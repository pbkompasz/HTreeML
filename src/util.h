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

// Main program struct
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

// Check if it is a valid url
int check_url(char* url);

// Check if address points to external is address
int is_external(char *address);

// Scan for arguments
void argscan(int argc, char *argv[], struct control *cl);

char* fetch_website(char *);

char* fetch_websites_chunk(char* urls[]);

#endif
