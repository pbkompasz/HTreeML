#include "algo.h"
#include <stdio.h>
#include <string.h>


void run() {
}

char fetch_website(char* url) {
		printf("hello");		


	CURL *curl;
	CURLcode res;
	printf("hello");		


	// Define custom headers
	struct curl_slist *chunk = NULL;

	char *user_agent = "user-agent: Mozilla/5.0 ";
	//chunk = curl_slist_append(chunk, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.182 Safari/537.36");
	chunk = curl_slist_append(chunk, user_agent);

	// Set custom headers
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
/*	printf("hello");		

	// set url
	curl_easy_setopt(curl, CURLOPT_URL, url);
	// make request
	res = curl_easy_perform(curl);
	// error
	if (res != CURLE_OK) {
		fprintf(stderr, "curl_easy_perform() failed %s\n", curl_easy_strerror(res)); 
	}
		printf("hello");		


	// curl general cleanup
	curl_easy_cleanup(curl);
	// free custom headers
	curl_slist_free_all(chunk);
*/	return 0;
}

char* fetch_websites_chunk(char* urls[]) {

}

struct website* parse_website(char* webpage) {
	
}

char* dfs_recursive(struct website* website, int max_depth) {
	
}

char* dfs_iterative(struct website* website, int max_depth); 

