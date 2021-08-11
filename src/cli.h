

static void __attribute__((__noreturn__)) usage(void); 
void print_help();
void print_error(char* error);
void print_result(char* result);

void parse_args(int argc, char *argv[], struct control *cl);
