#ifndef AST_H
#define AST_H

typedef struct ast_node {
    char* name;
    struct ast_node** children;
    int child_count;
} AST;
int count_function_params(AST* param_list);
int count_call_params(AST* args_list);
void check_function_call_params(char* func_name, AST* args_list);
#endif
