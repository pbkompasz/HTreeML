#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

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
	int digit_optind = 0;
	
	static struct option long_options[] = {
		{"add",     required_argument, 0,  0 },
        	{"append",  no_argument,       0,  0 },
                {"delete",  required_argument, 0,  0 },
                {"verbose", no_argument,       0,  0 },
                {"create",  required_argument, 0, 'c'},
                {"file",    required_argument, 0,  0 },
                {0,         0,                 0,  0 }
	};
	
	while (1) {
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		char c = getopt_long(argc, argv, "abc", long_options, &option_index);
		if (c == -1) break;
		switch (c) {
			case 0:
                   		printf("option %s", long_options[option_index].name);
                   		if (optarg)
                       			printf(" with arg %s", optarg);
                   		printf("\n");
                   		break;
			case 'a':
                   		printf("option a\n");
                   		break;

			case 'b':
                   		printf("option b\n");
                   		break;

               		case 'c':
                   		printf("option c with value '%s'\n", optarg);
                   		break;
			default:
                   		printf("?? getopt returned character code 0%o ??\n", c);
               		
		}
	}
	if (optind < argc) {
               	printf("non-option ARGV-elements: ");
               	while (optind < argc)
			printf("%s ", argv[optind++]);
               	printf("\n");
     	}

       	exit(EXIT_SUCCESS);	
}
