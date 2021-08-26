#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"


#define MAX_PARALLEL 10

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
    int no_children;
	// External links
	char** step_children;
    int no_step_children;
} website;


void tree();

