#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
int current_scope = -1;

void enter_scope() {
    current_scope++;
    symbol_stack[current_scope] = malloc(sizeof(SymbolTable));
    symbol_stack[current_scope]->head = NULL;
}

void exit_scope() {
    Symbol* s = symbol_stack[current_scope]->head;
    while (s) {
        Symbol* temp = s;
        s = s->next;
        free(temp->name);
        free(temp);
    }
    free(symbol_stack[current_scope]);
    symbol_stack[current_scope] = NULL;
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
