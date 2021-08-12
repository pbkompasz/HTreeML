#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <regex.h>
#include <curl/curl.h>
#include "cli.h"

struct control {
    char *parent_url;           // the main url = domain
    int lines_per_screen;       // output
    int max_search_depth;       // search depth
//  struct termios output_tty;
    int argv_position;          // argv[] position   
    char **child_urls;          // list of child urls
    int num_urls;               // number of remaining urls
    int colourful;
    char *exclude_by_expression; 
    char *read_url_from_file;
    CURL *curl;
} control;

struct MemoryStruct {
	char *memory;
	size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

int check_url(char* url);

void argscan(int argc, char *argv[], struct control *cl);

#endif
