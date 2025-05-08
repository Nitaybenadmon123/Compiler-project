#include "ast.h"

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_PARAMS 20  // מספר מקסימלי של פרמטרים


typedef enum {
    DT_INT, DT_REAL, DT_CHAR, DT_BOOL,
    DT_STRING, DT_VOID, DT_PTR_INT, DT_PTR_CHAR, DT_PTR_REAL
} DataType;

typedef enum { VAR_SYM, FUNC_SYM } SymbolKind;

typedef struct Symbol {
    char* name;
    SymbolKind kind;
    DataType type;
    struct Symbol* next;
    int param_count;
    DataType param_types[MAX_PARAMS];  // מערך של טיפוסי הפרמטרים

} Symbol;

typedef struct SymbolTable {
    Symbol* head;
} SymbolTable;

// Stack of symbol tables (scopes)
#define MAX_SCOPE_DEPTH 100
extern SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
extern int current_scope;

void enter_scope();
void exit_scope();
void insert_symbol(char* name, SymbolKind kind, DataType type);
Symbol* lookup_symbol(const char* name);
int symbol_exists_in_current_scope(const char* name);
Symbol* lookup_any_scope(const char* name);
DataType get_type_from_name(const char* type_str);
void print_scope_hierarchy();
void print_symbol_tables();
const char* get_name_from_type(DataType type);
void insert_checked_variable(const char* name, DataType type);
void insert_function_symbol(char* name, DataType type, int param_count);
int count_params(AST* args_node);

void insert_function_with_param_types(char* name, DataType type, int param_count, DataType* param_types);
void collect_param_types(AST* par_list, DataType* param_types);
void collect_call_param_types(AST* args_node, DataType* param_types);
void check_function_call_param_types(char* func_name, AST* args_node);
DataType get_expr_type(AST* expr);



#endif