#include "util.h"

int check_url(char* url) {
    regex_t regex;
    int reti;
    char msgbuf[100];
    
    reti = regcomp(&regex, "^([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);   
    }
    reti = regexec(&regex, url, 0, NULL, 0);
    return reti;    
}

// Check if name is a route or external link (e.g. contains .pdf, http)
int is_external(char *name) {
    char *key_words[] = {"pdf", "http", "https", "www."}; 
    size_t key_words_length = 3;
    int i;
    for(i = 0; i < key_words_length; i++) {
        if (strstr(name, key_words[i])) {
            return 1;    
        }
    }
    return 0;
}

void argscan(int argc, char *argv[], struct control *cl) {
	int opt;
	int digit_optind = 0;

	static struct option long_options[] = {
        {"colourful",  no_argument, 0, 'c'},
        {"depth",  required_argument, 0,  'd' },
        {"exclude",  required_argument, 0, 'e' },
        {"file",    required_argument, 0,  'f' },
        {"help",  no_argument,       0,  'h' },
        {"version", no_argument,       0,  'v' },
        {0,         0,                 0,  0 }
	};
	
	while (1) {
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		char c = getopt_long(argc, argv, "cd:e:f:hv", long_options, &option_index);
		if (c == -1) break;
		switch (c) {
			
            case 0:
                printf("option %s", long_options[option_index].name);
                if (optarg)
                   printf(" with arg %s", optarg);
                printf("\n");
                break;

                        case 'c':
                cl->colourful = 1;
                break;
            
            case 'd':
                if (atoi(optarg) < 1 || atoi(optarg) > 9) {
                    fprintf(stderr, "Depth must be a number between 1 and 9");
                    exit(1);
                }
                cl->max_search_depth = atoi(optarg);
                break;
            
            case 'e':
                cl->exclude_by_expression = optarg;
                break;
            
            case 'f':
                cl->read_url_from_file = optarg;
                break;
            
            case 'h':
                usage();
                break;

            case 'v':
                printf("Version 0.1");
                exit(EXIT_SUCCESS); 
                break;
			default:
                printf("?? getopt returned character code 0%o ??\n", c);
    		    break;
            }
	}

    
	if (optind < argc) {
        printf("non-option ARGV-elements: ");
        cl->parent_url = argv[optind];
        while (optind < argc)
	        printf("%s ", argv[optind++]);
        printf("\n");
    } else {
             
    }


}

struct string {
    char *ptr;
    size_t len;
};


void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;
    
    return size*nmemb;
}

char *fetch_website(char* url) {
	CURL *curl;
  	CURLcode res;
    
    //printf("Fetching site for urL: %s\n", url);
    
    struct string s;
    init_string(&s);

  	curl = curl_easy_init();
    int this;
  	if(curl) {
    	struct curl_slist *chunk = NULL;
 
    	chunk = curl_slist_append(chunk, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.182 Safari/537.36");
 
    	/* set our custom set of headers */
	    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);

       res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
 
                /* always cleanup */
        curl_easy_cleanup(curl);
 
        /* free the custom headers */
        /* free the custom headers */
        curl_slist_free_all(chunk);
    }

    return s.ptr;
}

char* fetch_websites_chunk(char* urls[]) {
   
}




