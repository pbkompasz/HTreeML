#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void print_help() {

	char *help_text = "\
	Usage: htreeml [OPTION...] [SECTION] ADDRESS...\n\
\
  -C, --config-file=FILE     use this user configuration file\n\
  -d, --debug                emit debugging messages\n\
  -D, --default              reset all options to their default values\n\
      --warnings[=WARNINGS]  enable warnings from groff\n\
\n\
 Main modes of operation:\n\
  -f, --whatis               equivalent to whatis\n\
  -k, --apropos              equivalent to apropos\n\
\n\
 Finding manual pages:\n\
  -L, --locale=LOCALE        define the locale for this particular man search\n\
  -m, --systems=SYSTEM       use manual pages from other systems\n\
                             foo-bar'\n\
\n\
 Controlling formatted output:\n\
  -P, --pager=PAGER          use program PAGER to display output\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n\
\n\
Report bugs to cjwatson@debian.org.";

	printf("%s", help_text);
}

void parse_args(int argc, char *argv[]) {
	int opt;
	enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode = CHARACTER_MODE;
	while ((opt = getopt(argc, argv, "lw")) != -1) {
		switch (opt) {
        	case 'l': printf("line mode"); break;
        	case 'w': printf("word mode"); break;
        	default:
            		fprintf(stderr, "Usage: %s [-ilw] [file...]\n", argv[0]);
            		exit(EXIT_FAILURE);
        	}
	}
	
}
