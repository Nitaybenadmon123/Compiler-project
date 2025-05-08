#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "ast.h"

SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
int current_scope = -1;
int max_scope = -1;
int preserve_symbol_tables = 0;  
void yyerror(const char* s);



void enter_scope() {
    current_scope++;
    if (current_scope > max_scope)
        max_scope = current_scope;

    symbol_stack[current_scope] = malloc(sizeof(SymbolTable));
    symbol_stack[current_scope]->head = NULL;
    printf("create new scope current_scope is: %d\n", current_scope);
}



void exit_scope() {
    /*if (!preserve_symbol_tables) {
        Symbol* s = symbol_stack[current_scope]->head;
        while (s) {
            Symbol* temp = s;
            s = s->next;
            free(temp->name);
            free(temp);
        }
        */
    current_scope--;
}


void insert_symbol(char* name, SymbolKind kind, DataType type) {
    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = kind;
    new_sym->type = type;
    new_sym->next = symbol_stack[current_scope]->head;
    symbol_stack[current_scope]->head = new_sym;
    

}


int symbol_exists_in_current_scope(const char* name) {
    Symbol* s = symbol_stack[current_scope]->head;
    while (s) {
        if (strcmp(s->name, name) == 0)
            return 1;
        s = s->next;
    }
    return 0;
}


Symbol* lookup_symbol(const char* name) {
    for (int i = current_scope; i >= 0; i--) {
        Symbol* s = symbol_stack[i]->head;
        while (s) {
            if (strcmp(s->name, name) == 0)
                return s;
            s = s->next;
        }
    }
    return NULL;
}


DataType get_type_from_name(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return DT_INT;
    if (strcmp(type_str, "real") == 0) return DT_REAL;
    if (strcmp(type_str, "char") == 0) return DT_CHAR;
    if (strcmp(type_str, "bool") == 0) return DT_BOOL;
    if (strcmp(type_str, "string") == 0) return DT_STRING;
    if (strcmp(type_str, "void") == 0) return DT_VOID;
    if (strcmp(type_str, "int*") == 0) return DT_PTR_INT;
    if (strcmp(type_str, "char*") == 0) return DT_PTR_CHAR;
    if (strcmp(type_str, "real*") == 0) return DT_PTR_REAL;
    return DT_INT; // ברירת מחדל
}
const char* get_name_from_type(DataType type) {
    switch (type) {
        case DT_INT: return "int";
        case DT_REAL: return "real";
        case DT_CHAR: return "char";
        case DT_BOOL: return "bool";
        case DT_STRING: return "string";
        case DT_VOID: return "void";
        case DT_PTR_INT: return "int*";
        case DT_PTR_CHAR: return "char*";
        case DT_PTR_REAL: return "real*";
        default: return "unknown";
    }
}


Symbol* lookup_any_scope(const char* name) {
    for (int i = current_scope; i >= 0; i--) {
        Symbol* s = symbol_stack[i]->head;
        while (s) {
            if (strcmp(s->name, name) == 0)
                return s;
            s = s->next;
        }
    }
    return NULL;
}

void print_scope_hierarchy() {
    printf("\n--- Scope Stack (top-down) ---\n");
    for (int i = current_scope; i >= 0; i--) {
        printf("Scope %d\n", i);
    }
    printf("------------------------------\n");
}
void print_symbol_tables() {
    printf("\n===== SYMBOL TABLES (with empty scopes) =====\n");
    for (int i = 0; i <= max_scope; i++) {
        printf("Scope %d:\n", i);
        Symbol* s = symbol_stack[i] ? symbol_stack[i]->head : NULL;
        if (!s) {
            printf("  (empty)\n");
            continue;
        }
        while (s) {
            const char* kind_str = (s->kind == FUNC_SYM) ? "Function" : "Variable";
            const char* type_str = get_name_from_type(s->type);
            printf("  Name: %-10s | Kind: %-8s | Type: %s\n", s->name, kind_str, type_str);
            s = s->next;
        }
    }
    printf("=======================================\n");
}
void insert_checked_variable(const char* name, DataType type) {
    if (symbol_exists_in_current_scope(name)) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Var '%s' already defined in this block", name);
        yyerror(error_msg);
    } else {
        insert_symbol((char*)name, VAR_SYM, type);
        printf("  Inserted '%s' as var in scope %d\n", name, current_scope);
    }
}
void insert_function_symbol(char* name, DataType type, int param_count) {
    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = FUNC_SYM;
    new_sym->type = type;
    new_sym->param_count = param_count;
    new_sym->next = symbol_stack[current_scope]->head;
    symbol_stack[current_scope]->head = new_sym;
    printf("  Inserted function '%s' with %d parameters in scope %d\n", 
           name, param_count, current_scope);
}

int count_params(AST* args_node) {
    if (!args_node || args_node->child_count == 0)
        return 0;

    AST* list = args_node->children[0];
    if (!list || strcmp(list->name, "NONE") == 0)
        return 0;

    int count = 0;
    if (strcmp(list->name, "") == 0) {
        for (int i = 0; i < list->child_count; i++) {
            if (list->children[i])
                count++;
        }
    } else {
        count = 1;
    }

    return count;
}

int count_actual_params(AST* args_node) {
    if (!args_node || strcmp(args_node->name, "args") != 0)
        return 0;

    AST* par_node = args_node->children[0];
    if (!par_node || strcmp(par_node->name, "none") == 0)
        return 0;

    int count = 0;
    AST* current = par_node;

    while (current && strcmp(current->name, "par") == 0) {
        if (current->child_count == 2) {
            count++;
            current = current->children[0];
        } else if (current->child_count == 1) {
            count++;
            break;
        } else {
            break;
        }
    }

    return count;
}

