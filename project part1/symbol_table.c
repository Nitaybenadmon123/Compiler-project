#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table.h"
#include "ast.h"

SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
int current_scope = -1;
int max_scope = -1;
int preserve_symbol_tables = 0;  

// הכרזה על פונקציה שמוגדרת בקוד אחר
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
    new_sym->param_count = 0; // ברירת מחדל
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

void insert_function_with_param_types(char* name, DataType type, int param_count, DataType* param_types) {
    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = FUNC_SYM;
    new_sym->type = type;
    new_sym->param_count = param_count;
    
    // העתקת טיפוסי הפרמטרים
    for (int i = 0; i < param_count && i < MAX_PARAMS; i++) {
        new_sym->param_types[i] = param_types[i];
    }
    
    new_sym->next = symbol_stack[current_scope]->head;
    symbol_stack[current_scope]->head = new_sym;
    
    printf("  Inserted function '%s' with %d parameters in scope %d\n", 
           name, param_count, current_scope);
    
    // הדפסת טיפוסי הפרמטרים
    if (param_count > 0) {
        printf("  Parameter types: ");
        for (int i = 0; i < param_count; i++) {
            printf("%s", get_name_from_type(param_types[i]));
            if (i < param_count - 1) printf(", ");
        }
        printf("\n");
    }
}

// פונקציה לאיסוף טיפוסי פרמטרים מהגדרת פונקציה
// This function should be corrected to properly parse the parameters from the AST
void collect_param_types(AST* par_list, DataType* param_types) {
    if (!par_list || strcmp(par_list->name, "ARGS") != 0 || par_list->child_count == 0)
        return;
    
    AST* param_list = par_list->children[0];
    if (!param_list || strcmp(param_list->name, "NONE") == 0)
        return;
    
    int param_index = 0;
    
    // Your code might be treating the parameters in incorrect order
    for (int i = 0; i < param_list->child_count; i++) {
        AST* param_item = param_list->children[i];
        if (param_item && param_item->child_count >= 2) {
            // Extract the type node (should be at index 1)
            AST* type_node = param_item->children[1];
            if (type_node) {
                param_types[param_index++] = get_type_from_name(type_node->name);
                // Add debug print
                printf("DEBUG: Collected parameter type %s at index %d\n", 
                       type_node->name, param_index-1);
            }
        }
    }
}

// פונקציית עזר לאיסוף טיפוסי פרמטרים ברקורסיה
void collect_params_recursive(AST* node, DataType* param_types, int* index) {
    if (!node || node->child_count < 2)
        return;

    // אם הצומת הוא המשך רשימה
    if (strcmp(node->name, "") == 0 && node->child_count >= 2) {
        // קודם מטפלים בפרמטר הנוכחי
        if (node->children[1] && node->children[1]->child_count >= 2) {
            DataType type = get_type_from_name(node->children[1]->children[1]->name);
            param_types[(*index)++] = type;
            printf("DEBUG: Collected parameter type %s at index %d\n", 
                  get_name_from_type(type), *index - 1);
        }
        
        // אחר כך מטפלים בשאר הרשימה
        if (node->children[0]) {
            collect_params_recursive(node->children[0], param_types, index);
        }
    } else if (node->child_count == 3) {
        // אם זה פרמטר ישיר (למשל הפרמטר האחרון)
        DataType type = get_type_from_name(node->children[1]->name);
        param_types[(*index)++] = type;
        printf("DEBUG: Collected parameter type %s at index %d\n", 
              get_name_from_type(type), *index - 1);
    }
}

// פונקציה לקבלת טיפוס של ביטוי

DataType get_expr_type(AST* expr) {
    if (!expr)
        return DT_VOID;
    
    // Check for array access (string indexing)
    if (expr->name && strcmp(expr->name, "array_access") == 0) {
        return DT_CHAR;  // Accessing a string element always returns a char
    }
    
    // If it's a character literal (starts with single quote)
    if (expr->name && expr->name[0] == '\'')
        return DT_CHAR;
    
    // If it's a string literal (starts with double quote)
    if (expr->name && expr->name[0] == '"')
        return DT_STRING;
    
    // If it's a number
    if (expr->name && (isdigit(expr->name[0]) || (expr->name[0] == '-' && isdigit(expr->name[1]))))
        return DT_INT;
    
    // If it's a boolean literal
    if (expr->name && (strcmp(expr->name, "true") == 0 || strcmp(expr->name, "false") == 0))
        return DT_BOOL;
    
    // If it's a NULL pointer
    if (expr->name && strcmp(expr->name, "nullptr") == 0)
        return DT_PTR_INT; // or any pointer type
    
    // Boolean operations
    if (expr->name) {
        if (strcmp(expr->name, "and") == 0 ||
            strcmp(expr->name, "or") == 0 ||
            strcmp(expr->name, "not") == 0)
            return DT_BOOL;
        
        // Comparison operations
        if (strcmp(expr->name, "==") == 0 ||
            strcmp(expr->name, "!=") == 0 ||
            strcmp(expr->name, "<") == 0 ||
            strcmp(expr->name, ">") == 0 ||
            strcmp(expr->name, "<=") == 0 ||
            strcmp(expr->name, ">=") == 0)
            return DT_BOOL;
    }
    
    // If it's a variable, look it up in the symbol table
    if (expr->name) {
        Symbol* sym = lookup_any_scope(expr->name);
        if (sym)
            return sym->type;
    }
    
    // If it has children, determine type based on operation
    if (expr->child_count > 0) {
        // Handle operations that return boolean results
        if (expr->name) {
            if (strcmp(expr->name, "and") == 0 ||
                strcmp(expr->name, "or") == 0 ||
                strcmp(expr->name, "not") == 0 ||
                strcmp(expr->name, "==") == 0 ||
                strcmp(expr->name, "!=") == 0 ||
                strcmp(expr->name, "<") == 0 ||
                strcmp(expr->name, ">") == 0 ||
                strcmp(expr->name, "<=") == 0 ||
                strcmp(expr->name, ">=") == 0)
                return DT_BOOL;
        }
        
        // For arithmetic operations, determine type based on operands
        if (expr->name && (strcmp(expr->name, "+") == 0 ||
                          strcmp(expr->name, "-") == 0 ||
                          strcmp(expr->name, "*") == 0 ||
                          strcmp(expr->name, "/") == 0)) {
            DataType left = get_expr_type(expr->children[0]);
            DataType right = expr->child_count > 1 ? get_expr_type(expr->children[1]) : DT_VOID;
            
            // If either operand is real, result is real
            if (left == DT_REAL || right == DT_REAL)
                return DT_REAL;
            
            // Otherwise if both are int, result is int
            if (left == DT_INT && right == DT_INT)
                return DT_INT;
        }
    }
    
    // Default to INT if we can't determine the type
    return DT_INT;
}
// פונקציה לבדיקת התאמת טיפוסי פרמטרים
void check_param_types(char* func_name, AST* args_node) {
    Symbol* func = lookup_any_scope(func_name);
    if (!func || func->kind != FUNC_SYM)
        return;
    
    int param_count = func->param_count;
    if (param_count == 0)
        return;
    
    // Get actual parameter types
    DataType actual_types[MAX_PARAMS];
    memset(actual_types, 0, sizeof(actual_types));
    
    printf("DEBUG: Checking params for function '%s', expects %d params\n", func_name, param_count);
for (int i = 0; i < param_count; i++) {
    printf("DEBUG: Formal param %d: %s\n", i+1, get_name_from_type(func->param_types[i]));
}

get_call_param_types(args_node, actual_types);

printf("DEBUG: Found %d actual params\n", count_actual_params(args_node));
for (int i = 0; i < param_count; i++) {
    printf("DEBUG: Actual param %d: %s\n", i+1, get_name_from_type(actual_types[i]));
}    
    for (int i = 0; i < param_count; i++) {
        if (actual_types[i] != func->param_types[i]) {
            // Allow certain implicit conversions (e.g., int to real)
            if (!(func->param_types[i] == DT_REAL && actual_types[i] == DT_INT)) {
                char msg[200];
                sprintf(msg, "Semantic Error: Parameter %d of function '%s' expects type %s, got %s",
                        i+1, func_name, get_name_from_type(func->param_types[i]), 
                        get_name_from_type(actual_types[i]));
                yyerror(msg);
            }
        }
    }
}
// איסוף טיפוסי פרמטרים מקריאה לפונקציה
void get_call_param_types(AST* args_node, DataType* types) {
    if (!args_node || strcmp(args_node->name, "args") != 0 || args_node->child_count == 0)
        return;
    
    AST* param_node = args_node->children[0];
    if (!param_node || strcmp(param_node->name, "none") == 0)
        return;
    
    // Initialize index
    int index = 0;
    
    // Debug the AST structure
    printf("DEBUG: Analyzing call args structure: %s with %d children\n", 
           param_node->name, param_node->child_count);
           
    // Call recursive function to gather parameter types
    get_call_param_types_recursive(param_node, types, &index);
}
// פונקציית עזר לאיסוף טיפוסי פרמטרים מקריאה לפונקציה
void get_call_param_types_recursive(AST* node, DataType* types, int* index) {
    if (!node) return;
    
    printf("DEBUG: Processing node '%s' with %d children for parameter type extraction\n", 
           node->name, node->child_count);
    
    if (strcmp(node->name, "par") == 0) {
        if (node->child_count == 1) {
            // Single parameter
            types[(*index)++] = get_expr_type(node->children[0]);
            printf("DEBUG: Extracted single parameter of type %s\n", 
                   get_name_from_type(types[(*index)-1]));
        } 
        else if (node->child_count == 2) {
            // Two children - typically (rest_of_params, current_param)
            // Process the rest of the parameters first (recursively)
            get_call_param_types_recursive(node->children[0], types, index);
            
            // Then process the current parameter
            types[(*index)++] = get_expr_type(node->children[1]);
            printf("DEBUG: Extracted parameter of type %s\n", 
                   get_name_from_type(types[(*index)-1]));
        }
    } 
    else {
        // Direct expression node
        types[(*index)++] = get_expr_type(node);
        printf("DEBUG: Extracted direct parameter of type %s\n", 
               get_name_from_type(types[(*index)-1]));
    }
}
void check_boolean_condition(AST* expr, const char* construct_name) {
    if (expr) {
        DataType type = get_expr_type(expr);
        if (type != DT_BOOL) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Condition in '%s' statement must be of boolean type, got %s", 
                    construct_name, get_name_from_type(type));
            yyerror(error_msg);
        }
    }
}
// Add to symbols_table.c
void check_return_type(AST* expr, const char* func_name) {
    Symbol* func = lookup_any_scope(func_name);
    if (!func || func->kind != FUNC_SYM) {
        printf("DEBUG: Could not find function '%s' for return type check\n", func_name);
        return;
    }
    
    // Check for void return
    if (expr && strcmp(expr->name, "NONE") == 0) {
        if (func->type != DT_VOID) {
            char msg[200];
            sprintf(msg, "Semantic Error: Function '%s' must return a value of type %s", 
                    func_name, get_name_from_type(func->type));
            yyerror(msg);
        }
        return;
    }
    
    // If function returns void but has a return value
    if (func->type == DT_VOID && expr && strcmp(expr->name, "NONE") != 0) {
        char msg[200];
        sprintf(msg, "Semantic Error: Function '%s' has void return type but returns a value", 
                func_name);
        yyerror(msg);
        return;
    }
    
    // Get return expression type
    DataType expr_type = get_expr_type(expr);
    printf("DEBUG: Function '%s' returns type %s, expression has type %s\n", 
            func_name, get_name_from_type(func->type), get_name_from_type(expr_type));
    
    // Check type match (allowing int to real conversion)
    if (expr_type != func->type) {
        // Allow int to real conversion
        if (!(func->type == DT_REAL && expr_type == DT_INT)) {
            char msg[200];
            sprintf(msg, "Semantic Error: Function '%s' returns type %s but return statement has type %s", 
                    func_name, get_name_from_type(func->type), get_name_from_type(expr_type));
            yyerror(msg);
        }
    }
}
// Add to symbol_table.c
void check_string_index(AST* index_expr) {
    if (index_expr) {
        DataType type = get_expr_type(index_expr);
        if (type != DT_INT) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String index must be of integer type, got %s", 
                    get_name_from_type(type));
            yyerror(error_msg);
        }
    }
}
int is_type_compatible(DataType lhs, DataType rhs) {
    // Same type is always compatible
    if (lhs == rhs)
        return 1;
    
    // Integer can be assigned to real (implicit conversion)
    if (lhs == DT_REAL && rhs == DT_INT)
        return 1;
    
    // Add other allowed conversions here if needed
    
    // All other combinations are incompatible
    return 0;
}