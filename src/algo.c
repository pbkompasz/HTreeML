#include "algo.h"
#include <stdio.h>
#include <string.h>


void run() {
}

char fetch_website(char* url) {
	CURL *curl;
  	CURLcode res;
 
  	curl = curl_easy_init();
    int this;
  	if(curl) {
    	struct curl_slist *chunk = NULL;
 
    	chunk = curl_slist_append(chunk, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.182 Safari/537.36");
 
    	/* set our custom set of headers */
	    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

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
    return 0;
}

char* fetch_websites_chunk(char* urls[]) {

}

struct website* parse_website(char* webpage) {
	
}

char* dfs_recursive(struct website* website, int max_depth) {
	
}

char* dfs_iterative(struct website* website, int max_depth); 

