#include "algo.h"
#include "cli.h"
#include "util.h"

int main(int argc, char *argv[]) {
    struct control cl = {
        .lines_per_screen = 1,
        .max_search_depth = 3,
        0 
    };


	argscan(argc, argv, &cl);

    printf("asd");

//	fetch_website("https://berkshirehathaway.com/");
//	fetch_website("https://berkshirehathaway.com/2021ProxyStmt.pdf");
//	usage();
	return 0;
}
