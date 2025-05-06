%{
    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"

    AST* make_node(char* name, int count, ...);
    void print_ast(AST* node, int indent);
    void yyerror(const char* s);
    void check_main_function();
    void print_symbol_tables();
    int yylex();
    int yydebug = 1;
    extern char* current_function_name;
    int inside_main = 0;
    int scope_parent[100] = {-1};  // Track parent-child scope relationships
    int function_scopes[100] = {0}; // Track which function a scope belongs to
    int current_function = 0; 
    int main_defined = 0;      // Current function ID
    


%}

%union {
    struct ast_node* ast ;
    char* sval;
}

%start program
%left PLUS MINUS
%left MULT DIV
%left EQ NE GT GE LT LE

%token <sval> ID CHAR_LITERAL STRING_LITERAL NUM
%token <sval> TYPE_INT TYPE_CHAR TYPE_REAL TYPE_BOOL TYPE_STRING TYPE_INT_PTR TYPE_CHAR_PTR TYPE_REAL_PTR

%token DEF T_BEGIN T_END IF ELSE ELIF WHILE FOR DO CALL RETURN RETURNS VAR NULLPTR
%token TRUE FALSE AND OR NOT

%token EQ NE GT GE LT LE ASSIGN
%token PLUS MINUS MULT DIV ADDRESS

%token COLON SEMICOLON COMMA LPAREN RPAREN LBRACK RBRACK BAR TYPE

%type <ast> program function func_list par_list par_list_item param_list_item_list elif_list call_list type_decls type_decl
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
    DEF ID LPAREN par_list RPAREN COLON RETURNS type stmt_list {
        printf(">> DEF FUNC: '%s' with params and return, scope=%d\n", $2, current_scope);
        if (strcmp($2, "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
    DataType return_type = get_type_from_name($8->name);
    if (return_type != DT_VOID) {
        yyerror("Semantic Error: _main_ function cannot return a value");
    }
}
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            insert_symbol($2, FUNC_SYM, get_type_from_name($8->name));
            printf("  Inserted '%s' as function in scope %d\n", $2, current_scope);
        }

        enter_scope();  // פתח scope חדש לגוף הפונקציה
        exit_scope();
            inside_main = 0;

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, $8),
             make_node("BODY", 1, $9));
    }

  | DEF ID LPAREN RPAREN COLON RETURNS type stmt_list{
        printf(">> DEF FUNC: '%s' no params, with return, scope=%d\n", $2, current_scope);
            if (strcmp($2, "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ($7->child_count > 0 && strcmp($7->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
    DataType return_type = get_type_from_name($7->name);
    if (return_type != DT_VOID) {
        yyerror("Semantic Error: _main_ function cannot return a value");
    }
}
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            insert_symbol($2, FUNC_SYM, get_type_from_name($7->name));
            printf("  Inserted '%s' as function in scope %d\n", $2, current_scope);
        }

        enter_scope();
        exit_scope();
            inside_main = 0;

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, $7),
             make_node("BODY", 1, $8));
    }
    
    

  | DEF ID LPAREN par_list RPAREN COLON stmt_list {
        printf(">> DEF FUNC: '%s' with params, no return, scope=%d\n", $2, current_scope);
            if (strcmp($2, "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
}
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            insert_symbol($2, FUNC_SYM, DT_VOID);
            printf("  Inserted '%s' as function in scope %d\n", $2, current_scope);
        }

        enter_scope();
         exit_scope();
        inside_main = 0;

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $7));
    }
    
    

  | DEF ID LPAREN RPAREN COLON stmt_list {
        printf(">> DEF FUNC: '%s' no params, no return, scope=%d\n", $2, current_scope);
        if (strcmp($2, "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;
    
}
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            insert_symbol($2, FUNC_SYM, DT_VOID);
            printf("  Inserted '%s' as function in scope %d\n", $2, current_scope);
        }
        enter_scope();
        exit_scope();
        inside_main = 0;
        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $6));

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
| func_list { 
        printf("DEBUG: Processing function in stmt, current_scope = %d\n", current_scope);
        $$ = $1; 
    }
;

assignment:
    ID ASSIGN expr SEMICOLON {
        if (symbol_exists_in_current_scope($1)) {
            char err[100];
            sprintf(err, "Semantic Error: Variable '%s' redefined in the same block", $1);
            yyerror(err);
        } else {
            insert_symbol($1, VAR_SYM, DT_INT);  // או הטיפוס שאתה מחלץ לפי ה־var
        }

        $$ = make_node("=", 2, make_node($1, 0), $3);
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
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 0));
    }
  | TYPE TYPE_CHAR COLON ID SEMICOLON {
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 0));
    }
  | TYPE TYPE_STRING COLON ID SEMICOLON {
        $$ = make_node("TYPE", 2, make_node("string", 0), make_node($4, 0));
    }
   | TYPE TYPE_INT COLON ID COLON NUM SEMICOLON {
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 1,make_node($6,0)));
    }
     | TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON {
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 0));
    }
  // וכן הלאה...
;



return_stmt:
    RETURN expr SEMICOLON {
        printf("DEBUG: Processing return with value. inside_main=%d\n", inside_main);
        if (inside_main) {
            yyerror("Semantic Error: _main_ function cannot return a value");
        }
        $$ = make_node("RETURN", 1, $2);
    }
  | RETURN SEMICOLON {
        printf("DEBUG: Processing empty return. inside_main=%d\n", inside_main);
        $$ = make_node("RETURN", 1, make_node("NONE", 0));
    }
;

if_stmt:
    IF expr COLON block ELSE COLON block
    {
        $$ = make_node("IF-ELSE", 3, $2, $4, $7);
    }
  | IF expr COLON block
    {
        $$ = make_node("IF", 2, $2, $4);
    }
    | IF expr COLON stmt
    {
         $$ =make_node("IF",2,$2,$4);
    }
       | IF expr COLON stmt ELSE COLON stmt
    {
         $$ =make_node("IF-ELSE",3,$2,$4,$7);
    }
     | IF expr COLON block elif_list ELSE COLON block
{
    $$ = make_node("IF-ELIF-ELSE", 4, $2, $4, $5, $8);
}

    
;
elif_list: 
    ELIF expr COLON block
	{
        $$=make_node("ELIF",2,$2,$4);
    }
    |elif_list ELIF expr COLON block
    {
        $$=make_node("ELIF - ...",3,$1,make_node("elif",2,$3,$5));
    }
;
while_stmt:
    WHILE COLON expr SEMICOLON
    {
        $$=make_node("while",1,$3);
    }
    |WHILE  expr COLON block
    {
        $$= make_node("while2",2,$2,$4);
    }
    |WHILE  expr COLON stmt
    {
        $$= make_node("while2",2,$2,$4);
    }
;
do_while_stmt:
    DO COLON block while_stmt
    {
        $$=make_node("do", 1,$3,make_node("do while",1,$4));
    }
;

for_stmt:
    FOR LPAREN assignment expr SEMICOLON expr RPAREN COLON stmt
    {
        $$=make_node("for", 4,$3,$4,$6,$9);
    }
    |FOR LPAREN assignment expr SEMICOLON expr RPAREN COLON block
    {
        $$=make_node("for", 4,$3,$4,$6,$9);
    }

;

call_args:
    call_list {$$=$1;}
  | /*empty*/  {$$ =make_node("args", 1 ,make_node("none",0));}
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
        $$ = make_node("ASSIGN-CALL", 2,
                       make_node($1, 0),
                       make_node("CALL", 2, make_node($4, 0), $6));
    }
;

void_call:
    CALL ID LPAREN call_args RPAREN SEMICOLON {
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
    expr PLUS expr   { $$ = make_node("+", 2, $1, $3); }
  | expr MINUS expr  { $$ = make_node("-", 2, $1, $3); }
  | expr MULT expr   { $$ = make_node("*", 2, $1, $3); }
  | expr DIV expr    { $$ = make_node("/", 2, $1, $3); }
  | expr EQ expr     { $$ = make_node("==", 2, $1, $3); }
  | expr NE expr     { $$ = make_node("!=", 2, $1, $3); }
  | expr LT expr     { $$ = make_node("<", 2, $1, $3); }
  | expr GT expr     { $$ = make_node(">", 2, $1, $3); }
  | expr LE expr     { $$ = make_node("<=", 2, $1, $3); }
  | expr GE expr     { $$ = make_node(">=", 2, $1, $3); }
  | LPAREN expr RPAREN { $$ = $2; }
 | LBRACK expr RBRACK {$$=$2;}
  | NUM             { $$ = make_node($1, 0); }
  | ID              { $$ = make_node($1, 0); }
  | CHAR_LITERAL      { $$ = make_node($1, 0); }
  |STRING_LITERAL    { $$ = make_node($1, 0); }
  |NULLPTR { $$ = make_node("nullptr", 0); }
  |TRUE { $$ = make_node("true", 0); }
  |FALSE { $$ = make_node("false", 0); }
  |AND { $$ = make_node("and", 0); }
  |OR { $$ = make_node("or", 0); }
  |NOT { $$ = make_node("not", 0); }
  |CALL ID LPAREN call_args RPAREN { $$ = make_node("call", 2,make_node($2,0),$4); }
  | ID LPAREN call_args RPAREN { $$ = make_node("call", 2, make_node($1, 0), $3); } 
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
void check_main_function() {
    Symbol* main_func = lookup_any_scope("_main_");
    
   /* if (!main_func) {
        yyerror("Semantic Error: _main_ function must be defined");
        return;
    }
    
    if (main_func->kind != FUNC_SYM) {
        yyerror("Semantic Error: _main_ is not a function");
        return;
    }
    
    // Check if _main_ has a non-void return type
    if (main_func->type != DT_VOID) {
        yyerror("Semantic Error: _main_ function cannot return a value");
    }
    */
    // We would also need to check for parameters, but this requires
    // enhancing the Symbol struct to track parameters
}

void print_symbol_tables() {
    printf("\n===== SYMBOL TABLES (scope stack) =====\n");
    for (int i = 0; i <= current_scope; i++) {
        printf("Scope %d:\n", i);
        Symbol* s = symbol_stack[i]->head;
        if (!s) {
            printf("  (empty)\n");
        }
        while (s) {
            const char* kind_str = (s->kind == FUNC_SYM) ? "Function" : "Variable";
            const char* type_str = "";  // תוכל לשפר אם תבנה מתרגם הפוך ל־DataType
            switch (s->type) {
                case DT_INT: type_str = "int"; break;
                case DT_REAL: type_str = "real"; break;
                case DT_CHAR: type_str = "char"; break;
                case DT_BOOL: type_str = "bool"; break;
                case DT_STRING: type_str = "string"; break;
                case DT_VOID: type_str = "void"; break;
                case DT_PTR_INT: type_str = "int*"; break;
                case DT_PTR_CHAR: type_str = "char*"; break;
                case DT_PTR_REAL: type_str = "real*"; break;
                default: type_str = "unknown";
            }

            printf("  Name: %-10s | Kind: %-8s | Type: %s\n", s->name, kind_str, type_str);
            s = s->next;
        }
    }
    printf("=======================================\n");
}


int main() {
    printf("DEBUG: Starting compiler\n");
    enter_scope();
    int result = yyparse();

    printf("\nDEBUG: Final symbol tables:\n");
    print_symbol_tables();
   // check_main_function();

   exit_scope();
   if (!main_defined) {
    yyerror("Semantic Error: No _main_ function defined");
}

    return result;
}
