#include "algo.h"



void run() {
}

static void add_transfer(CURLM *cm, int i) {
	CURL *eh = curl_easy_init();
	curl_easy_setopt(eh, CURLOPT_WRITEFUNCTION, write_cb);
	curl_easy_setopt(eh, CURLOPT_URL, urls[i]);
	curl_easy_setopt(eh, CURLOPT_PRIVATE, urls[i]);
	curl_multi_add_handle(cm, eh);
}

char* fetch_websites(char* urls[]) {
	// Number of urls to fetch
	int num_urls = sizeof(urls) / sizeof(char *);

	CURLM *cm;
	CURLMsg *msg;
	unsigned int transfers = 0;
	int msgs_left = -1;
	int still_alive = 1;

	curl_global_init(CURL_GLOBAL_ALL);
	cm = curl_multi_init();

	// max connections limit
	curl_multi_setopt(cm, CURLMOP_MAXCONNECTS, (long)MAX_PARALLEL);

	for (transfers = 0; transfers < MAX_PARALLEL, transfers++) {
		add_transfers(cm, transfers);
	}

	do {

	} while (still_alive || (transfers < NUM_URLS))

	

	return 0;
}

struct website* parse_website(char* webpage) {
	
}


