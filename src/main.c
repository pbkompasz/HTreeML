#include "algo.h"
#include "cli.h"

struct control {
    char* parent_url;
    int lines_per_screen;
    int max_search_depth;
//  struct termios output_tty;
    off_t file_position;
    off_t file_size;
    int argv_position;    
};


int main(int argc, char *argv[]) {
    struct control cl;

	parse_args(argc, argv, &cl);
//	fetch_website("https://berkshirehathaway.com/");
//	fetch_website("https://berkshirehathaway.com/2021ProxyStmt.pdf");
//	print_help();
	return 0;
}
