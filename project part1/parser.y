%{
    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"

    AST* make_node(char* name, int count, ...);
    void print_ast(AST* node, int indent);
    void yyerror(const char* s);
    void print_symbol_tables();
    int yylex();
    int yydebug = 1;
    int inside_main = 0;
    int scope_parent[100] = {-1};  
    int function_scopes[100] = {0}; 
    int current_function = 0; 
    int main_defined = 0;  
    extern int preserve_symbol_tables;
    // Add to your globals in parser.y
    char current_function_name[256] = "";
%}

%union {
    struct ast_node* ast ;
    char* sval;
}

%start program
%left OR
%left AND
%left PLUS MINUS
%left MULT DIV
%left EQ NE GT GE LT LE
%right NOT

%token <sval> ID CHAR_LITERAL STRING_LITERAL NUM TRUE FALSE
%token <sval> TYPE_INT TYPE_CHAR TYPE_REAL TYPE_BOOL TYPE_STRING TYPE_INT_PTR TYPE_CHAR_PTR TYPE_REAL_PTR

%token DEF T_BEGIN T_END IF ELSE ELIF WHILE FOR DO CALL RETURN RETURNS VAR NULLPTR ASSIGN ADDRESS
//%token AND OR NOT

//%token EQ NE GT GE LT LE ASSIGN
//%token PLUS MINUS MULT DIV ADDRESS

%token COLON SEMICOLON COMMA LPAREN RPAREN LBRACK RBRACK BAR TYPE

%type <ast> program function func_list par_list par_list_item param_list_item_list elif_list call_list type_decls type_decl update_expr
%type <ast> type stmt_list stmt assignment expr if_stmt block return_stmt while_stmt for_stmt   do_while_stmt var_stmt call_args void_call assignment_call
%%

program:
    func_list {
        print_ast($1, 0);
    }
  | error {
        yyerror("Could not parse input");
    }
;

func_list:
    func_list function { $$ = make_node("CODE", 2, $1, $2); }
  | function { $$ = make_node("CODE", 1, $1); }
;
function:
    DEF ID LPAREN par_list RPAREN COLON RETURNS type {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params($4);
            collect_param_types($4, param_types);
            insert_function_with_param_types($2, get_type_from_name($8->name), param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", $2, current_scope, param_count);
        }
        // In each function declaration rule
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");

            if (get_type_from_name($8->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        // Add this check in the function declaration rule actions
        if (get_type_from_name($8->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
    } stmt_list {
        inside_main = 0;
        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, $8),
             make_node("BODY", 1, $10));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }

  | DEF ID LPAREN RPAREN COLON RETURNS type {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  // במקרה זה, אין פרמטרים
            insert_function_with_param_types($2, get_type_from_name($7->name), 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", $2, current_scope);
        }
        // In each function declaration rule
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if (get_type_from_name($7->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name($7->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
    } stmt_list {
        inside_main = 0;
        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, $7),
             make_node("BODY", 1, $9));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }

  | DEF ID LPAREN par_list RPAREN COLON {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params($4);
            collect_param_types($4, param_types);
            insert_function_with_param_types($2, DT_VOID, param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", $2, current_scope, param_count);
        }
        // In each function declaration rule
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");
        }
    } stmt_list {
        inside_main = 0;
        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $8));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }

  | DEF ID LPAREN RPAREN COLON {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  // במקרה זה, אין פרמטרים
            insert_function_with_param_types($2, DT_VOID, 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", $2, current_scope);
        }
        // In each function declaration rule
    strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;
        }
    } stmt_list {
        inside_main = 0;
        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $7));

             // At the end of each function rule, after creating the AST node
        current_function_name[0] = '\0';  // Clear the current function name
    }
;

par_list:
    param_list_item_list { $$ = make_node("ARGS", 1, $1); }
  | /* empty */ { $$ = make_node("ARGS", 1, make_node("NONE", 0)); }
;

param_list_item_list:
    param_list_item_list SEMICOLON par_list_item {
        $$ = make_node("", 2, $1, $3);
    }
  | par_list_item {
        $$ = $1;
    }
;


par_list_item:
    ID type COLON ID {
        // טיפוס הפרמטר הוא get_type_from_name($2->name)
        insert_symbol($4, VAR_SYM, get_type_from_name($2->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", $4, current_scope);
        
        $$ = make_node("", 3, make_node($1, 0), make_node($2->name, 0), make_node($4, 0));
    }
;

type:
    TYPE_INT   { $$ = make_node($1, 0); }
  | TYPE_CHAR  { $$ = make_node($1, 0); }
  | TYPE_REAL  { $$ = make_node($1, 0); }
  | TYPE_BOOL  { $$ = make_node($1, 0); }
  | TYPE_STRING { $$ = make_node($1, 0); }
  | TYPE_INT_PTR { $$ = make_node($1, 0); }
  | TYPE_CHAR_PTR { $$ = make_node($1, 0); }
  | TYPE_REAL_PTR { $$ = make_node($1, 0); }
;

stmt_list:
    stmt_list stmt { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        $$ = make_node("", 2, $1, $2); 
    }
    | stmt { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        $$ = $1; 
    }
;

stmt:
    assignment
  | if_stmt
  | return_stmt
|block
  | while_stmt 
  | for_stmt 
  | call_args 
  |do_while_stmt
  |var_stmt 
  |void_call
|assignment_call
|func_list
;

assignment:
   ID ASSIGN expr SEMICOLON {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else {
            // Check type compatibility
            DataType lhs_type = sym->type;
            DataType rhs_type = get_expr_type($3);
            
            // Check if null is assigned to a non-pointer type
            if (rhs_type == DT_PTR_INT && $3->name && strcmp($3->name, "nullptr") == 0) {
                if (lhs_type != DT_PTR_INT && lhs_type != DT_PTR_CHAR && lhs_type != DT_PTR_REAL) {
                    char error_msg[100];
                    sprintf(error_msg, "Semantic Error: Cannot assign null to non-pointer type %s", 
                            get_name_from_type(lhs_type));
                    yyerror(error_msg);
                }
            }
            // Check general type compatibility
            else if (!is_type_compatible(lhs_type, rhs_type)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment, cannot assign %s to %s", 
                        get_name_from_type(rhs_type), get_name_from_type(lhs_type));
                yyerror(error_msg);
            }
        }
        $$ = make_node("=", 2, make_node($1, 0), $3);
    }
    | ID LBRACK expr RBRACK ASSIGN expr SEMICOLON {
        // Check that the variable is a string
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    $1, get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            // Check that the index is an integer
            check_string_index($3);
            
            // Check that the assigned value is a char
            DataType rhs_type = get_expr_type($6);
            if (rhs_type != DT_CHAR) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: String element can only be assigned a char value, got %s", 
                        get_name_from_type(rhs_type));
                yyerror(error_msg);
            }
        }
        $$ = make_node("=", 2, make_node("array_access", 2, make_node($1, 0), $3), $6);
    }
;
var_stmt:
    VAR type_decls block {
        $$ = make_node("VAR", 2, $2, $3);
    }
  | VAR type_decls stmt {
        $$ = make_node("VAR", 2, $2, $3);
    }
;
type_decls:
    type_decls type_decl {
        $$ = make_node("DECLS", 2, $1, $2);
    }
  | type_decl {
        $$ = $1;
    }
;
type_decl:
    TYPE TYPE_INT COLON ID SEMICOLON {
        insert_checked_variable($4, DT_INT);
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 0));
    }
  | TYPE TYPE_BOOL COLON ID SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 0));
    }
  | TYPE TYPE_CHAR COLON ID SEMICOLON {
        insert_checked_variable($4, DT_CHAR);
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 0));
    }
  | TYPE TYPE_STRING COLON ID SEMICOLON {
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 2, make_node("string", 0), make_node($4, 0));
    }
  | TYPE TYPE_REAL COLON ID SEMICOLON {
        insert_checked_variable($4, DT_REAL);
        $$ = make_node("TYPE", 2, make_node("real", 0), make_node($4, 0));
    }
    | TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON {
        insert_checked_variable($4, DT_REAL);
        $$ = make_node("TYPE", 2, make_node("real", 0), make_node($4, 1,make_node($6,0)));
    }
  | TYPE TYPE_INT COLON ID COLON NUM SEMICOLON {
        insert_checked_variable($4, DT_INT);
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON {
        insert_checked_variable($4, DT_CHAR);
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON {
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 2, make_node("string", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 1, make_node("true", 0)));
    }
  | TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 1, make_node("false", 0)));
    }
   | TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON {
        int size = atoi($6);
        if (size <= 0) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String size must be a positive integer");
            yyerror(error_msg);
        }
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 3, make_node("string", 0), make_node($4, 0), make_node($6, 0));
    }
;

// In return_stmt rule
return_stmt:
    RETURN expr SEMICOLON {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);
        if (inside_main) {
            yyerror("Semantic Error: _main_ function cannot return a value");
        }
        
        // Check if return type matches function declaration
        check_return_type($2, current_function_name);
        
        $$ = make_node("RETURN", 1, $2);
    }
  | RETURN SEMICOLON {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        // Empty return is equivalent to "return void"
        check_return_type(make_node("NONE", 0), current_function_name);
        
        $$ = make_node("RETURN", 1, make_node("NONE", 0));
    }
;

if_stmt:
    IF expr COLON block ELSE COLON block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELSE", 3, $2, $4, $7);
    }
  | IF expr COLON block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF", 2, $2, $4);
    }
  | IF expr COLON stmt
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF", 2, $2, $4);
    }
  | IF expr COLON stmt ELSE COLON stmt
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELSE", 3, $2, $4, $7);
    }
  | IF expr COLON block elif_list ELSE COLON block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELIF-ELSE", 4, $2, $4, $5, $8);
    }
;

// And similarly for the elif_list rule
elif_list: 
    ELIF expr COLON block
    {
        check_boolean_condition($2, "elif");
        $$ = make_node("ELIF", 2, $2, $4);
    }
    | elif_list ELIF expr COLON block
    {
        check_boolean_condition($3, "elif");
        $$ = make_node("ELIF - ...", 3, $1, make_node("elif", 2, $3, $5));
    }
;
while_stmt:
    WHILE COLON expr SEMICOLON
    {
        check_boolean_condition($3, "while");
        $$ = make_node("while", 1, $3);
    }
    | WHILE expr COLON block
    {
        check_boolean_condition($2, "while");
        $$ = make_node("while2", 2, $2, $4);
    }
    | WHILE expr COLON stmt
    {
        check_boolean_condition($2, "while");
        $$ = make_node("while2", 2, $2, $4);
    }
;
do_while_stmt:
    DO COLON stmt_list WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
    |
    DO COLON stmt WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
    |
    DO COLON block WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
;

for_stmt:
    FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block {
        check_boolean_condition($4, "for"); // Check the loop condition expression is boolean
        $$ = make_node("for", 4, $3, $4, $6, $9);
    }
    |
    FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt {
        check_boolean_condition($4, "for"); // Check the loop condition expression is boolean
        $$ = make_node("for", 4, $3, $4, $6, $9);
    }
;

update_expr:
    ID ASSIGN expr {
        $$ = make_node("=", 2, make_node($1, 0), $3);
    }
    | expr {
        $$ = $1;
    }
;
call_args:
    call_list { $$ = make_node("args", 1, $1); }
  | /* empty */ { $$ = make_node("args", 1, make_node("none", 0)); }
;

call_list:
    call_list COMMA expr
    {
        $$= make_node ("par",2,$1,$3);
    }
    | expr
    {
          $$= make_node ("par",1,$1);
    }

;

assignment_call:
    ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON {
        Symbol* func = lookup_any_scope($4);
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", $4);
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", $4);
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params($6);
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", $4, expected, actual);
                yyerror(msg);
            } else {
                // בדיקת טיפוסי פרמטרים
                check_param_types($4, $6);
            }
        }

        $$ = make_node("ASSIGN-CALL", 2,
                       make_node($1, 0),
                       make_node("CALL", 2, make_node($4, 0), $6));
    }
;

void_call:
    CALL ID LPAREN call_args RPAREN SEMICOLON {
        Symbol* func = lookup_any_scope($2);
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", $2);
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", $2);
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params($4);
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", $2, expected, actual);
                yyerror(msg);
            } else {
                // בדיקת טיפוסי פרמטרים
                check_param_types($2, $4);
            }
        }

        $$ = make_node("CALL", 2, make_node($2, 0), $4);
    }
;

block:
    T_BEGIN {
        enter_scope();
    }
    stmt_list T_END {
        $$ = make_node("BLOCK", 1, $3); 
        exit_scope();
    }
    |    T_BEGIN {
        enter_scope();
    }
     T_END {
        $$ = make_node("BLOCK", 0); 
        exit_scope();
     }
;

expr:
    expr PLUS expr { $$ = make_node("+", 2, $1, $3); }
    | expr MINUS expr { $$ = make_node("-", 2, $1, $3); }
    | expr MULT expr { $$ = make_node("*", 2, $1, $3); }
    | expr DIV expr { $$ = make_node("/", 2, $1, $3); }
    | expr EQ expr { $$ = make_node("==", 2, $1, $3); }
    | expr NE expr { $$ = make_node("!=", 2, $1, $3); }
    | expr LT expr { $$ = make_node("<", 2, $1, $3); }
    | expr GT expr { $$ = make_node(">", 2, $1, $3); }
    | expr LE expr { $$ = make_node("<=", 2, $1, $3); }
    | expr GE expr { $$ = make_node(">=", 2, $1, $3); }
    | LPAREN expr RPAREN { $$ = $2; }
    
    // New rule for array access
    | ID LBRACK expr RBRACK {
        // Check that the variable is a string
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    $1, get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            // Check that the index is an integer
            check_string_index($3);
        }
        $$ = make_node("array_access", 2, make_node($1, 0), $3);
    }

    // Remove or modify this rule
    | LBRACK expr RBRACK {
        // This rule should not be used for array access
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        $$ = $2; // Fallback to avoid further errors
    }
    
    | NUM { $$ = make_node($1, 0); }
    | ID {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        }
        $$ = make_node($1, 0);
    }
    | CHAR_LITERAL { $$ = make_node($1, 0); }
    | STRING_LITERAL { $$ = make_node($1, 0); }
    | NULLPTR { $$ = make_node("nullptr", 0); }
    | TRUE { $$ = make_node("true", 0); }
    | FALSE { $$ = make_node("false", 0); }
    | AND { $$ = make_node("and", 0); }
    | OR { $$ = make_node("or", 0); }
    | NOT { $$ = make_node("not", 0); }
    | CALL ID LPAREN call_args RPAREN {
        Symbol* func = lookup_any_scope($2);
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params($4);
            if (expected == actual) {
                // בדיקת טיפוסי פרמטרים
                check_param_types($2, $4);
            }
        }
        $$ = make_node("call", 2, make_node($2, 0), $4);
    }
    | ID LPAREN call_args RPAREN {
        Symbol* func = lookup_any_scope($1);
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params($3);
            if (expected == actual) {
                // בדיקת טיפוסי פרמטרים
                check_param_types($1, $3);
            }
        }
        $$ = make_node("call", 2, make_node($1, 0), $3);
    }
    | expr AND expr { $$ = make_node("and", 2, $1, $3); }
    | expr OR expr { $$ = make_node("or", 2, $1, $3); }
    | NOT expr { $$ = make_node("not", 1, $2); }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main(int argc, char* argv[]) {
    printf("DEBUG: Starting compiler\n");

    enter_scope();
    int result = yyparse();

    printf("\nDEBUG: Final symbol tables:\n");
    print_symbol_tables();
    preserve_symbol_tables = 1;
    exit_scope();

    if (!main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    return result;
}
