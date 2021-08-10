#include <stdio.h>
#include <curl/curl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PARALLEL 10

struct website {
	// Website address
	char* address;
	// 0 - root of website /
	// 1 - /vehicle
	// 2 - /vehicle/1
	int level;
	// HTML of website
	char* data;
	// Internal links 
	char* children;
	// External links
	char* step_children;
};

// Return raw HTML of a website
// url - address of website
char fetch_website(char* url);

// Return array of raw HTML
// urls - array of addresses of websites
char* fetch_websites_chunk(char* urls[]);


// Parse a website
// Return a pointer to a website struct
// webpage - raw HTML of website
struct website* parse_website(char* webpage);

// Perform recursive DFS on a website
// website - parsed website as input
// max_depth - how deep to perform search
char* dfs_recursive(struct website* website, int max_depth);

char* dfs_iterative(struct website* website, int max_depth); 

void* bfs_recursive(struct website* website, int max_depth);

void* bfs_iterative(struct website* website, int max_depth);

void run();

