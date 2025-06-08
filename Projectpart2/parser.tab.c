/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"
#include "three_address_code.h"
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
    char current_function_name[256] = "";
    int current_param_index = 0;
    AST* program_ast = NULL;

#line 95 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OR = 3,                         /* OR  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_MULT = 7,                       /* MULT  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NE = 10,                        /* NE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_CHAR_LITERAL = 17,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 18,            /* STRING_LITERAL  */
  YYSYMBOL_NUM = 19,                       /* NUM  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_TYPE_INT = 22,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_CHAR = 23,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_REAL = 24,                 /* TYPE_REAL  */
  YYSYMBOL_TYPE_BOOL = 25,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 26,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_INT_PTR = 27,              /* TYPE_INT_PTR  */
  YYSYMBOL_TYPE_CHAR_PTR = 28,             /* TYPE_CHAR_PTR  */
  YYSYMBOL_TYPE_REAL_PTR = 29,             /* TYPE_REAL_PTR  */
  YYSYMBOL_DEF = 30,                       /* DEF  */
  YYSYMBOL_T_BEGIN = 31,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 32,                     /* T_END  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_ELIF = 35,                      /* ELIF  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_CALL = 39,                      /* CALL  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_RETURNS = 41,                   /* RETURNS  */
  YYSYMBOL_VAR = 42,                       /* VAR  */
  YYSYMBOL_NULLPTR = 43,                   /* NULLPTR  */
  YYSYMBOL_ASSIGN = 44,                    /* ASSIGN  */
  YYSYMBOL_ADDRESS = 45,                   /* ADDRESS  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_LPAREN = 49,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 50,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 51,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 52,                    /* RBRACK  */
  YYSYMBOL_BAR = 53,                       /* BAR  */
  YYSYMBOL_TYPE = 54,                      /* TYPE  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_func_list = 57,                 /* func_list  */
  YYSYMBOL_function_body = 58,             /* function_body  */
  YYSYMBOL_nested_func_list = 59,          /* nested_func_list  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_par_list = 65,                  /* par_list  */
  YYSYMBOL_param_list_item_list = 66,      /* param_list_item_list  */
  YYSYMBOL_par_list_item = 67,             /* par_list_item  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_stmt_list = 69,                 /* stmt_list  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_assignment = 71,                /* assignment  */
  YYSYMBOL_id_list = 72,                   /* id_list  */
  YYSYMBOL_var_stmt = 73,                  /* var_stmt  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_block_content = 76,             /* block_content  */
  YYSYMBOL_type_decls = 77,                /* type_decls  */
  YYSYMBOL_type_decl = 78,                 /* type_decl  */
  YYSYMBOL_id_value_list = 79,             /* id_value_list  */
  YYSYMBOL_literal = 80,                   /* literal  */
  YYSYMBOL_return_stmt = 81,               /* return_stmt  */
  YYSYMBOL_if_stmt = 82,                   /* if_stmt  */
  YYSYMBOL_elif_list = 83,                 /* elif_list  */
  YYSYMBOL_while_stmt = 84,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 85,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 86,                  /* for_stmt  */
  YYSYMBOL_update_expr = 87,               /* update_expr  */
  YYSYMBOL_call_args = 88,                 /* call_args  */
  YYSYMBOL_call_list = 89,                 /* call_list  */
  YYSYMBOL_assignment_call = 90,           /* assignment_call  */
  YYSYMBOL_void_call = 91,                 /* void_call  */
  YYSYMBOL_block = 92,                     /* block  */
  YYSYMBOL_nested_block = 93,              /* nested_block  */
  YYSYMBOL_94_7 = 94,                      /* $@7  */
  YYSYMBOL_95_8 = 95,                      /* $@8  */
  YYSYMBOL_expr = 96                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  359

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    60,    66,    67,    70,    71,    72,    73,
      76,    81,    82,    85,    85,   132,   132,   173,   173,   214,
     214,   252,   253,   257,   260,   267,   282,   283,   284,   285,
     286,   287,   288,   289,   293,   297,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   319,   346,
     370,   399,   406,   407,   412,   412,   418,   418,   428,   433,
     440,   443,   448,   452,   456,   460,   464,   468,   472,   476,
     480,   484,   488,   492,   502,   506,   510,   515,   519,   523,
     527,   531,   535,   539,   543,   556,   560,   564,   568,   572,
     579,   582,   589,   590,   591,   592,   593,   598,   606,   616,
     621,   626,   631,   636,   644,   649,   656,   661,   666,   673,
     678,   683,   690,   695,   702,   705,   710,   711,   715,   719,
     727,   756,   783,   786,   791,   791,   799,   799,   810,   821,
     832,   843,   854,   865,   876,   887,   898,   909,   920,   922,
     939,   946,   947,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   975,  1003,  1004,  1005,  1007,  1039,  1062
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OR", "AND", "PLUS",
  "MINUS", "MULT", "DIV", "EQ", "NE", "GT", "GE", "LT", "LE", "NOT", "ID",
  "CHAR_LITERAL", "STRING_LITERAL", "NUM", "TRUE", "FALSE", "TYPE_INT",
  "TYPE_CHAR", "TYPE_REAL", "TYPE_BOOL", "TYPE_STRING", "TYPE_INT_PTR",
  "TYPE_CHAR_PTR", "TYPE_REAL_PTR", "DEF", "T_BEGIN", "T_END", "IF",
  "ELSE", "ELIF", "WHILE", "FOR", "DO", "CALL", "RETURN", "RETURNS", "VAR",
  "NULLPTR", "ASSIGN", "ADDRESS", "COLON", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACK", "RBRACK", "BAR", "TYPE", "$accept", "program",
  "func_list", "function_body", "nested_func_list", "function", "$@1",
  "$@2", "$@3", "$@4", "par_list", "param_list_item_list", "par_list_item",
  "type", "stmt_list", "stmt", "assignment", "id_list", "var_stmt", "$@5",
  "$@6", "block_content", "type_decls", "type_decl", "id_value_list",
  "literal", "return_stmt", "if_stmt", "elif_list", "while_stmt",
  "do_while_stmt", "for_stmt", "update_expr", "call_args", "call_list",
  "assignment_call", "void_call", "block", "nested_block", "$@7", "$@8",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-295)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -295,     9,    38,    19,  -295,    16,  -295,  -295,    -3,
     217,    27,    41,    49,  -295,  -295,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,    68,    64,    84,   124,   133,   217,    -9,
     111,  -295,  -295,  -295,   310,   102,  -295,   217,    -9,    -9,
    -295,  -295,   889,   208,   -20,  -295,  -295,  -295,  -295,  -295,
     353,  -295,   932,   833,   181,   119,   205,   882,  -295,  -295,
     218,   932,   932,   740,  -295,   396,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,   152,  -295,  -295,  -295,  1279,
     940,   -14,  -295,  -295,  -295,  -295,   932,    15,   221,   240,
     123,    59,  -295,   939,   932,   932,  -295,  -295,   439,  1208,
     932,  1223,     0,   740,   209,  -295,  1049,   102,   102,   -23,
    1001,   170,  -295,   482,  -295,  -295,   932,   932,   932,   932,
     932,   932,   932,   932,   932,   932,   932,   932,   932,   171,
     214,   245,   264,     2,   266,   270,   278,   525,  -295,    -9,
     932,   932,   295,   300,   299,  1061,   304,   183,  -295,   783,
    1076,   740,   342,    43,   351,   932,   826,   346,   352,   932,
    -295,    -8,   108,   932,   932,  -295,  -295,  -295,  1279,  1093,
     906,   325,   325,   123,   123,  -295,  -295,  -295,  -295,  -295,
    -295,   371,   378,   381,   385,  -295,   394,    52,   402,   403,
     404,  -295,   568,  -295,  1106,   259,   932,   372,  -295,  -295,
     379,   353,   390,   120,  -295,  -295,  -295,   386,   932,   932,
     387,  1121,   833,   932,   932,   375,   611,  -295,  -295,  1133,
     271,    96,   113,   116,   122,   151,   155,   158,   160,   162,
     166,   168,   172,   -12,   184,   406,   418,   393,   201,   397,
     207,   401,   246,  -295,  -295,  -295,   399,   932,   932,   740,
     419,   407,   415,   932,   274,   293,   982,  1031,  1151,  1178,
     405,  -295,   654,  -295,  -295,    99,  -295,  -295,  -295,   434,
     269,  -295,  -295,  -295,   301,  -295,  -295,  -295,   345,  -295,
    -295,  -295,   358,  -295,   443,  -295,  -295,   411,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,   414,  1196,   697,  -295,   740,
     435,  1252,   421,   932,   379,    53,   423,  1279,  -295,  -295,
    -295,  -295,  -295,  -295,  -295,   427,  -295,  -295,  -295,   422,
     433,  -295,   436,   440,   444,   445,   413,   446,   447,  -295,
    -295,  -295,  -295,  -295,   464,   435,  1267,   932,   450,  -295,
     388,  -295,  -295,  -295,  -295,  -295,   457,  -295,  -295,  -295,
    -295,   464,  1279,   740,  -295,  -295,  -295,  -295,  -295
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     5,     0,     1,     4,     0,
       0,     0,     0,    21,    24,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    19,     0,     0,     0,     0,     0,
      17,    23,    25,    15,     0,     0,    20,     0,     0,     0,
     149,   148,     0,   150,   142,   143,   144,   141,   146,   147,
       0,     8,     0,     0,     0,     0,     0,     0,    54,   145,
       0,     0,     0,   117,    12,     0,    35,    36,    44,    38,
      37,    40,    43,    41,    42,   116,    46,    45,    39,   119,
       0,     0,    61,    13,    18,    16,     0,   142,     0,     0,
     156,   142,   155,     0,   117,     0,   123,    47,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,   157,
       0,     0,    11,     0,     6,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,   157,     0,     0,     0,     0,   122,   117,
       0,   117,     0,     0,     0,     0,     0,    35,    39,   117,
      97,     0,   117,     0,     0,   138,   140,     7,   118,   154,
     153,   128,   129,   130,   131,   132,   133,   135,   137,   134,
     136,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,    10,     0,    14,     0,     0,   117,     0,    48,   152,
     139,     0,   101,   100,   106,   108,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    57,     0,
       0,    52,     0,     0,    52,     0,     0,    52,     0,     0,
      52,     0,     0,     0,     0,     0,     0,    52,     0,    52,
       0,    52,     0,     9,    50,   139,     0,   117,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,    59,     0,    51,   158,     0,    62,    77,    86,     0,
       0,    64,    79,    87,     0,    66,    80,    89,     0,    63,
      78,    85,     0,    65,     0,    88,    53,     0,    74,    81,
      75,    82,    76,    83,   151,     0,     0,     0,   127,   117,
       0,     0,     0,     0,     0,   142,     0,   115,   109,   110,
     111,   121,    58,    95,    96,    92,    93,    94,    90,     0,
      95,    92,    92,    93,    94,    96,     0,     0,   151,    49,
     125,   102,   124,    99,     0,     0,     0,     0,     0,    68,
       0,    69,    67,    71,    72,    70,     0,    84,   120,   104,
     103,     0,   114,   117,    91,    73,   105,   113,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -295,  -295,  -295,   -30,  -295,    26,  -295,  -295,  -295,  -295,
    -295,  -295,   479,    -1,   -31,   -61,   408,  -127,  -295,  -295,
    -295,  -295,   273,   -69,  -115,   167,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,   -89,  -295,  -295,  -295,  -101,  -294,  -295,
    -295,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    36,    63,    97,   139,    39,    38,    29,
      12,    13,    14,    23,    98,    66,    67,   187,    68,   107,
     108,   217,    81,    82,   223,   318,    69,    70,   254,    71,
      72,    73,   306,    74,    75,    76,    77,    78,   203,   249,
     250,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    92,   158,    65,   115,   146,   333,   152,    84,    85,
      99,   101,   138,    10,     1,   106,   153,   137,   185,   110,
     111,   163,    34,   216,    93,     6,     5,    33,   164,    94,
       8,    95,   113,    35,   282,   283,    83,   115,     7,   284,
      80,   350,   157,     2,    90,   154,    80,    11,   186,     2,
     206,   145,   115,   147,   222,   225,   228,   231,   150,   140,
      64,   238,   240,   242,    94,     9,   141,   226,   229,   232,
     215,   234,   156,    24,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   208,   202,   112,
     205,    25,   138,   138,   209,   115,    26,   337,   194,   195,
     235,   218,    94,   236,   141,    28,   192,   246,    94,   193,
     141,    40,    41,   211,    27,    42,   313,   314,   315,   316,
     317,   219,   220,    43,    44,    45,    46,    47,    48,    49,
      30,   115,   123,   124,   125,   126,   127,   128,     2,    50,
      10,    52,   265,   266,    53,    54,    55,    56,    57,    32,
      58,    59,    37,    60,   252,   253,    80,    61,   295,    62,
     267,   235,    80,   268,   269,   103,   145,   255,   270,   271,
     257,   258,   259,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   262,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   272,   235,
     116,   115,   273,   269,   274,   275,   296,   276,   235,   277,
     269,   301,   278,   279,   307,   280,   235,   181,   297,   281,
     269,   104,   166,    43,    91,    45,    46,    47,    48,    49,
     102,   285,   269,   349,   109,   200,   115,   142,   331,    15,
      16,    17,    18,    19,    20,    21,    22,    88,   289,   235,
     356,    59,   358,    89,   291,   235,   143,    61,   159,    62,
     182,   336,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   320,   314,   321,   316,
     317,   183,   357,   293,   235,   352,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   302,   303,
     184,   245,   188,    40,    41,   197,   189,    42,   313,   314,
     322,   316,   317,   264,   190,    43,    44,    45,    46,    47,
      48,    49,   121,   122,   123,   124,   125,   126,   127,   128,
       2,    50,    51,    52,   196,   304,    53,    54,    55,    56,
      57,   164,    58,    59,   199,    60,    40,    41,   207,    61,
      42,    62,   313,   314,   321,   323,   324,   210,    43,    44,
      45,    46,    47,    48,    49,   313,   325,   321,   316,   317,
     161,   162,   213,     2,    50,    96,    52,   221,   214,    53,
      54,    55,    56,    57,   224,    58,    59,   227,    60,    40,
      41,   230,    61,    42,    62,   313,   314,   321,   316,   317,
     233,    43,    44,    45,    46,    47,    48,    49,   237,   239,
     241,   247,   286,   248,   251,   260,     2,    50,   114,    52,
     140,   163,    53,    54,    55,    56,    57,   287,    58,    59,
     288,    60,    40,    41,   290,    61,    42,    62,   292,   294,
     319,   298,   311,   299,    43,    44,    45,    46,    47,    48,
      49,   300,   326,   327,   328,   346,   332,   335,   340,     2,
      50,   148,    52,   338,   339,    53,    54,    55,    56,    57,
     341,    58,    59,   342,    60,    40,    41,   343,    61,    42,
      62,   344,   345,   347,   348,    50,   353,    43,    44,    45,
      46,    47,    48,    49,   355,    31,     0,   354,     0,     0,
     155,     0,     2,    50,   167,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,     0,    60,    40,    41,
       0,    61,    42,    62,     0,     0,     0,     0,     0,     0,
      43,    44,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    50,   191,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,     0,
      60,    40,    41,     0,    61,    42,    62,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     2,    50,
     243,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,     0,    60,    40,    41,     0,    61,    42,    62,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    50,   261,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,     0,    60,    40,    41,     0,
      61,    42,    62,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    50,   312,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,     0,    60,
      40,    41,     0,    61,    42,    62,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     2,    50,   330,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,     0,    60,    40,    41,     0,    61,    42,    62,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    50,     0,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,     0,    60,    40,    41,     0,    61,
      42,    62,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46,    47,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     2,   201,     0,    52,     0,     0,    53,
      54,    55,    56,    57,     0,    58,    59,     0,    60,    40,
      41,     0,    61,    42,    62,     0,    40,    41,     0,     0,
      86,    43,    44,    45,    46,    47,    48,    49,    43,    91,
      45,    46,    47,    48,    49,     0,     2,    50,     0,    52,
       0,     0,   212,    54,    55,    56,    57,     0,    58,    59,
       0,    60,    88,     0,     0,    61,    59,    62,    89,   100,
       0,     0,    61,     0,    62,    40,    41,     0,     0,    86,
       0,     0,    40,    41,     0,     0,    86,    43,    91,    45,
      46,    47,    48,    49,    43,    87,    45,    46,    47,    48,
      49,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    88,     0,     0,     0,    59,     0,    89,    88,   105,
       0,    61,    59,    62,    89,    40,    41,     0,    61,    86,
      62,     0,    40,    41,     0,     0,    86,    43,    91,    45,
      46,    47,    48,    49,    43,    91,    45,    46,    47,    48,
      49,     0,   129,   130,   131,   132,   133,   134,   135,   136,
       0,    88,     0,     0,     0,    59,     0,    89,   144,     0,
       0,    61,    59,    62,    89,    40,    41,     0,    61,    86,
      62,     0,     0,     0,     0,     0,     0,    43,   305,    45,
      46,    47,    48,    49,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,    88,     0,     0,     0,    59,     0,    89,     0,     0,
       0,    61,     0,    62,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,   165,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,   151,   308,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,   160,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   198,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,   204,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,   244,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,     0,     0,     0,     0,   309,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,     0,   310,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,     0,   151,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     0,     0,     0,     0,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351
};

static const yytype_int16 yycheck[] =
{
      42,    43,   103,    34,    65,    94,   300,     7,    38,    39,
      52,    53,    81,    16,     1,    57,    16,    31,    16,    61,
      62,    44,    31,    31,    44,    16,     0,    28,    51,    49,
       4,    51,    63,    42,    46,    47,    37,    98,     0,    51,
      54,   335,   103,    30,    86,    45,    54,    50,    46,    30,
     151,    93,   113,    95,   181,   182,   183,   184,   100,    44,
      34,   188,   189,   190,    49,    49,    51,   182,   183,   184,
     159,   186,   103,    46,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    44,   149,    63,
     151,    50,   161,   162,    51,   156,    47,    44,   140,   141,
      48,   162,    49,    51,    51,    41,   137,   196,    49,   139,
      51,     3,     4,   155,    46,     7,    17,    18,    19,    20,
      21,   163,   164,    15,    16,    17,    18,    19,    20,    21,
      46,   192,     9,    10,    11,    12,    13,    14,    30,    31,
      16,    33,    46,    47,    36,    37,    38,    39,    40,    16,
      42,    43,    41,    45,    34,    35,    54,    49,   247,    51,
      47,    48,    54,    47,    48,    46,   208,   209,    46,    47,
     212,   213,   214,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   216,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    47,    48,
      48,   262,    47,    48,    46,    47,   248,    47,    48,    47,
      48,   253,    46,    47,   256,    47,    48,    46,   249,    47,
      48,    16,    52,    15,    16,    17,    18,    19,    20,    21,
      49,    47,    48,   334,    16,    52,   297,    16,   299,    22,
      23,    24,    25,    26,    27,    28,    29,    39,    47,    48,
     351,    43,   353,    45,    47,    48,    16,    49,    49,    51,
      46,   303,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    17,    18,    19,    20,
      21,    46,   353,    47,    48,   337,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    34,    35,
      46,    52,    46,     3,     4,    16,    46,     7,    17,    18,
      19,    20,    21,    52,    46,    15,    16,    17,    18,    19,
      20,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      30,    31,    32,    33,    49,    52,    36,    37,    38,    39,
      40,    51,    42,    43,    50,    45,     3,     4,    16,    49,
       7,    51,    17,    18,    19,    20,    21,    16,    15,    16,
      17,    18,    19,    20,    21,    17,    18,    19,    20,    21,
     107,   108,    36,    30,    31,    32,    33,    16,    36,    36,
      37,    38,    39,    40,    16,    42,    43,    16,    45,     3,
       4,    16,    49,     7,    51,    17,    18,    19,    20,    21,
      16,    15,    16,    17,    18,    19,    20,    21,    16,    16,
      16,    49,    16,    44,    34,    50,    30,    31,    32,    33,
      44,    44,    36,    37,    38,    39,    40,    19,    42,    43,
      47,    45,     3,     4,    47,    49,     7,    51,    47,    50,
      16,    32,    47,    46,    15,    16,    17,    18,    19,    20,
      21,    46,    19,    52,    50,    52,    31,    46,    46,    30,
      31,    32,    33,    50,    47,    36,    37,    38,    39,    40,
      47,    42,    43,    47,    45,     3,     4,    47,    49,     7,
      51,    47,    47,    47,    47,    31,    46,    15,    16,    17,
      18,    19,    20,    21,    47,    26,    -1,   340,    -1,    -1,
     102,    -1,    30,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    42,    43,    -1,    45,     3,     4,
      -1,    49,     7,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    42,    43,    -1,
      45,     3,     4,    -1,    49,     7,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      42,    43,    -1,    45,     3,     4,    -1,    49,     7,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    -1,    45,     3,     4,    -1,
      49,     7,    51,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
       3,     4,    -1,    49,     7,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39,    40,    -1,    42,
      43,    -1,    45,     3,     4,    -1,    49,     7,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    42,    43,    -1,    45,     3,     4,    -1,    49,
       7,    51,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    45,     3,
       4,    -1,    49,     7,    51,    -1,     3,     4,    -1,    -1,
       7,    15,    16,    17,    18,    19,    20,    21,    15,    16,
      17,    18,    19,    20,    21,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      -1,    45,    39,    -1,    -1,    49,    43,    51,    45,    46,
      -1,    -1,    49,    -1,    51,     3,     4,    -1,    -1,     7,
      -1,    -1,     3,     4,    -1,    -1,     7,    15,    16,    17,
      18,    19,    20,    21,    15,    16,    17,    18,    19,    20,
      21,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    39,    -1,    -1,    -1,    43,    -1,    45,    39,    47,
      -1,    49,    43,    51,    45,     3,     4,    -1,    49,     7,
      51,    -1,     3,     4,    -1,    -1,     7,    15,    16,    17,
      18,    19,    20,    21,    15,    16,    17,    18,    19,    20,
      21,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    39,    -1,
      -1,    49,    43,    51,    45,     3,     4,    -1,    49,     7,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    -1,    -1,
      -1,    49,    -1,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    46,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    47,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    47,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    46,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    30,    56,    57,    60,    16,     0,    60,    49,
      16,    50,    65,    66,    67,    22,    23,    24,    25,    26,
      27,    28,    29,    68,    46,    50,    47,    46,    41,    64,
      46,    67,    16,    68,    31,    42,    58,    41,    63,    62,
       3,     4,     7,    15,    16,    17,    18,    19,    20,    21,
      31,    32,    33,    36,    37,    38,    39,    40,    42,    43,
      45,    49,    51,    59,    60,    69,    70,    71,    73,    81,
      82,    84,    85,    86,    88,    89,    90,    91,    92,    96,
      54,    77,    78,    68,    58,    58,     7,    16,    39,    45,
      96,    16,    96,    44,    49,    51,    32,    60,    69,    96,
      46,    96,    49,    46,    16,    47,    96,    74,    75,    16,
      96,    96,    60,    69,    32,    70,    48,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    78,    61,
      44,    51,    16,    16,    39,    96,    88,    96,    32,    46,
      96,    46,     7,    16,    45,    71,    69,    70,    92,    49,
      47,    77,    77,    44,    51,    50,    52,    32,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    46,    46,    46,    46,    16,    46,    72,    46,    46,
      46,    32,    69,    58,    96,    96,    49,    16,    47,    50,
      52,    31,    70,    93,    47,    70,    92,    16,    44,    51,
      16,    96,    36,    36,    36,    88,    31,    76,    70,    96,
      96,    16,    72,    79,    16,    72,    79,    16,    72,    79,
      16,    72,    79,    16,    79,    48,    51,    16,    72,    16,
      72,    16,    72,    32,    47,    52,    88,    49,    44,    94,
      95,    34,    34,    35,    83,    96,    47,    96,    96,    96,
      50,    32,    69,    47,    52,    46,    47,    47,    47,    48,
      46,    47,    47,    47,    46,    47,    47,    47,    46,    47,
      47,    47,    46,    47,    51,    47,    16,    19,    47,    47,
      47,    47,    47,    47,    50,    88,    96,    69,    32,    46,
      46,    96,    34,    35,    52,    16,    87,    96,    47,    47,
      47,    47,    32,    17,    18,    19,    20,    21,    80,    16,
      17,    19,    19,    20,    21,    18,    19,    52,    50,    47,
      32,    70,    31,    93,    46,    46,    96,    44,    50,    47,
      46,    47,    47,    47,    47,    47,    52,    47,    47,    92,
      93,    46,    96,    46,    80,    47,    92,    70,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    61,    60,    62,    60,    63,    60,    64,
      60,    65,    65,    66,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    72,    72,    74,    73,    75,    73,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    91,    92,    92,    94,    93,    95,    93,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     4,     2,     5,
       4,     2,     1,     0,    10,     0,     9,     0,     8,     0,
       7,     1,     0,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     7,
       5,     5,     1,     3,     0,     4,     0,     4,     3,     2,
       2,     1,     5,     5,     5,     5,     5,     7,     7,     7,
       7,     7,     7,     8,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     7,     5,     5,     5,     5,     5,
       3,     5,     1,     1,     1,     1,     1,     3,     2,     7,
       4,     4,     7,     8,     4,     5,     4,     4,     4,     6,
       6,     6,     9,     9,     3,     1,     1,     0,     3,     1,
       8,     6,     3,     2,     0,     4,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     3,     3,     2,     2,     2,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: func_list  */
#line 56 "parser.y"
              {
         program_ast = (yyvsp[0].ast);
        print_ast((yyvsp[0].ast), 0);
    }
#line 1606 "parser.tab.c"
    break;

  case 3: /* program: error  */
#line 60 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1614 "parser.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 66 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1620 "parser.tab.c"
    break;

  case 5: /* func_list: function  */
#line 67 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1626 "parser.tab.c"
    break;

  case 6: /* function_body: T_BEGIN stmt_list T_END  */
#line 70 "parser.y"
                            { (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); }
#line 1632 "parser.tab.c"
    break;

  case 7: /* function_body: T_BEGIN nested_func_list stmt_list T_END  */
#line 71 "parser.y"
                                             { (yyval.ast) = make_node("BLOCK", 2, (yyvsp[-2].ast), (yyvsp[-1].ast)); }
#line 1638 "parser.tab.c"
    break;

  case 8: /* function_body: T_BEGIN T_END  */
#line 72 "parser.y"
                  { (yyval.ast) = make_node("BLOCK", 0); }
#line 1644 "parser.tab.c"
    break;

  case 9: /* function_body: VAR type_decls T_BEGIN stmt_list T_END  */
#line 73 "parser.y"
                                            { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-3].ast), make_node("BLOCK", 1, (yyvsp[-1].ast))); 
    }
#line 1652 "parser.tab.c"
    break;

  case 10: /* function_body: VAR type_decls T_BEGIN T_END  */
#line 76 "parser.y"
                                 { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-2].ast), make_node("BLOCK", 0)); 
    }
#line 1660 "parser.tab.c"
    break;

  case 11: /* nested_func_list: nested_func_list function  */
#line 81 "parser.y"
                              { (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1666 "parser.tab.c"
    break;

  case 12: /* nested_func_list: function  */
#line 82 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1672 "parser.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 85 "parser.y"
                                                     {
        current_param_index = 0;
        if (symbol_exists_in_current_scope((yyvsp[-6].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-6].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params((yyvsp[-4].ast));
            collect_param_types((yyvsp[-4].ast), param_types);
            insert_function_with_param_types((yyvsp[-6].sval), get_type_from_name((yyvsp[0].ast)->name), param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", (yyvsp[-6].sval), current_scope, param_count);
        }
        strcpy(current_function_name, (yyvsp[-6].sval));

        if (strcmp((yyvsp[-6].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ((yyvsp[-4].ast)->child_count > 0 && strcmp((yyvsp[-4].ast)->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");

            if (get_type_from_name((yyvsp[0].ast)->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name((yyvsp[0].ast)->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-6].sval));
        //enter_scope();
    }
#line 1711 "parser.tab.c"
    break;

  case 14: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type $@1 function_body  */
#line 118 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-8].sval), 0),
             (yyvsp[-6].ast),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
              exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-8].sval), current_scope);
    }
#line 1729 "parser.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 132 "parser.y"
                                            {
        if (symbol_exists_in_current_scope((yyvsp[-5].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-5].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types((yyvsp[-5].sval), get_type_from_name((yyvsp[0].ast)->name), 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-5].sval), current_scope);
        }
        strcpy(current_function_name, (yyvsp[-5].sval));

        if (strcmp((yyvsp[-5].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if (get_type_from_name((yyvsp[0].ast)->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name((yyvsp[0].ast)->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-5].sval));
        //enter_scope();
    }
#line 1762 "parser.tab.c"
    break;

  case 16: /* function: DEF ID LPAREN RPAREN COLON RETURNS type $@2 function_body  */
#line 159 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-7].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-7].sval), current_scope);
    }
#line 1780 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 173 "parser.y"
                                        {
    current_param_index = 0;
        if (symbol_exists_in_current_scope((yyvsp[-4].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-4].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params((yyvsp[-2].ast));
            collect_param_types((yyvsp[-2].ast), param_types);
            insert_function_with_param_types((yyvsp[-4].sval), DT_VOID, param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", (yyvsp[-4].sval), current_scope, param_count);
        }
        strcpy(current_function_name, (yyvsp[-4].sval));

        if (strcmp((yyvsp[-4].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ((yyvsp[-2].ast)->child_count > 0 && strcmp((yyvsp[-2].ast)->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-4].sval));
        //enter_scope();
    }
#line 1813 "parser.tab.c"
    break;

  case 18: /* function: DEF ID LPAREN par_list RPAREN COLON $@3 function_body  */
#line 200 "parser.y"
                    {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-6].sval), 0),
             (yyvsp[-4].ast),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-6].sval), current_scope);
    }
#line 1831 "parser.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 214 "parser.y"
                               {
        if (symbol_exists_in_current_scope((yyvsp[-3].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types((yyvsp[-3].sval), DT_VOID, 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-3].sval), current_scope);
        }
    strcpy(current_function_name, (yyvsp[-3].sval));

        if (strcmp((yyvsp[-3].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, (yyvsp[-3].sval));
       // enter_scope();
    }
#line 1858 "parser.tab.c"
    break;

  case 20: /* function: DEF ID LPAREN RPAREN COLON $@4 function_body  */
#line 235 "parser.y"
                    {
        // exit_scope();
        inside_main = 0;
         current_function_name[0] = '\0';  

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-5].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
                    exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", (yyvsp[-5].sval), current_scope);

    }
#line 1877 "parser.tab.c"
    break;

  case 21: /* par_list: param_list_item_list  */
#line 252 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1883 "parser.tab.c"
    break;

  case 22: /* par_list: %empty  */
#line 253 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1889 "parser.tab.c"
    break;

  case 23: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 257 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1897 "parser.tab.c"
    break;

  case 24: /* param_list_item_list: par_list_item  */
#line 260 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1905 "parser.tab.c"
    break;

  case 25: /* par_list_item: ID type COLON ID  */
#line 267 "parser.y"
                     {
        current_param_index++;
        
        check_param_order((yyvsp[-3].sval), current_param_index);
        
        insert_symbol((yyvsp[0].sval), VAR_SYM, get_type_from_name((yyvsp[-2].ast)->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", (yyvsp[0].sval), current_scope);
        
    
              (yyval.ast) = make_node((yyvsp[-3].sval), 2,
          make_node((yyvsp[-2].ast)->name, 0),
            make_node((yyvsp[0].sval),      0));
    }
#line 1923 "parser.tab.c"
    break;

  case 26: /* type: TYPE_INT  */
#line 282 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1929 "parser.tab.c"
    break;

  case 27: /* type: TYPE_CHAR  */
#line 283 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1935 "parser.tab.c"
    break;

  case 28: /* type: TYPE_REAL  */
#line 284 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1941 "parser.tab.c"
    break;

  case 29: /* type: TYPE_BOOL  */
#line 285 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1947 "parser.tab.c"
    break;

  case 30: /* type: TYPE_STRING  */
#line 286 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1953 "parser.tab.c"
    break;

  case 31: /* type: TYPE_INT_PTR  */
#line 287 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1959 "parser.tab.c"
    break;

  case 32: /* type: TYPE_CHAR_PTR  */
#line 288 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1965 "parser.tab.c"
    break;

  case 33: /* type: TYPE_REAL_PTR  */
#line 289 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1971 "parser.tab.c"
    break;

  case 34: /* stmt_list: stmt_list stmt  */
#line 293 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 1980 "parser.tab.c"
    break;

  case 35: /* stmt_list: stmt  */
#line 297 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1989 "parser.tab.c"
    break;

  case 48: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 319 "parser.y"
                            {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else {
            DataType lhs_type = sym->type;
            DataType rhs_type = get_expr_type((yyvsp[-1].ast));
            
            if (rhs_type == DT_PTR_INT && (yyvsp[-1].ast)->name && strcmp((yyvsp[-1].ast)->name, "nullptr") == 0) {
                if (lhs_type != DT_PTR_INT && lhs_type != DT_PTR_CHAR && lhs_type != DT_PTR_REAL) {
                    char error_msg[100];
                    sprintf(error_msg, "Semantic Error: Cannot assign null to non-pointer type %s", 
                            get_name_from_type(lhs_type));
                    yyerror(error_msg);
                }
            }
            else if (!is_type_compatible(lhs_type, rhs_type)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment, cannot assign %s to %s", 
                        get_name_from_type(rhs_type), get_name_from_type(lhs_type));
                yyerror(error_msg);
            }
        }
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 2021 "parser.tab.c"
    break;

  case 49: /* assignment: ID LBRACK expr RBRACK ASSIGN expr SEMICOLON  */
#line 346 "parser.y"
                                                  {
        Symbol* sym = lookup_any_scope((yyvsp[-6].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-6].sval));
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    (yyvsp[-6].sval), get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index((yyvsp[-4].ast));
            
            DataType rhs_type = get_expr_type((yyvsp[-1].ast));
            if (rhs_type != DT_CHAR) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: String element can only be assigned a char value, got %s", 
                        get_name_from_type(rhs_type));
                yyerror(error_msg);
            }
        }
        (yyval.ast) = make_node("=", 2, make_node("array_access", 2, make_node((yyvsp[-6].sval), 0), (yyvsp[-4].ast)), (yyvsp[-1].ast));
    }
#line 2050 "parser.tab.c"
    break;

  case 50: /* assignment: MULT ID ASSIGN expr SEMICOLON  */
#line 370 "parser.y"
                                  {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        }
        
        DataType type = sym->type;
        if (!is_pointer_type(type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", (yyvsp[-3].sval));
            yyerror(error_msg);
        }
        
        DataType target_type = get_base_type(type);
        
        DataType expr_type = get_expr_type((yyvsp[-1].ast));
        if (target_type != expr_type) {
            if (!(target_type == DT_REAL && expr_type == DT_INT)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment to dereferenced pointer: expected %s, got %s",
                        get_name_from_type(target_type), get_name_from_type(expr_type));
                yyerror(error_msg);
            }
        }
        
        (yyval.ast) = make_node("=", 2, make_node("*", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
    }
#line 2084 "parser.tab.c"
    break;

  case 51: /* assignment: ADDRESS ID ASSIGN expr SEMICOLON  */
#line 399 "parser.y"
                                       {
        yyerror("Semantic Error: Cannot use address operator on left side of assignment");
        (yyval.ast) = make_node("error", 2, make_node("&", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
   }
#line 2093 "parser.tab.c"
    break;

  case 52: /* id_list: ID  */
#line 406 "parser.y"
                                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2099 "parser.tab.c"
    break;

  case 53: /* id_list: id_list COMMA ID  */
#line 407 "parser.y"
                               { (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), make_node((yyvsp[0].sval), 0)); }
#line 2105 "parser.tab.c"
    break;

  case 54: /* $@5: %empty  */
#line 412 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2114 "parser.tab.c"
    break;

  case 55: /* var_stmt: VAR $@5 type_decls block_content  */
#line 415 "parser.y"
                               {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2122 "parser.tab.c"
    break;

  case 56: /* $@6: %empty  */
#line 418 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2131 "parser.tab.c"
    break;

  case 57: /* var_stmt: VAR $@6 type_decls stmt  */
#line 421 "parser.y"
                      {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
        exit_scope();
        printf("DEBUG: Exited VAR scope\n");
    }
#line 2141 "parser.tab.c"
    break;

  case 58: /* block_content: T_BEGIN stmt_list T_END  */
#line 428 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from block_content\n");
    }
#line 2151 "parser.tab.c"
    break;

  case 59: /* block_content: T_BEGIN T_END  */
#line 433 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from empty block_content\n");
    }
#line 2161 "parser.tab.c"
    break;

  case 60: /* type_decls: type_decls type_decl  */
#line 440 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2169 "parser.tab.c"
    break;

  case 61: /* type_decls: type_decl  */
#line 443 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2177 "parser.tab.c"
    break;

  case 62: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 448 "parser.y"
                                     {
        insert_checked_variable((yyvsp[-1].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2186 "parser.tab.c"
    break;

  case 63: /* type_decl: TYPE TYPE_BOOL COLON ID SEMICOLON  */
#line 452 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2195 "parser.tab.c"
    break;

  case 64: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 456 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2204 "parser.tab.c"
    break;

  case 65: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 460 "parser.y"
                                        {
        insert_checked_variable((yyvsp[-1].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2213 "parser.tab.c"
    break;

  case 66: /* type_decl: TYPE TYPE_REAL COLON ID SEMICOLON  */
#line 464 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2222 "parser.tab.c"
    break;

  case 67: /* type_decl: TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON  */
#line 468 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-3].sval), 1,make_node((yyvsp[-1].sval),0)));
    }
#line 2231 "parser.tab.c"
    break;

  case 68: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 472 "parser.y"
                                               {
        insert_checked_variable((yyvsp[-3].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2240 "parser.tab.c"
    break;

  case 69: /* type_decl: TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON  */
#line 476 "parser.y"
                                                         {
        insert_checked_variable((yyvsp[-3].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2249 "parser.tab.c"
    break;

  case 70: /* type_decl: TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON  */
#line 480 "parser.y"
                                                             {
        insert_checked_variable((yyvsp[-3].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2258 "parser.tab.c"
    break;

  case 71: /* type_decl: TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON  */
#line 484 "parser.y"
                                                 {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("true", 0)));
    }
#line 2267 "parser.tab.c"
    break;

  case 72: /* type_decl: TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON  */
#line 488 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("false", 0)));
    }
#line 2276 "parser.tab.c"
    break;

  case 73: /* type_decl: TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON  */
#line 492 "parser.y"
                                                           {
        int size = atoi((yyvsp[-2].sval));
        if (size <= 0) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String size must be a positive integer");
            yyerror(error_msg);
        }
        insert_checked_variable((yyvsp[-4].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 3, make_node("string", 0), make_node((yyvsp[-4].sval), 0), make_node((yyvsp[-2].sval), 0));
    }
#line 2291 "parser.tab.c"
    break;

  case 74: /* type_decl: TYPE TYPE_INT_PTR COLON ID SEMICOLON  */
#line 502 "parser.y"
                                           {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2300 "parser.tab.c"
    break;

  case 75: /* type_decl: TYPE TYPE_CHAR_PTR COLON ID SEMICOLON  */
#line 506 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2309 "parser.tab.c"
    break;

  case 76: /* type_decl: TYPE TYPE_REAL_PTR COLON ID SEMICOLON  */
#line 510 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2318 "parser.tab.c"
    break;

  case 77: /* type_decl: TYPE TYPE_INT COLON id_list SEMICOLON  */
#line 515 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int", 0), (yyvsp[-1].ast));
    }
#line 2327 "parser.tab.c"
    break;

  case 78: /* type_decl: TYPE TYPE_BOOL COLON id_list SEMICOLON  */
#line 519 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_BOOL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("bool", 0), (yyvsp[-1].ast));
    }
#line 2336 "parser.tab.c"
    break;

  case 79: /* type_decl: TYPE TYPE_CHAR COLON id_list SEMICOLON  */
#line 523 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char", 0), (yyvsp[-1].ast));
    }
#line 2345 "parser.tab.c"
    break;

  case 80: /* type_decl: TYPE TYPE_REAL COLON id_list SEMICOLON  */
#line 527 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real", 0), (yyvsp[-1].ast));
    }
#line 2354 "parser.tab.c"
    break;

  case 81: /* type_decl: TYPE TYPE_INT_PTR COLON id_list SEMICOLON  */
#line 531 "parser.y"
                                              {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int*", 0), (yyvsp[-1].ast));
    }
#line 2363 "parser.tab.c"
    break;

  case 82: /* type_decl: TYPE TYPE_CHAR_PTR COLON id_list SEMICOLON  */
#line 535 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char*", 0), (yyvsp[-1].ast));
    }
#line 2372 "parser.tab.c"
    break;

  case 83: /* type_decl: TYPE TYPE_REAL_PTR COLON id_list SEMICOLON  */
#line 539 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real*", 0), (yyvsp[-1].ast));
    }
#line 2381 "parser.tab.c"
    break;

  case 84: /* type_decl: TYPE TYPE_STRING id_list LBRACK NUM RBRACK SEMICOLON  */
#line 543 "parser.y"
                                                           {
        int size = atoi((yyvsp[-2].sval));
        if (size <= 0) {
           yyerror("Semantic Error: String size must be a positive integer");
       }
        /* רישום משתנים */
        add_multiple_variables((yyvsp[-4].ast), DT_STRING);
        /* יצירת AST: שם הצומת, מספר ילדים, טיפוס, רשימת מזהים, גודל */
        (yyval.ast) = make_node("TYPE_STRING_ARRAY", 3,
                      make_node("string", 0),
                       (yyvsp[-4].ast),
                       make_node((yyvsp[-2].sval), 0));
    }
#line 2399 "parser.tab.c"
    break;

  case 85: /* type_decl: TYPE TYPE_BOOL COLON id_value_list SEMICOLON  */
#line 556 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_BOOL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("bool", 0), (yyvsp[-1].ast));
}
#line 2408 "parser.tab.c"
    break;

  case 86: /* type_decl: TYPE TYPE_INT COLON id_value_list SEMICOLON  */
#line 560 "parser.y"
                                              {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_INT);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("int", 0), (yyvsp[-1].ast));
}
#line 2417 "parser.tab.c"
    break;

  case 87: /* type_decl: TYPE TYPE_CHAR COLON id_value_list SEMICOLON  */
#line 564 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_CHAR);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("char", 0), (yyvsp[-1].ast));
}
#line 2426 "parser.tab.c"
    break;

  case 88: /* type_decl: TYPE TYPE_STRING COLON id_value_list SEMICOLON  */
#line 568 "parser.y"
                                                 {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_STRING);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("string", 0), (yyvsp[-1].ast));
}
#line 2435 "parser.tab.c"
    break;

  case 89: /* type_decl: TYPE TYPE_REAL COLON id_value_list SEMICOLON  */
#line 572 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_REAL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("real", 0), (yyvsp[-1].ast));
}
#line 2444 "parser.tab.c"
    break;

  case 90: /* id_value_list: ID COLON literal  */
#line 579 "parser.y"
                       {
          (yyval.ast) = make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast));  // $3 כבר AST
      }
#line 2452 "parser.tab.c"
    break;

  case 91: /* id_value_list: id_value_list COMMA ID COLON literal  */
#line 582 "parser.y"
                                           {
          (yyval.ast) = make_node("", 2, (yyvsp[-4].ast), make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast)));
      }
#line 2460 "parser.tab.c"
    break;

  case 92: /* literal: NUM  */
#line 589 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2466 "parser.tab.c"
    break;

  case 93: /* literal: TRUE  */
#line 590 "parser.y"
                { (yyval.ast) = make_node("true", 0); }
#line 2472 "parser.tab.c"
    break;

  case 94: /* literal: FALSE  */
#line 591 "parser.y"
                { (yyval.ast) = make_node("false", 0); }
#line 2478 "parser.tab.c"
    break;

  case 95: /* literal: CHAR_LITERAL  */
#line 592 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2484 "parser.tab.c"
    break;

  case 96: /* literal: STRING_LITERAL  */
#line 593 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2490 "parser.tab.c"
    break;

  case 97: /* return_stmt: RETURN expr SEMICOLON  */
#line 598 "parser.y"
                          {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);

        
        check_return_type((yyvsp[-1].ast), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 2503 "parser.tab.c"
    break;

  case 98: /* return_stmt: RETURN SEMICOLON  */
#line 606 "parser.y"
                     {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        check_return_type(make_node("NONE", 0), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 2515 "parser.tab.c"
    break;

  case 99: /* if_stmt: IF expr COLON nested_block ELSE COLON nested_block  */
#line 617 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2524 "parser.tab.c"
    break;

  case 100: /* if_stmt: IF expr COLON nested_block  */
#line 622 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2533 "parser.tab.c"
    break;

  case 101: /* if_stmt: IF expr COLON stmt  */
#line 627 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2542 "parser.tab.c"
    break;

  case 102: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 632 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2551 "parser.tab.c"
    break;

  case 103: /* if_stmt: IF expr COLON nested_block elif_list ELSE COLON nested_block  */
#line 637 "parser.y"
    {
        check_boolean_condition((yyvsp[-6].ast), "if");
        (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2560 "parser.tab.c"
    break;

  case 104: /* elif_list: ELIF expr COLON block  */
#line 645 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2569 "parser.tab.c"
    break;

  case 105: /* elif_list: elif_list ELIF expr COLON block  */
#line 650 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF - ...", 3, (yyvsp[-4].ast), make_node("elif", 2, (yyvsp[-2].ast), (yyvsp[0].ast)));
    }
#line 2578 "parser.tab.c"
    break;

  case 106: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 657 "parser.y"
    {
        check_boolean_condition((yyvsp[-1].ast), "while");
        (yyval.ast) = make_node("while", 1, (yyvsp[-1].ast));
    }
#line 2587 "parser.tab.c"
    break;

  case 107: /* while_stmt: WHILE expr COLON block  */
#line 662 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2596 "parser.tab.c"
    break;

  case 108: /* while_stmt: WHILE expr COLON stmt  */
#line 667 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2605 "parser.tab.c"
    break;

  case 109: /* do_while_stmt: DO COLON stmt_list WHILE expr SEMICOLON  */
#line 673 "parser.y"
                                            {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2614 "parser.tab.c"
    break;

  case 110: /* do_while_stmt: DO COLON stmt WHILE expr SEMICOLON  */
#line 678 "parser.y"
                                       {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2623 "parser.tab.c"
    break;

  case 111: /* do_while_stmt: DO COLON block WHILE expr SEMICOLON  */
#line 683 "parser.y"
                                        {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2632 "parser.tab.c"
    break;

  case 112: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block  */
#line 690 "parser.y"
                                                                        {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2641 "parser.tab.c"
    break;

  case 113: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt  */
#line 695 "parser.y"
                                                                       {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2650 "parser.tab.c"
    break;

  case 114: /* update_expr: ID ASSIGN expr  */
#line 702 "parser.y"
                   {
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-2].sval), 0), (yyvsp[0].ast));
    }
#line 2658 "parser.tab.c"
    break;

  case 115: /* update_expr: expr  */
#line 705 "parser.y"
           {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2666 "parser.tab.c"
    break;

  case 116: /* call_args: call_list  */
#line 710 "parser.y"
              { (yyval.ast) = make_node("args", 1, (yyvsp[0].ast)); }
#line 2672 "parser.tab.c"
    break;

  case 117: /* call_args: %empty  */
#line 711 "parser.y"
                { (yyval.ast) = make_node("args", 1, make_node("none", 0)); }
#line 2678 "parser.tab.c"
    break;

  case 118: /* call_list: call_list COMMA expr  */
#line 716 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2686 "parser.tab.c"
    break;

  case 119: /* call_list: expr  */
#line 720 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 2694 "parser.tab.c"
    break;

  case 120: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 727 "parser.y"
                                                        {
        Symbol* func = lookup_any_scope((yyvsp[-4].sval));
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", (yyvsp[-4].sval));
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-4].sval));
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-2].ast));
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", (yyvsp[-4].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("ASSIGN-CALL", 2,
                       make_node((yyvsp[-7].sval), 0),
                       make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast)));
    }
#line 2725 "parser.tab.c"
    break;

  case 121: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 756 "parser.y"
                                              {
        Symbol* func = lookup_any_scope((yyvsp[-4].sval));
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", (yyvsp[-4].sval));
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-4].sval));
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-2].ast));
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", (yyvsp[-4].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast));
    }
#line 2754 "parser.tab.c"
    break;

  case 122: /* block: T_BEGIN stmt_list T_END  */
#line 783 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
    }
#line 2762 "parser.tab.c"
    break;

  case 123: /* block: T_BEGIN T_END  */
#line 786 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
    }
#line 2770 "parser.tab.c"
    break;

  case 124: /* $@7: %empty  */
#line 791 "parser.y"
            {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2779 "parser.tab.c"
    break;

  case 125: /* nested_block: T_BEGIN $@7 stmt_list T_END  */
#line 794 "parser.y"
                      {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2789 "parser.tab.c"
    break;

  case 126: /* $@8: %empty  */
#line 799 "parser.y"
              {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2798 "parser.tab.c"
    break;

  case 127: /* nested_block: T_BEGIN $@8 T_END  */
#line 802 "parser.y"
            {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2808 "parser.tab.c"
    break;

  case 128: /* expr: expr PLUS expr  */
#line 810 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '+' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("+", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2824 "parser.tab.c"
    break;

  case 129: /* expr: expr MINUS expr  */
#line 821 "parser.y"
                      {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '-' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("-", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2840 "parser.tab.c"
    break;

  case 130: /* expr: expr MULT expr  */
#line 832 "parser.y"
                     {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '*' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("*", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2856 "parser.tab.c"
    break;

  case 131: /* expr: expr DIV expr  */
#line 843 "parser.y"
                     {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '/' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("/", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2872 "parser.tab.c"
    break;

  case 132: /* expr: expr EQ expr  */
#line 854 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '==' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("==", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2888 "parser.tab.c"
    break;

  case 133: /* expr: expr NE expr  */
#line 865 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '!=' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("!=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2904 "parser.tab.c"
    break;

  case 134: /* expr: expr LT expr  */
#line 876 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("<", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2920 "parser.tab.c"
    break;

  case 135: /* expr: expr GT expr  */
#line 887 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node(">", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2936 "parser.tab.c"
    break;

  case 136: /* expr: expr LE expr  */
#line 898 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node("<=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2952 "parser.tab.c"
    break;

  case 137: /* expr: expr GE expr  */
#line 909 "parser.y"
                   {
    DataType left = get_expr_type((yyvsp[-2].ast));
    DataType right = get_expr_type((yyvsp[0].ast));
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    (yyval.ast) = make_node(">=", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
	}
#line 2968 "parser.tab.c"
    break;

  case 138: /* expr: LPAREN expr RPAREN  */
#line 920 "parser.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2974 "parser.tab.c"
    break;

  case 139: /* expr: ID LBRACK expr RBRACK  */
#line 922 "parser.y"
                            {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    (yyvsp[-3].sval), get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index((yyvsp[-1].ast));
        }
        (yyval.ast) = make_node("array_access", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 2995 "parser.tab.c"
    break;

  case 140: /* expr: LBRACK expr RBRACK  */
#line 939 "parser.y"
                         {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        (yyval.ast) = (yyvsp[-1].ast); 
    }
#line 3006 "parser.tab.c"
    break;

  case 141: /* expr: NUM  */
#line 946 "parser.y"
          { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3012 "parser.tab.c"
    break;

  case 142: /* expr: ID  */
#line 947 "parser.y"
         {
        Symbol* sym = lookup_any_scope((yyvsp[0].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node((yyvsp[0].sval), 0);
    }
#line 3026 "parser.tab.c"
    break;

  case 143: /* expr: CHAR_LITERAL  */
#line 956 "parser.y"
                   { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3032 "parser.tab.c"
    break;

  case 144: /* expr: STRING_LITERAL  */
#line 957 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3038 "parser.tab.c"
    break;

  case 145: /* expr: NULLPTR  */
#line 958 "parser.y"
              { (yyval.ast) = make_node("nullptr", 0); }
#line 3044 "parser.tab.c"
    break;

  case 146: /* expr: TRUE  */
#line 959 "parser.y"
           { (yyval.ast) = make_node("true", 0); }
#line 3050 "parser.tab.c"
    break;

  case 147: /* expr: FALSE  */
#line 960 "parser.y"
            { (yyval.ast) = make_node("false", 0); }
#line 3056 "parser.tab.c"
    break;

  case 148: /* expr: AND  */
#line 961 "parser.y"
          { (yyval.ast) = make_node("and", 0); }
#line 3062 "parser.tab.c"
    break;

  case 149: /* expr: OR  */
#line 962 "parser.y"
         { (yyval.ast) = make_node("or", 0); }
#line 3068 "parser.tab.c"
    break;

  case 150: /* expr: NOT  */
#line 963 "parser.y"
          { (yyval.ast) = make_node("not", 0); }
#line 3074 "parser.tab.c"
    break;

  case 151: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 964 "parser.y"
                                      {
        Symbol* func = lookup_any_scope((yyvsp[-3].sval));
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-1].ast));
            if (expected == actual) {
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 3090 "parser.tab.c"
    break;

  case 152: /* expr: ID LPAREN call_args RPAREN  */
#line 975 "parser.y"
                                 {
        
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char msg[128];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration/definition", (yyvsp[-3].sval));
            yyerror(msg);
        }
        else if (sym->kind != FUNC_SYM) {
            char msg[128];
            sprintf(msg, "Semantic Error: '%s' is not a function", (yyvsp[-3].sval));
            yyerror(msg);
        }
        else {
         
            int expected = sym->param_count;
            int actual   = count_actual_params((yyvsp[-1].ast));
          if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d args, got %d",
                        (yyvsp[-3].sval), expected, actual);
                yyerror(msg);
            } else {
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 3123 "parser.tab.c"
    break;

  case 153: /* expr: expr AND expr  */
#line 1003 "parser.y"
                    { (yyval.ast) = make_node("and", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3129 "parser.tab.c"
    break;

  case 154: /* expr: expr OR expr  */
#line 1004 "parser.y"
                   { (yyval.ast) = make_node("or", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3135 "parser.tab.c"
    break;

  case 155: /* expr: NOT expr  */
#line 1005 "parser.y"
               { (yyval.ast) = make_node("not", 1, (yyvsp[0].ast)); }
#line 3141 "parser.tab.c"
    break;

  case 156: /* expr: MULT expr  */
#line 1007 "parser.y"
              {
  
    if (!(yyvsp[0].ast)) {
        yyerror("Semantic Error: Invalid dereference expression");
        (yyval.ast) = make_node("error", 0);
    }
   
    else if ((yyvsp[0].ast)->name && strcmp((yyvsp[0].ast)->name, "*") == 0) {
        yyerror("Semantic Error: Double dereference is not allowed (cannot use **ptr)");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
    
    else if ((yyvsp[0].ast)->name && (yyvsp[0].ast)->child_count == 0) {
        Symbol* sym = lookup_any_scope((yyvsp[0].ast)->name);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].ast)->name);
            yyerror(error_msg);
        }
        else if (!is_pointer_type(sym->type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", (yyvsp[0].ast)->name);
            yyerror(error_msg);
        }
        (yyval.ast) = make_node("*", 1, (yyvsp[0].ast));
    }
   
    else {
        yyerror("Semantic Error: Cannot dereference non-pointer expression");
        (yyval.ast) = make_node("error", 1, (yyvsp[0].ast));
    }
}
#line 3178 "parser.tab.c"
    break;

  case 157: /* expr: ADDRESS ID  */
#line 1039 "parser.y"
               {
    Symbol* sym = lookup_any_scope((yyvsp[0].sval));
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
        yyerror(error_msg);
    } else {
        DataType type = sym->type;
        if (type == DT_PTR_INT || type == DT_PTR_CHAR || type == DT_PTR_REAL) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of pointer variable '%s'", (yyvsp[0].sval));
            yyerror(error_msg);
        } else if (type != DT_INT && type != DT_REAL && type != DT_CHAR && type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of '%s' with type '%s'",
                    (yyvsp[0].sval), get_name_from_type(type));
            yyerror(error_msg);
        }
    }

    (yyval.ast) = make_node("&", 1, make_node((yyvsp[0].sval), 0));
}
#line 3205 "parser.tab.c"
    break;

  case 158: /* expr: ADDRESS ID LBRACK expr RBRACK  */
#line 1062 "parser.y"
                                {
    Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
        yyerror(error_msg);
    } else if (sym->type != DT_STRING) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                (yyvsp[-3].sval), get_name_from_type(sym->type));
        yyerror(error_msg);
    } else {
        check_string_index((yyvsp[-1].ast));
    }
    
    
    (yyval.ast) = make_node("&array_access", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
}
#line 3228 "parser.tab.c"
    break;


#line 3232 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1083 "parser.y"


void yyerror(const char* s) {
    extern char* yytext;
    fprintf(stderr, "Syntax Error: %s (current token: %s)\n", s, yytext);
}

int main(int argc, char* argv[]) {
    printf("DEBUG: Starting compiler\n");

    enter_scope();
    int result = yyparse();

    printf("\nDEBUG: Final symbol tables:\n");
    print_symbol_tables();
    preserve_symbol_tables = 1;
    exit_scope();

    // בדוק אם יש _main_ רק אם הפרסינג הצליח
    if (result == 0 && !main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    // גנרט קוד 3AC תמיד אם הפרסינג הצליח (ללא תלות ב-main)
    if (result == 0 && program_ast) {
        printf("\n=== THREE ADDRESS CODE ===\n");
        generate_tac_from_ast(program_ast);
    } else if (result != 0) {
        printf("Parsing failed, cannot generate 3AC\n");
    } else if (!program_ast) {
        printf("No AST available for 3AC generation\n");
    }

    return result;
}
