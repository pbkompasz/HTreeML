#include <stdio.h>
#include "cli.h"
#include "util.h"

void __attribute__((__noreturn__)) usage(void) {
    printf("%s", "USAGE_HEADER");
    printf( " %s [options] <file>...\n", "program_invocation_short_name");

    printf("%s", "USAGE_SEPARATOR");
    printf("%s\n", "A usage explanation.");

    printf("%s", "USAGE_HEADER");
    printf("%s", "USAGE_HEADER");

    printf("%s", "USAGE_OPTIONS");
	printf("%s\n", " -d, --silent          display help instead of ringing bell");
	printf("%s\n", " -f, --logical         count logical rather than screen lines");
	printf("%s\n", " -l, --no-pause        suppress pause after form feed");
	printf("%s\n", " -c, --print-over      do not scroll, display text and clean line ends");
	printf("%s\n", " -p, --clean-print     do not scroll, clean screen and display text");
	printf("%s\n", " -s, --squeeze         squeeze multiple blank lines into one");
	printf("%s\n", " -u, --plain           suppress underlining and bold");
	printf("%s\n", " -n, --lines <number>  the number of lines per screenful");
	printf("%s\n", " -<number>             same as --lines");
	printf("%s\n", " +<number>             display file beginning from line number");
	printf("%s\n", " +/<pattern>           display file beginning from pattern match");
	printf("%s", "USAGE_SEPARATOR");
//	printf(USAGE_HELP_OPTIONS(23));
//	printf(USAGE_MAN_TAIL("more(1)"));
	exit(EXIT_SUCCESS);
}


