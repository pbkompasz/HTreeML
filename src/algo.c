#include "algo.h"

void get_website_children(char*, char***, size_t*, char***, size_t*);
struct website *parse_website(struct control*, char*, int);

void tree(struct control *cl) {
    printf("%s", cl->parent_url);
    struct website *result = parse_website(cl, "", 0);
    printf("%i\n", result->no_children); 
} 

void get_website_children(char* webpage, char*** children, size_t *no_children, char*** step_children, size_t *no_step_children) {
    const char* pattern = "href=\"";
    const long int webpage_length = strlen(webpage);

    int i = 0, j = 0;
    *no_children = 0;
    *no_step_children = 0;
    //children = malloc(1 * sizeof(char*));
    for (i = 0; i < webpage_length; i++) {
        for (j = 0; j < 6; j++) {
            if ( webpage[i + j] != pattern[j] || i + j > webpage_length) {
                break;
            }
            if (j == 5) {
                int k = 1;
                while ( k < webpage_length && webpage[i + j + k + 1] != '\"') {
                    //printf("%c", webpage[k]);
                    k++;
                } 
                char *word;
                word = (char*)calloc(k, sizeof(char*));
                memcpy(word, webpage + i + j + 1, k);        
                if (is_external(word)) {
                    (*step_children) = realloc(*step_children, (*no_step_children + 1) * sizeof(char*));
//                    printf("external %s\n", word);
                    (*step_children)[(*no_step_children)] = (char*)calloc(k, sizeof(char*));

                    if ((*step_children)[(*no_step_children)] == NULL) {
                        fprintf(stderr, "malloc() failed\n");
                        exit(EXIT_FAILURE);
                    }
                    memcpy( (*step_children)[(*no_step_children)], webpage + i + j + 1, k);
                    (*no_step_children)++;

                } else {
                    (*children) = realloc(*children, (*no_children + 1) * sizeof(char*));
                    (*children)[(*no_children)] = (char*)calloc(k, sizeof(char*));
  //                  printf("internal %s\n", word);

                    if ((*children)[(*no_children)] == NULL) {
                        fprintf(stderr, "malloc() failed\n");
                        exit(EXIT_FAILURE);
                    }
                    memcpy( (*children)[(*no_children)], webpage + i + j + 1, k);
                    (*no_children)++;
                } 
                
            }
        }
    }

}



struct website* parse_website(struct control *cl, char *name, int level) {
    if (level > cl->max_search_depth) {
        return NULL;
    }
    struct website *parsed = (struct website*)malloc(1 * sizeof(struct website));	
    char **children = malloc(1 * sizeof(char*)), 
        **step_children = malloc(1 * sizeof(char*));
    size_t no_children = 0, no_step_children = 0;
    
    
    parsed->no_children = no_children;
    parsed->no_step_children = no_step_children;
    parsed->level = level;
    parsed->address = (char*)calloc((sizeof(cl->parent_url) + sizeof(name)), sizeof(char*));
    strcat(strcat(strcat(parsed->address, cl->parent_url), "/"), name);
    parsed->data = fetch_website(parsed->address);
    get_website_children(parsed->data, &children, &no_children, &step_children, &no_step_children);
    parsed->children = (struct website*)malloc(no_children * sizeof(struct website*));    
    parsed->step_children = (char**)malloc(no_step_children * sizeof(char**));    
    
    int i;
    for(i = 0;i < level; i++) printf(" ");
    if (level > 0) {
        printf("|_");
    }
    printf("%s\n", name);
    
    for(i = 0; i < no_children; i++) {
        parse_website(cl, children[i],  level+1);
    } 
    for(i = 0; i < no_step_children; i++) {
        parsed->step_children[i] = step_children[i];
    }

    // Cleanup
    for(i = 0; i < no_children; i++) {
        free(children[i]);
    }
    for(i = 0; i < no_step_children; i++) {
//        if (level > 0) {
 //           printf("|");
  //      }
   //     for(i = 0;i < level; i++) printf("-");
    //    printf("%s\n", parsed.step_children[i]);
        free(step_children[i]);
    }

    free(children); 
    free(step_children);
//    return NULL; 
    return (parsed); 
}

char* dfs_recursive(struct website* website, int max_depth) {
	
}

char* dfs_iterative(struct website* website, int max_depth) { 
}
