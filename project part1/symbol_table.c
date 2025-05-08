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
void collect_param_types(AST* par_list, DataType* param_types) {
    if (!par_list || strcmp(par_list->name, "ARGS") != 0 || par_list->child_count == 0)
        return;
    
    AST* param_list = par_list->children[0];
    if (!param_list || strcmp(param_list->name, "NONE") == 0)
        return;
    
    // המבנה: par_list -> param_list_item_list -> par_list_item
    // par_list_item: ID type COLON ID
    // בכל par_list_item, הטיפוס הוא במיקום 1 (הילד השני)
    
    int param_index = 0;
    collect_param_types_recursive(param_list, param_types, &param_index);
}

void collect_param_types_recursive(AST* node, DataType* param_types, int* index) {
    if (!node) return;
    
    // אם זה צומת par_list_item
    if (node->child_count >= 2) {
        // הילד השני הוא טיפוס
        AST* type_node = node->children[1];
        if (type_node) {
            param_types[(*index)++] = get_type_from_name(type_node->name);
        }
    }
    
    // רקורסיה לילדים אחרים, אם יש
    if (node->child_count > 0 && strcmp(node->name, "") == 0) {
        // רקורסיה לילד הראשון, אם זהו המשך רשימת פרמטרים
        collect_param_types_recursive(node->children[0], param_types, index);
    }
}

// פונקציה לקבלת טיפוס של ביטוי
DataType get_expr_type(AST* expr) {
    if (!expr)
        return DT_VOID;
    
    // אם אין ילדים, זהו ערך או משתנה
    if (expr->child_count == 0) {
        // מספרים
        if (isdigit(expr->name[0]) || (expr->name[0] == '-' && isdigit(expr->name[1])))
            return DT_INT;
        
        // תווים
        if (expr->name[0] == '\'')
            return DT_CHAR;
        
        // מחרוזות
        if (expr->name[0] == '"')
            return DT_STRING;
        
        // ערכים בוליאניים
        if (strcmp(expr->name, "true") == 0 || strcmp(expr->name, "false") == 0)
            return DT_BOOL;
        
        // מצביע ריק
        if (strcmp(expr->name, "nullptr") == 0)
            return DT_PTR_INT;  // או כל טיפוס מצביע אחר
        
        // משתנה
        Symbol* sym = lookup_any_scope(expr->name);
        if (sym)
            return sym->type;
        
        return DT_INT;  // ברירת מחדל
    }
    
    // ביטויים בינאריים
    if (expr->child_count == 2) {
        // ביטויים אריתמטיים
        if (strcmp(expr->name, "+") == 0 || strcmp(expr->name, "-") == 0 ||
            strcmp(expr->name, "*") == 0 || strcmp(expr->name, "/") == 0) {
            DataType type1 = get_expr_type(expr->children[0]);
            DataType type2 = get_expr_type(expr->children[1]);
            
            // כללים פשוטים: real עדיף על int
            if (type1 == DT_REAL || type2 == DT_REAL)
                return DT_REAL;
            return DT_INT;
        }
        
        // ביטויי השוואה
        if (strcmp(expr->name, "==") == 0 || strcmp(expr->name, "!=") == 0 ||
            strcmp(expr->name, "<") == 0 || strcmp(expr->name, ">") == 0 ||
            strcmp(expr->name, "<=") == 0 || strcmp(expr->name, ">=") == 0) {
            return DT_BOOL;
        }
    }
    
    // קריאות לפונקציות
    if (strcmp(expr->name, "call") == 0 && expr->child_count >= 1) {
        Symbol* func = lookup_any_scope(expr->children[0]->name);
        if (func && func->kind == FUNC_SYM)
            return func->type;
    }
    
    return DT_INT;  // ברירת מחדל
}

// פונקציה לבדיקת התאמת טיפוסי פרמטרים
void check_param_types(char* func_name, AST* args_node) {
    Symbol* func = lookup_any_scope(func_name);
    if (!func || func->kind != FUNC_SYM)
        return;
    
    int param_count = func->param_count;
    if (param_count == 0)
        return;
    
    // בדיקת הפרמטרים
    DataType actual_types[MAX_PARAMS];
    memset(actual_types, 0, sizeof(actual_types));
    
    get_call_param_types(args_node, actual_types);
    
    for (int i = 0; i < param_count; i++) {
        if (actual_types[i] != func->param_types[i]) {
            // אפשר להוסיף כאן המרות אוטומטיות מסוימות (למשל int ל-real)
            // לדוגמה:
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
    
    // לולאה על פרמטרים ורקורסיה
    int index = 0;
    get_call_param_types_recursive(param_node, types, &index);
}

void get_call_param_types_recursive(AST* node, DataType* types, int* index) {
    if (!node) return;
    
    if (strcmp(node->name, "par") == 0) {
        if (node->child_count >= 1) {
            // אם יש ילד אחד, זה הפרמטר הראשון והיחיד
            if (node->child_count == 1) {
                types[(*index)++] = get_expr_type(node->children[0]);
            }
            // אם יש שני ילדים, הראשון הוא המשך הרשימה והשני הוא הפרמטר הנוכחי
            else if (node->child_count == 2) {
                get_call_param_types_recursive(node->children[0], types, index);
                types[(*index)++] = get_expr_type(node->children[1]);
            }
        }
    }
    // אם node הוא ביטוי ולא "par", זה פרמטר יחיד
    else {
        types[(*index)++] = get_expr_type(node);
    }
}
