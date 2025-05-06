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
    



#line 96 "parser.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_CHAR_LITERAL = 4,               /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_NUM = 6,                        /* NUM  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_CHAR = 8,                  /* TYPE_CHAR  */
  YYSYMBOL_TYPE_REAL = 9,                  /* TYPE_REAL  */
  YYSYMBOL_TYPE_BOOL = 10,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 11,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_INT_PTR = 12,              /* TYPE_INT_PTR  */
  YYSYMBOL_TYPE_CHAR_PTR = 13,             /* TYPE_CHAR_PTR  */
  YYSYMBOL_TYPE_REAL_PTR = 14,             /* TYPE_REAL_PTR  */
  YYSYMBOL_DEF = 15,                       /* DEF  */
  YYSYMBOL_T_BEGIN = 16,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 17,                     /* T_END  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ELIF = 20,                      /* ELIF  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_CALL = 24,                      /* CALL  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_RETURNS = 26,                   /* RETURNS  */
  YYSYMBOL_VAR = 27,                       /* VAR  */
  YYSYMBOL_NULLPTR = 28,                   /* NULLPTR  */
  YYSYMBOL_TRUE = 29,                      /* TRUE  */
  YYSYMBOL_FALSE = 30,                     /* FALSE  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NE = 35,                        /* NE  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_GE = 37,                        /* GE  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 41,                      /* PLUS  */
  YYSYMBOL_MINUS = 42,                     /* MINUS  */
  YYSYMBOL_MULT = 43,                      /* MULT  */
  YYSYMBOL_DIV = 44,                       /* DIV  */
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
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_par_list = 59,                  /* par_list  */
  YYSYMBOL_param_list_item_list = 60,      /* param_list_item_list  */
  YYSYMBOL_par_list_item = 61,             /* par_list_item  */
  YYSYMBOL_type = 62,                      /* type  */
  YYSYMBOL_stmt_list = 63,                 /* stmt_list  */
  YYSYMBOL_stmt = 64,                      /* stmt  */
  YYSYMBOL_assignment = 65,                /* assignment  */
  YYSYMBOL_var_stmt = 66,                  /* var_stmt  */
  YYSYMBOL_type_decls = 67,                /* type_decls  */
  YYSYMBOL_type_decl = 68,                 /* type_decl  */
  YYSYMBOL_return_stmt = 69,               /* return_stmt  */
  YYSYMBOL_if_stmt = 70,                   /* if_stmt  */
  YYSYMBOL_elif_list = 71,                 /* elif_list  */
  YYSYMBOL_while_stmt = 72,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 73,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 74,                  /* for_stmt  */
  YYSYMBOL_call_args = 75,                 /* call_args  */
  YYSYMBOL_call_list = 76,                 /* call_list  */
  YYSYMBOL_assignment_call = 77,           /* assignment_call  */
  YYSYMBOL_void_call = 78,                 /* void_call  */
  YYSYMBOL_block = 79,                     /* block  */
  YYSYMBOL_80_1 = 80,                      /* $@1  */
  YYSYMBOL_81_2 = 81,                      /* $@2  */
  YYSYMBOL_expr = 82                       /* expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       0,    57,    57,    60,    66,    67,    70,   107,   146,   181,
     214,   215,   219,   222,   229,   235,   236,   237,   238,   239,
     240,   241,   242,   246,   250,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   275,   290,   293,
     298,   301,   306,   309,   312,   315,   324,   331,   338,   342,
     346,   350,   354,   362,   366,   372,   376,   380,   386,   393,
     397,   405,   406,   409,   413,   421,   429,   435,   435,   442,
     442,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "CHAR_LITERAL",
  "STRING_LITERAL", "NUM", "TYPE_INT", "TYPE_CHAR", "TYPE_REAL",
  "TYPE_BOOL", "TYPE_STRING", "TYPE_INT_PTR", "TYPE_CHAR_PTR",
  "TYPE_REAL_PTR", "DEF", "T_BEGIN", "T_END", "IF", "ELSE", "ELIF",
  "WHILE", "FOR", "DO", "CALL", "RETURN", "RETURNS", "VAR", "NULLPTR",
  "TRUE", "FALSE", "AND", "OR", "NOT", "EQ", "NE", "GT", "GE", "LT", "LE",
  "ASSIGN", "PLUS", "MINUS", "MULT", "DIV", "ADDRESS", "COLON",
  "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "BAR",
  "TYPE", "$accept", "program", "func_list", "function", "par_list",
  "param_list_item_list", "par_list_item", "type", "stmt_list", "stmt",
  "assignment", "var_stmt", "type_decls", "type_decl", "return_stmt",
  "if_stmt", "elif_list", "while_stmt", "do_while_stmt", "for_stmt",
  "call_args", "call_list", "assignment_call", "void_call", "block", "$@1",
  "$@2", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -78,     5,    17,   -11,   -78,   -39,   -78,   -78,     0,
     540,   -17,   -18,    -6,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,     6,   167,    11,    44,    46,   -34,   -78,
     -78,   -78,   -78,   348,   299,     7,    18,    62,   309,   540,
      24,   -78,   -78,   -78,   -78,   -78,   -78,   348,   348,   -11,
     268,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
      31,   -78,   -78,   -78,   502,   199,   -78,   -78,   358,   348,
     268,    63,    33,    80,   450,   348,   463,    82,    70,    38,
     -78,     1,   268,    13,   130,   -78,   388,   376,   -78,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     540,   268,    86,    85,    41,   236,   -78,    39,   268,   422,
     268,    53,   348,    73,   348,   -78,   268,    50,    51,    65,
     -78,   -78,   -78,   -78,   -78,   502,   -78,   -78,   -78,   -78,
     -78,   -78,    64,    64,   172,   172,   268,    60,   -78,   -78,
     -78,   348,    91,     3,   -78,   -78,   -78,   348,   436,   -78,
      66,   109,   112,   114,   268,   348,    81,    84,    92,   348,
       8,   348,    93,    15,    95,    96,    94,   -78,   268,    70,
     476,   101,   348,   405,   -78,   143,   -78,   -78,   -78,   117,
     -78,   -78,    70,    70,   489,   110,   118,   -78,   -78,   -78,
      70,   268,   -78,   -78,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     2,     5,     0,     1,     4,     0,
       0,     0,     0,    10,    13,    15,    16,    17,    18,    19,
      20,    21,    22,     0,    62,     0,     0,     0,    84,    85,
      86,    83,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,     0,     0,    36,
       9,    24,    25,    33,    27,    26,    29,    32,    30,    31,
      61,    35,    34,    28,    64,    62,    12,    14,     0,    62,
      62,     0,    84,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    62,     0,    62,    41,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,    70,     0,    62,     0,
      62,     0,     0,     0,    62,    46,     7,     0,     0,     0,
      39,    40,    28,    81,    82,    63,    75,    76,    78,    80,
      77,    79,    71,    72,    73,    74,    62,     0,    37,    94,
      68,    62,    50,    28,    55,    57,    28,     0,     0,    58,
       0,     0,     0,     0,     6,    62,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,    93,    62,     0,
       0,     0,     0,     0,    66,     0,    42,    43,    44,    93,
      51,    48,     0,     0,     0,     0,     0,    65,    53,    52,
       0,    62,    45,    54,    59,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   166,    10,   -78,   -78,   141,   -37,   -52,   -50,
      97,   -78,   -78,   102,   -78,   -78,   -78,    55,   -78,   -78,
     -60,   -78,   -78,   -78,   -77,   -78,   -78,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    49,     5,    12,    13,    14,    23,    50,    51,
      52,    53,    84,    85,    54,    55,   160,    56,    57,    58,
      59,    60,    61,    62,    63,    70,    71,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      88,   113,    82,    10,     2,     1,    68,   122,     6,   104,
       9,    74,    76,   101,     8,    69,    81,     7,   105,     2,
     117,   118,   158,   159,   119,    86,    87,   171,   172,    24,
     116,   143,    25,   146,   120,    90,    91,    92,    93,    94,
      95,    26,    96,    97,    98,    99,   103,    10,   115,    67,
      11,    88,    27,   109,   150,    88,    77,    65,   142,     8,
     145,   175,   176,   136,    78,    79,    88,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    83,    89,
     106,   156,    69,   107,   154,   111,    32,   114,   141,   137,
     148,   139,   181,   147,    34,   166,   151,   152,    90,    91,
      92,    93,    94,    95,    88,   188,   189,    98,    99,   155,
     157,   153,   163,   193,   195,   164,   162,   165,   180,    90,
      91,    92,    93,    94,    95,   103,    96,    97,    98,    99,
     168,   167,   138,    28,    29,    30,    31,   170,   169,   173,
     174,   194,   177,   178,   179,     2,    32,   183,    33,   186,
     184,    34,    35,    36,    37,    38,   191,    40,    41,    42,
      43,    44,    45,    46,   187,   192,     4,    66,   149,     0,
      28,    29,    30,    31,   112,     0,     0,     0,     0,    47,
       0,    48,     2,    32,    83,    33,   121,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    28,    29,    30,    31,    90,    91,    92,    93,
      94,    95,     0,     0,     2,    32,    47,    33,    48,     0,
      34,    35,    36,    37,    38,   100,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,     0,     0,     0,     0,     0,    47,     0,
      48,     2,    32,   140,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    40,    41,    42,    43,    44,    45,    46,
       0,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     2,    32,    47,    33,    48,     0,    34,
      35,    36,    37,    38,     0,    40,    41,    42,    43,    44,
      45,    46,    72,    29,    30,    31,     0,     0,     0,     0,
       0,     0,    72,    29,    30,    31,     0,    47,     0,    48,
       0,     0,     0,    73,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    73,     0,     0,     0,    41,    42,    43,
      44,    45,    46,     0,     0,    75,     0,     0,    47,     0,
      48,    72,    29,    30,    31,     0,    80,     0,    47,     0,
      48,    72,    29,    30,    31,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,    41,    42,    43,    44,
      45,    46,   102,     0,     0,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,     0,    47,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    48,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,    90,    91,    92,    93,    94,    95,   124,    96,
      97,    98,    99,     0,     0,     0,     0,     0,   123,    90,
      91,    92,    93,    94,    95,     0,    96,    97,    98,    99,
       0,     0,     0,     0,     0,   185,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,     0,   144,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,     0,   161,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,     0,   108,    90,    91,    92,
      93,    94,    95,     0,    96,    97,    98,    99,     0,   110,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,   182,    90,    91,    92,    93,    94,    95,     0,
      96,    97,    98,    99,     0,   190,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,    15,    16,    17,
      18,    19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
      50,    78,    39,     3,    15,     1,    40,    84,     3,    69,
      49,    33,    34,    65,     4,    49,    38,     0,    70,    15,
       7,     8,    19,    20,    11,    47,    48,    19,    20,    46,
      82,   108,    50,   110,    84,    34,    35,    36,    37,    38,
      39,    47,    41,    42,    43,    44,    68,     3,    47,     3,
      50,   101,    46,    75,   114,   105,    49,    46,   108,    49,
     110,    46,    47,   100,    46,     3,   116,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    54,    48,
      17,   141,    49,     3,   136,     3,    16,    49,    49,     3,
     112,    50,   169,    40,    21,   155,    46,    46,    34,    35,
      36,    37,    38,    39,   154,   182,   183,    43,    44,    49,
      19,    46,     3,   190,   191,     3,    50,     3,   168,    34,
      35,    36,    37,    38,    39,   147,    41,    42,    43,    44,
      46,    50,    47,     3,     4,     5,     6,   159,    46,   161,
      47,   191,    47,    47,    50,    15,    16,    46,    18,     6,
     172,    21,    22,    23,    24,    25,    46,    27,    28,    29,
      30,    31,    32,    33,    47,    47,     0,    26,   113,    -1,
       3,     4,     5,     6,    77,    -1,    -1,    -1,    -1,    49,
      -1,    51,    15,    16,    54,    18,    84,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,     3,     4,     5,     6,    34,    35,    36,    37,
      38,    39,    -1,    -1,    15,    16,    49,    18,    51,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    49,    18,    51,    -1,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    49,    -1,    51,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    46,    -1,    -1,    49,    -1,
      51,     3,     4,     5,     6,    -1,    47,    -1,    49,    -1,
      51,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    34,    35,    36,    37,    38,    39,    52,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    46,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    -1,    46,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    46,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    -1,    46,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,     7,     8,     9,
      10,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    15,    56,    57,    58,     3,     0,    58,    49,
       3,    50,    59,    60,    61,     7,     8,     9,    10,    11,
      12,    13,    14,    62,    46,    50,    47,    46,     3,     4,
       5,     6,    16,    18,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    49,    51,    57,
      63,    64,    65,    66,    69,    70,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    46,    61,     3,    40,    49,
      80,    81,     3,    24,    82,    46,    82,    49,    46,     3,
      47,    82,    62,    54,    67,    68,    82,    82,    64,    48,
      34,    35,    36,    37,    38,    39,    41,    42,    43,    44,
      26,    63,    24,    82,    75,    63,    17,     3,    46,    82,
      46,     3,    65,    79,    49,    47,    63,     7,     8,    11,
      64,    68,    79,    50,    52,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    62,     3,    47,    50,
      17,    49,    64,    79,    47,    64,    79,    40,    82,    72,
      75,    46,    46,    46,    63,    49,    75,    19,    19,    20,
      71,    47,    50,     3,     3,     3,    75,    50,    46,    46,
      82,    19,    20,    82,    47,    46,    47,    47,    47,    50,
      64,    79,    46,    46,    82,    50,     6,    47,    79,    79,
      46,    46,    47,    79,    64,    79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    72,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    80,    79,    81,
      79,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     9,     8,     7,     6,
       1,     0,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       2,     1,     5,     5,     5,     7,     3,     2,     7,     4,
       4,     7,     8,     4,     5,     4,     4,     4,     4,     9,
       9,     1,     0,     3,     1,     8,     6,     0,     4,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4
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
#line 57 "parser.y"
              {
        print_ast((yyvsp[0].ast), 0);
    }
#line 1368 "parser.tab.c"
    break;

  case 3: /* program: error  */
#line 60 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1376 "parser.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 66 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1382 "parser.tab.c"
    break;

  case 5: /* func_list: function  */
#line 67 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1388 "parser.tab.c"
    break;

  case 6: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type stmt_list  */
#line 70 "parser.y"
                                                               {
        printf(">> DEF FUNC: '%s' with params and return, scope=%d\n", (yyvsp[-7].sval), current_scope);
        if (strcmp((yyvsp[-7].sval), "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ((yyvsp[-5].ast)->child_count > 0 && strcmp((yyvsp[-5].ast)->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
    DataType return_type = get_type_from_name((yyvsp[-1].ast)->name);
    if (return_type != DT_VOID) {
        yyerror("Semantic Error: _main_ function cannot return a value");
    }
}
        if (symbol_exists_in_current_scope((yyvsp[-7].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-7].sval));
            yyerror(error_msg);
        } else {
            insert_symbol((yyvsp[-7].sval), FUNC_SYM, get_type_from_name((yyvsp[-1].ast)->name));
            printf("  Inserted '%s' as function in scope %d\n", (yyvsp[-7].sval), current_scope);
        }

        enter_scope();  // פתח scope חדש לגוף הפונקציה
        exit_scope();
            inside_main = 0;

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-7].sval), 0),
             (yyvsp[-5].ast),
             make_node("RET", 1, (yyvsp[-1].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1429 "parser.tab.c"
    break;

  case 7: /* function: DEF ID LPAREN RPAREN COLON RETURNS type stmt_list  */
#line 107 "parser.y"
                                                     {
        printf(">> DEF FUNC: '%s' no params, with return, scope=%d\n", (yyvsp[-6].sval), current_scope);
            if (strcmp((yyvsp[-6].sval), "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ((yyvsp[-1].ast)->child_count > 0 && strcmp((yyvsp[-1].ast)->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
    DataType return_type = get_type_from_name((yyvsp[-1].ast)->name);
    if (return_type != DT_VOID) {
        yyerror("Semantic Error: _main_ function cannot return a value");
    }
}
        if (symbol_exists_in_current_scope((yyvsp[-6].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-6].sval));
            yyerror(error_msg);
        } else {
            insert_symbol((yyvsp[-6].sval), FUNC_SYM, get_type_from_name((yyvsp[-1].ast)->name));
            printf("  Inserted '%s' as function in scope %d\n", (yyvsp[-6].sval), current_scope);
        }

        enter_scope();
        exit_scope();
            inside_main = 0;

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-6].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, (yyvsp[-1].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1470 "parser.tab.c"
    break;

  case 8: /* function: DEF ID LPAREN par_list RPAREN COLON stmt_list  */
#line 146 "parser.y"
                                                  {
        printf(">> DEF FUNC: '%s' with params, no return, scope=%d\n", (yyvsp[-5].sval), current_scope);
            if (strcmp((yyvsp[-5].sval), "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;

    if ((yyvsp[-3].ast)->child_count > 0 && strcmp((yyvsp[-3].ast)->children[0]->name, "NONE") != 0) {
        yyerror("Semantic Error: _main_ function cannot take arguments");
    }
}
        if (symbol_exists_in_current_scope((yyvsp[-5].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-5].sval));
            yyerror(error_msg);
        } else {
            insert_symbol((yyvsp[-5].sval), FUNC_SYM, DT_VOID);
            printf("  Inserted '%s' as function in scope %d\n", (yyvsp[-5].sval), current_scope);
        }

        enter_scope();
         exit_scope();
        inside_main = 0;

        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-5].sval), 0),
             (yyvsp[-3].ast),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
    }
#line 1507 "parser.tab.c"
    break;

  case 9: /* function: DEF ID LPAREN RPAREN COLON stmt_list  */
#line 181 "parser.y"
                                         {
        printf(">> DEF FUNC: '%s' no params, no return, scope=%d\n", (yyvsp[-4].sval), current_scope);
        if (strcmp((yyvsp[-4].sval), "_main_") == 0) {
    if (main_defined) {
        yyerror("Semantic Error: Multiple definitions of _main_ function");
    }
    main_defined = 1;
    inside_main = 1;
    
}
        if (symbol_exists_in_current_scope((yyvsp[-4].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-4].sval));
            yyerror(error_msg);
        } else {
            insert_symbol((yyvsp[-4].sval), FUNC_SYM, DT_VOID);
            printf("  Inserted '%s' as function in scope %d\n", (yyvsp[-4].sval), current_scope);
        }
        enter_scope();
        exit_scope();
        inside_main = 0;
        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-4].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));

    }
#line 1540 "parser.tab.c"
    break;

  case 10: /* par_list: param_list_item_list  */
#line 214 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1546 "parser.tab.c"
    break;

  case 11: /* par_list: %empty  */
#line 215 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1552 "parser.tab.c"
    break;

  case 12: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 219 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1560 "parser.tab.c"
    break;

  case 13: /* param_list_item_list: par_list_item  */
#line 222 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1568 "parser.tab.c"
    break;

  case 14: /* par_list_item: ID type COLON ID  */
#line 229 "parser.y"
                     {
        (yyval.ast) = make_node("", 3, make_node((yyvsp[-3].sval), 0), make_node((yyvsp[-2].ast)->name, 0), make_node((yyvsp[0].sval), 0));
    }
#line 1576 "parser.tab.c"
    break;

  case 15: /* type: TYPE_INT  */
#line 235 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1582 "parser.tab.c"
    break;

  case 16: /* type: TYPE_CHAR  */
#line 236 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1588 "parser.tab.c"
    break;

  case 17: /* type: TYPE_REAL  */
#line 237 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1594 "parser.tab.c"
    break;

  case 18: /* type: TYPE_BOOL  */
#line 238 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1600 "parser.tab.c"
    break;

  case 19: /* type: TYPE_STRING  */
#line 239 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1606 "parser.tab.c"
    break;

  case 20: /* type: TYPE_INT_PTR  */
#line 240 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1612 "parser.tab.c"
    break;

  case 21: /* type: TYPE_CHAR_PTR  */
#line 241 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1618 "parser.tab.c"
    break;

  case 22: /* type: TYPE_REAL_PTR  */
#line 242 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1624 "parser.tab.c"
    break;

  case 23: /* stmt_list: stmt_list stmt  */
#line 246 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 1633 "parser.tab.c"
    break;

  case 24: /* stmt_list: stmt  */
#line 250 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1642 "parser.tab.c"
    break;

  case 36: /* stmt: func_list  */
#line 268 "parser.y"
            { 
        printf("DEBUG: Processing function in stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1651 "parser.tab.c"
    break;

  case 37: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 275 "parser.y"
                             {
        if (symbol_exists_in_current_scope((yyvsp[-3].sval))) {
            char err[100];
            sprintf(err, "Semantic Error: Variable '%s' redefined in the same block", (yyvsp[-3].sval));
            yyerror(err);
        } else {
            insert_symbol((yyvsp[-3].sval), VAR_SYM, DT_INT);  // או הטיפוס שאתה מחלץ לפי ה־var
        }

        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 1667 "parser.tab.c"
    break;

  case 38: /* var_stmt: VAR type_decls block  */
#line 290 "parser.y"
                         {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1675 "parser.tab.c"
    break;

  case 39: /* var_stmt: VAR type_decls stmt  */
#line 293 "parser.y"
                        {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1683 "parser.tab.c"
    break;

  case 40: /* type_decls: type_decls type_decl  */
#line 298 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1691 "parser.tab.c"
    break;

  case 41: /* type_decls: type_decl  */
#line 301 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1699 "parser.tab.c"
    break;

  case 42: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 306 "parser.y"
                                     {
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1707 "parser.tab.c"
    break;

  case 43: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 309 "parser.y"
                                      {
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1715 "parser.tab.c"
    break;

  case 44: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 312 "parser.y"
                                        {
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1723 "parser.tab.c"
    break;

  case 45: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 315 "parser.y"
                                                {
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1,make_node((yyvsp[-1].sval),0)));
    }
#line 1731 "parser.tab.c"
    break;

  case 46: /* return_stmt: RETURN expr SEMICOLON  */
#line 324 "parser.y"
                          {
        printf("DEBUG: Processing return with value. inside_main=%d\n", inside_main);
        if (inside_main) {
            yyerror("Semantic Error: _main_ function cannot return a value");
        }
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 1743 "parser.tab.c"
    break;

  case 47: /* return_stmt: RETURN SEMICOLON  */
#line 331 "parser.y"
                     {
        printf("DEBUG: Processing empty return. inside_main=%d\n", inside_main);
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 1752 "parser.tab.c"
    break;

  case 48: /* if_stmt: IF expr COLON block ELSE COLON block  */
#line 339 "parser.y"
    {
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 1760 "parser.tab.c"
    break;

  case 49: /* if_stmt: IF expr COLON block  */
#line 343 "parser.y"
    {
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1768 "parser.tab.c"
    break;

  case 50: /* if_stmt: IF expr COLON stmt  */
#line 347 "parser.y"
    {
         (yyval.ast) =make_node("IF",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 1776 "parser.tab.c"
    break;

  case 51: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 351 "parser.y"
    {
         (yyval.ast) =make_node("IF-ELSE",3,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast));
    }
#line 1784 "parser.tab.c"
    break;

  case 52: /* if_stmt: IF expr COLON block elif_list ELSE COLON block  */
#line 355 "parser.y"
{
    (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
}
#line 1792 "parser.tab.c"
    break;

  case 53: /* elif_list: ELIF expr COLON block  */
#line 363 "parser.y"
        {
        (yyval.ast)=make_node("ELIF",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 1800 "parser.tab.c"
    break;

  case 54: /* elif_list: elif_list ELIF expr COLON block  */
#line 367 "parser.y"
    {
        (yyval.ast)=make_node("ELIF - ...",3,(yyvsp[-4].ast),make_node("elif",2,(yyvsp[-2].ast),(yyvsp[0].ast)));
    }
#line 1808 "parser.tab.c"
    break;

  case 55: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 373 "parser.y"
    {
        (yyval.ast)=make_node("while",1,(yyvsp[-1].ast));
    }
#line 1816 "parser.tab.c"
    break;

  case 56: /* while_stmt: WHILE expr COLON block  */
#line 377 "parser.y"
    {
        (yyval.ast)= make_node("while2",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 1824 "parser.tab.c"
    break;

  case 57: /* while_stmt: WHILE expr COLON stmt  */
#line 381 "parser.y"
    {
        (yyval.ast)= make_node("while2",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 1832 "parser.tab.c"
    break;

  case 58: /* do_while_stmt: DO COLON block while_stmt  */
#line 387 "parser.y"
    {
        (yyval.ast)=make_node("do", 1,(yyvsp[-1].ast),make_node("do while",1,(yyvsp[0].ast)));
    }
#line 1840 "parser.tab.c"
    break;

  case 59: /* for_stmt: FOR LPAREN assignment expr SEMICOLON expr RPAREN COLON stmt  */
#line 394 "parser.y"
    {
        (yyval.ast)=make_node("for", 4,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast));
    }
#line 1848 "parser.tab.c"
    break;

  case 60: /* for_stmt: FOR LPAREN assignment expr SEMICOLON expr RPAREN COLON block  */
#line 398 "parser.y"
    {
        (yyval.ast)=make_node("for", 4,(yyvsp[-6].ast),(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast));
    }
#line 1856 "parser.tab.c"
    break;

  case 61: /* call_args: call_list  */
#line 405 "parser.y"
              {(yyval.ast)=(yyvsp[0].ast);}
#line 1862 "parser.tab.c"
    break;

  case 62: /* call_args: %empty  */
#line 406 "parser.y"
               {(yyval.ast) =make_node("args", 1 ,make_node("none",0));}
#line 1868 "parser.tab.c"
    break;

  case 63: /* call_list: call_list COMMA expr  */
#line 410 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 1876 "parser.tab.c"
    break;

  case 64: /* call_list: expr  */
#line 414 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 1884 "parser.tab.c"
    break;

  case 65: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 421 "parser.y"
                                                        {
        (yyval.ast) = make_node("ASSIGN-CALL", 2,
                       make_node((yyvsp[-7].sval), 0),
                       make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast)));
    }
#line 1894 "parser.tab.c"
    break;

  case 66: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 429 "parser.y"
                                              {
        (yyval.ast) = make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast));
    }
#line 1902 "parser.tab.c"
    break;

  case 67: /* $@1: %empty  */
#line 435 "parser.y"
            {
        enter_scope();
    }
#line 1910 "parser.tab.c"
    break;

  case 68: /* block: T_BEGIN $@1 stmt_list T_END  */
#line 438 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
    }
#line 1919 "parser.tab.c"
    break;

  case 69: /* $@2: %empty  */
#line 442 "parser.y"
                 {
        enter_scope();
    }
#line 1927 "parser.tab.c"
    break;

  case 70: /* block: T_BEGIN $@2 T_END  */
#line 445 "parser.y"
           {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
     }
#line 1936 "parser.tab.c"
    break;

  case 71: /* expr: expr PLUS expr  */
#line 453 "parser.y"
                     { (yyval.ast) = make_node("+", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1942 "parser.tab.c"
    break;

  case 72: /* expr: expr MINUS expr  */
#line 454 "parser.y"
                     { (yyval.ast) = make_node("-", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1948 "parser.tab.c"
    break;

  case 73: /* expr: expr MULT expr  */
#line 455 "parser.y"
                     { (yyval.ast) = make_node("*", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1954 "parser.tab.c"
    break;

  case 74: /* expr: expr DIV expr  */
#line 456 "parser.y"
                     { (yyval.ast) = make_node("/", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1960 "parser.tab.c"
    break;

  case 75: /* expr: expr EQ expr  */
#line 457 "parser.y"
                     { (yyval.ast) = make_node("==", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1966 "parser.tab.c"
    break;

  case 76: /* expr: expr NE expr  */
#line 458 "parser.y"
                     { (yyval.ast) = make_node("!=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1972 "parser.tab.c"
    break;

  case 77: /* expr: expr LT expr  */
#line 459 "parser.y"
                     { (yyval.ast) = make_node("<", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1978 "parser.tab.c"
    break;

  case 78: /* expr: expr GT expr  */
#line 460 "parser.y"
                     { (yyval.ast) = make_node(">", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1984 "parser.tab.c"
    break;

  case 79: /* expr: expr LE expr  */
#line 461 "parser.y"
                     { (yyval.ast) = make_node("<=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1990 "parser.tab.c"
    break;

  case 80: /* expr: expr GE expr  */
#line 462 "parser.y"
                     { (yyval.ast) = make_node(">=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1996 "parser.tab.c"
    break;

  case 81: /* expr: LPAREN expr RPAREN  */
#line 463 "parser.y"
                       { (yyval.ast) = (yyvsp[-1].ast); }
#line 2002 "parser.tab.c"
    break;

  case 82: /* expr: LBRACK expr RBRACK  */
#line 464 "parser.y"
                      {(yyval.ast)=(yyvsp[-1].ast);}
#line 2008 "parser.tab.c"
    break;

  case 83: /* expr: NUM  */
#line 465 "parser.y"
                    { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2014 "parser.tab.c"
    break;

  case 84: /* expr: ID  */
#line 466 "parser.y"
                    { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2020 "parser.tab.c"
    break;

  case 85: /* expr: CHAR_LITERAL  */
#line 467 "parser.y"
                      { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2026 "parser.tab.c"
    break;

  case 86: /* expr: STRING_LITERAL  */
#line 468 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2032 "parser.tab.c"
    break;

  case 87: /* expr: NULLPTR  */
#line 469 "parser.y"
           { (yyval.ast) = make_node("nullptr", 0); }
#line 2038 "parser.tab.c"
    break;

  case 88: /* expr: TRUE  */
#line 470 "parser.y"
        { (yyval.ast) = make_node("true", 0); }
#line 2044 "parser.tab.c"
    break;

  case 89: /* expr: FALSE  */
#line 471 "parser.y"
         { (yyval.ast) = make_node("false", 0); }
#line 2050 "parser.tab.c"
    break;

  case 90: /* expr: AND  */
#line 472 "parser.y"
       { (yyval.ast) = make_node("and", 0); }
#line 2056 "parser.tab.c"
    break;

  case 91: /* expr: OR  */
#line 473 "parser.y"
      { (yyval.ast) = make_node("or", 0); }
#line 2062 "parser.tab.c"
    break;

  case 92: /* expr: NOT  */
#line 474 "parser.y"
       { (yyval.ast) = make_node("not", 0); }
#line 2068 "parser.tab.c"
    break;

  case 93: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 475 "parser.y"
                                   { (yyval.ast) = make_node("call", 2,make_node((yyvsp[-3].sval),0),(yyvsp[-1].ast)); }
#line 2074 "parser.tab.c"
    break;

  case 94: /* expr: ID LPAREN call_args RPAREN  */
#line 476 "parser.y"
                               { (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast)); }
#line 2080 "parser.tab.c"
    break;


#line 2084 "parser.tab.c"

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

#line 479 "parser.y"


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
