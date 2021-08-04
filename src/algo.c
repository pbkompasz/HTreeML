#include "algo.h"

void run() {
	printf("run asd");
	CURL *curl;
  	CURLcode res;
 
  	curl = curl_easy_init();
}

char* fetch_website(char* url) {
	CURL *curl;
  	CURLcode res;
 
  	curl = curl_easy_init();
  	if(curl) {
    		curl_easy_setopt(curl, CURLOPT_URL, url);
    		res = curl_easy_perform(curl);
 
    		if(CURLE_OK == res) {
      			char *ct;
      			/* ask for the content-type */
      			res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
 
      			if((CURLE_OK == res) && ct)
        			printf("We received Content-Type: %s\n", ct);
    		}
 
    		/* always cleanup */
    		curl_easy_cleanup(curl);
  	}
	return 0;
}
