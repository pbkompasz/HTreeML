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

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *) userp;

	char *ptr = realloc(mem->memory, mem->size + realsize + 1);
	if (ptr == NULL) {
		printf("ERROR: Not enough memory!\n");
		return 0;
	}
	
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
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
