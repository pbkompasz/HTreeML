#include "algo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"

struct string {
    char *ptr;
    size_t len;
};

void run(struct control *cl) {
    char *result = fetch_website(cl->parent_url);
    free(result); 
    parse_website(result);
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
    
    printf("Fetching site");
    
    struct string s;
    init_string(&s);

  	curl = curl_easy_init();
    int this;
        printf("%i", 1+1);
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

struct website* parse_website(char* webpage) {
    struct website parsed;
    	
}

char* dfs_recursive(struct website* website, int max_depth) {
	
}

char* dfs_iterative(struct website* website, int max_depth) { 
}
