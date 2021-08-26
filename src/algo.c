#include "algo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"

typedef struct website {
	// Website address
	char* address;
	// 0 - root of website /
	// 1 - /vehicle
	// 2 - /vehicle/1
	int level;
	// HTML of website
	char* data;
	// Internal links 
	struct website* children;
	// External links
	char* step_children;
} website;


struct string {
    char *ptr;
    size_t len;
};

void get_website_children(char*, char***, size_t*, char***, size_t*);
char* fetch_website(char *);

void run(struct control *cl) {
    char *result = fetch_website(cl->parent_url);
    //parse_website(result);
    char **children = malloc(1 * sizeof(char*)), 
         **step_children = malloc(1 * sizeof(char*));
    size_t no_children = 0, no_step_children = 0;
    get_website_children(result, &children, &no_children, &step_children, &no_step_children);
    int i;
    for(i = 0; i < no_children; i++) {
        free(children[i]);
    }
    for(i = 0; i < no_step_children; i++) {
       free(step_children[i]);
    }

    free(children); 
    free(step_children); 
} 

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
    
    printf("Fetching site\n");
    
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
        curl_slist_free_all(chunk);
    }

    return s.ptr;
}

char* fetch_websites_chunk(char* urls[]) {
   
}

void doit(char*** strs) {
    (*strs)[0] = "asd";
    (*strs) = realloc(*strs, 2 * sizeof(char*));
    
    char* text = "asdfdas";
    (*strs)[1] = (char*)calloc(5, sizeof(char*));
    memcpy( (*strs)[1], text + 1, 5);
    //(*strs)[1] = "asdfdasfds";
}

void get_website_children(char* webpage, char*** children, size_t *no_children, char*** step_children, size_t *no_step_children) {
    const char* pattern = "a href=\"";
    const long int webpage_length = strlen(webpage);

    int i = 0, j = 0;
    *no_children = 0;
    *no_step_children = 0;
    //children = malloc(1 * sizeof(char*));
    for (i = 0; i < webpage_length; i++) {
        for (j = 0; j < 8; j++) {
            if ( webpage[i + j] != pattern[j] || i + j > webpage_length) {
                break;
            }
            if (j == 7) {
                int k = 1;
                while ( k < webpage_length && webpage[i + j + k + 1] != '\"') {
                    //printf("%c", webpage[k]);
                    k++;
                } 
/*                printf("%i", k);*
                char *word = (char*)malloc(k * sizeof(char*));
                memcpy(word, webpage + i + j + 1, k);        
                if (is_external(word)) {
                    (*step_children) = realloc(*step_children, (*no_step_children + 1) * sizeof(char*));
                    (*step_children)[(*no_step_children)] = (char*)calloc(k, sizeof(char*));

                    if ((*step_children)[(*no_step_children)] == NULL) {
                        fprintf(stderr, "malloc() failed\n");
                        exit(EXIT_FAILURE);
                    }
                    memcpy( (*step_children)[(*no_step_children)], webpage + i + j + 1, k);
                    (*no_step_children)++;

                } else {
                    (*children) = realloc(*children, (*no_children + 1) * sizeof(char*));
                    (*children)[(*no_children)] = (char*)calloc(k, sizeof(char*));

                    if ((*children)[(*no_children)] == NULL) {
                        fprintf(stderr, "malloc() failed\n");
                        exit(EXIT_FAILURE);
                    }
                    memcpy( (*children)[(*no_children)], webpage + i + j + 1, k);
                    (*no_children)++;
                } */
                
            }
        }
    }

}

// Check if name is a route or external link (e.g. contains .pdf, http)
int is_external(char *name) {
    return 1; 

    char *key_words[] = {"pdf", "http"}; 
    size_t key_words_length = 2;
    int i;
    for(i = 0; i < key_words_length; i++) {
        if (strstr(name, key_words[i])) {
            return i;    
        }
    }
    return 0;
}

struct website* parse_website(char* webpage) {
    struct website parsed;
    	
}

char* dfs_recursive(struct website* website, int max_depth) {
	
}

char* dfs_iterative(struct website* website, int max_depth) { 
}
