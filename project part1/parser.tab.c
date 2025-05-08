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

#line 94 "parser.tab.c"

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
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_par_list = 63,                  /* par_list  */
  YYSYMBOL_param_list_item_list = 64,      /* param_list_item_list  */
  YYSYMBOL_par_list_item = 65,             /* par_list_item  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_stmt_list = 67,                 /* stmt_list  */
  YYSYMBOL_stmt = 68,                      /* stmt  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_var_stmt = 70,                  /* var_stmt  */
  YYSYMBOL_type_decls = 71,                /* type_decls  */
  YYSYMBOL_type_decl = 72,                 /* type_decl  */
  YYSYMBOL_return_stmt = 73,               /* return_stmt  */
  YYSYMBOL_if_stmt = 74,                   /* if_stmt  */
  YYSYMBOL_elif_list = 75,                 /* elif_list  */
  YYSYMBOL_while_stmt = 76,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 77,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 78,                  /* for_stmt  */
  YYSYMBOL_update_expr = 79,               /* update_expr  */
  YYSYMBOL_call_args = 80,                 /* call_args  */
  YYSYMBOL_call_list = 81,                 /* call_list  */
  YYSYMBOL_assignment_call = 82,           /* assignment_call  */
  YYSYMBOL_void_call = 83,                 /* void_call  */
  YYSYMBOL_block = 84,                     /* block  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_expr = 87                       /* expr  */
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
#define YYLAST   720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

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
       0,    53,    53,    56,    62,    63,    66,    66,   108,   108,
     144,   144,   179,   179,   212,   213,   217,   220,   227,   237,
     238,   239,   240,   241,   242,   243,   244,   248,   252,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   274,   285,   288,   293,   296,   301,   305,   309,   313,
     317,   321,   325,   329,   333,   337,   345,   356,   367,   372,
     377,   382,   387,   396,   401,   408,   413,   418,   425,   430,
     435,   442,   447,   454,   457,   462,   463,   467,   471,   479,
     509,   537,   537,   544,   544,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   596,   608,
     609,   610
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
  "func_list", "function", "$@1", "$@2", "$@3", "$@4", "par_list",
  "param_list_item_list", "par_list_item", "type", "stmt_list", "stmt",
  "assignment", "var_stmt", "type_decls", "type_decl", "return_stmt",
  "if_stmt", "elif_list", "while_stmt", "do_while_stmt", "for_stmt",
  "update_expr", "call_args", "call_list", "assignment_call", "void_call",
  "block", "$@5", "$@6", "expr", YY_NULLPTR
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
       8,   -78,    -5,    17,    29,   -78,    14,   -78,   -78,   -15,
     457,    31,     0,    41,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,    54,    75,    71,   102,   105,   457,   229,
      82,   -78,   -78,   -78,   -78,   -78,   657,   -31,   -78,   -78,
     -78,   -78,   -78,   -78,   320,    76,    77,    83,   108,   311,
      74,   -78,   320,   320,    29,   229,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,    87,   -78,   -78,   -78,   706,
     457,   229,   229,    90,   115,   -78,   361,   320,   229,   104,
     581,   320,   625,   124,   229,    92,   -78,   443,    60,   139,
     -78,   419,    99,   -78,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   -78,   229,   229,
      95,   129,   488,    97,   188,   -78,   229,   500,   229,   109,
     320,   270,   113,   126,   320,   -78,   117,   119,   120,   121,
     122,   -78,   -78,   -78,   -78,   -78,   706,    20,   453,   203,
     203,   185,   185,   -78,   -78,   -78,   -78,   -78,   -78,   229,
     320,   125,   -78,   -78,   -78,   137,   -14,   -78,   -78,   -78,
     320,   512,    76,   320,   320,   123,   164,   167,   168,   169,
     170,   229,   151,   320,   143,   156,   320,     2,   370,   431,
     557,   569,   175,     1,     7,   176,    10,    15,   -78,   179,
     229,   204,   637,   190,   320,    -4,   184,   706,   -78,   -78,
     -78,   -78,   219,   -78,   223,   -78,   -78,    78,   -78,   224,
     -78,   194,   -78,   -78,   204,   204,   649,   320,   197,   205,
     206,   207,   208,   209,   -78,   -78,   -78,   204,   706,   229,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     2,     5,     0,     1,     4,     0,
       0,     0,     0,    14,    17,    19,    20,    21,    22,    23,
      24,    25,    26,     0,    12,     0,     0,     0,     0,    76,
      10,    16,    18,     8,   105,   104,   106,    98,    99,   100,
      97,   102,   103,    81,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,    40,    13,    28,    29,    37,    31,
      30,    33,    36,    34,    35,    75,    39,    38,    32,    78,
       0,    76,    76,    98,     0,   111,     0,    76,    76,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,    76,
      45,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    11,     9,
       0,     0,     0,     0,     0,    84,    76,     0,    76,     0,
       0,     0,    28,    32,    76,    56,     0,     0,     0,     0,
       0,    43,    44,    32,    95,    96,    77,   110,   109,    85,
      86,    87,    88,    89,    90,    92,    94,    91,    93,    76,
      76,     0,    41,   108,    82,    60,    32,    65,    67,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,   107,     0,
      76,     0,     0,     0,     0,    98,     0,    74,    68,    69,
      70,    80,     0,    46,     0,    48,    50,     0,    47,     0,
      49,   107,    61,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    63,    62,     0,    73,    76,
      51,    52,    54,    55,    53,    64,    72,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   251,     4,   -78,   -78,   -78,   -78,   -78,   -78,
     231,   -26,   -68,   -29,   178,   -78,   -78,   174,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -72,   -78,   -78,   -78,   -77,
     -78,   -78,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    54,     5,   149,    72,    71,    29,    12,    13,
      14,    23,    55,    93,    57,    58,    89,    90,    59,    60,
     177,    61,    62,    63,   196,    64,    65,    66,    67,    68,
      78,    79,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    10,    33,   108,   109,   113,    75,   123,     8,     1,
     114,     6,   133,    76,    80,    82,   121,     7,    77,    87,
     175,   176,    91,    92,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    11,   193,   194,     2,   156,
     217,   159,    56,    56,   107,    77,   112,   202,   203,    56,
      25,   117,   165,   204,   205,   122,   207,   208,     8,     2,
     131,   209,   210,     9,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    24,   172,    34,
      35,   171,   126,   127,   128,   129,   130,   155,    26,   158,
     161,    36,    73,    38,    39,    40,    41,    42,   221,   222,
      27,   189,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   213,    74,    28,    30,    10,    51,
      56,    32,    81,    70,    85,    52,    83,    53,    88,    84,
     112,   110,   179,   180,   181,    94,   115,   225,   226,    77,
     119,   124,    34,    35,   150,   151,   192,   153,   197,   163,
     235,   135,   237,   160,    36,    37,    38,    39,    40,    41,
      42,   212,   164,   166,   216,   167,   168,   169,   170,     2,
      43,   174,    44,   182,   173,    45,    46,    47,    48,    49,
     183,    50,    51,   184,   185,   186,   187,   228,    52,   190,
      53,    34,    35,    88,   101,   102,   103,   104,   105,   106,
     236,   188,   191,    36,    37,    38,    39,    40,    41,    42,
      99,   100,   101,   102,   103,   104,   105,   106,     2,    43,
     154,    44,   201,   206,    45,    46,    47,    48,    49,   211,
      50,    51,    34,    35,   218,    43,   215,    52,   219,    53,
     220,   224,   223,   229,    36,    37,    38,    39,    40,    41,
      42,     4,   230,   231,   232,   233,   234,    31,     0,     2,
      43,   120,    44,   132,     0,    45,    46,    47,    48,    49,
       0,    50,    51,    34,    35,     0,     0,     0,    52,     0,
      53,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    43,     0,    44,     0,     0,   162,    46,    47,    48,
      49,     0,    50,    51,    34,    35,     0,     0,     0,    52,
       0,    53,     0,    34,    35,     0,    36,    73,    38,    39,
      40,    41,    42,     0,     0,    36,    73,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,    51,     0,     0,     0,    86,    74,
      52,     0,    53,    51,    34,    35,     0,     0,     0,    52,
       0,    53,     0,    34,    35,     0,    36,    73,    38,    39,
      40,    41,    42,     0,     0,    36,   195,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,    51,     0,     0,     0,     0,    74,
      52,     0,    53,    51,     0,     0,     0,     0,     0,    52,
       0,    53,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   134,
       0,     0,     0,     0,     0,     0,     0,   118,   198,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
     125,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   178,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   118,    36,    73,    38,    39,    40,    41,    42,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,    74,     0,     0,     0,
      51,     0,     0,     0,     0,     0,    52,     0,    53,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106
};

static const yytype_int16 yycheck[] =
{
      29,    16,    28,    71,    72,    77,    36,    84,     4,     1,
      78,    16,    89,    44,    44,    45,    84,     0,    49,    49,
      34,    35,    52,    53,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    50,    34,    35,    30,   116,
      44,   118,    71,    72,    70,    49,    76,    46,    47,    78,
      50,    81,   124,    46,    47,    84,    46,    47,    54,    30,
      89,    46,    47,    49,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    46,   150,     3,
       4,   149,    22,    23,    24,    25,    26,   116,    47,   118,
     120,    15,    16,    17,    18,    19,    20,    21,    20,    21,
      46,   173,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   191,    39,    41,    46,    16,    43,
     149,    16,    46,    41,    16,    49,    49,    51,    54,    46,
     160,    16,   162,   163,   164,    48,    32,   214,   215,    49,
      16,    49,     3,     4,    49,    16,   176,    50,   178,    36,
     227,    52,   229,    44,    15,    16,    17,    18,    19,    20,
      21,   190,    36,    46,   194,    46,    46,    46,    46,    30,
      31,    34,    33,    50,    49,    36,    37,    38,    39,    40,
      16,    42,    43,    16,    16,    16,    16,   217,    49,    46,
      51,     3,     4,    54,     9,    10,    11,    12,    13,    14,
     229,    50,    46,    15,    16,    17,    18,    19,    20,    21,
       7,     8,     9,    10,    11,    12,    13,    14,    30,    31,
      32,    33,    47,    47,    36,    37,    38,    39,    40,    50,
      42,    43,     3,     4,    50,    31,    46,    49,    19,    51,
      17,    47,    18,    46,    15,    16,    17,    18,    19,    20,
      21,     0,    47,    47,    47,    47,    47,    26,    -1,    30,
      31,    83,    33,    89,    -1,    36,    37,    38,    39,    40,
      -1,    42,    43,     3,     4,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    42,    43,     3,     4,    -1,    -1,    -1,    49,
      -1,    51,    -1,     3,     4,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    39,
      49,    -1,    51,    43,     3,     4,    -1,    -1,    -1,    49,
      -1,    51,    -1,     3,     4,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    39,
      49,    -1,    51,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      47,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    39,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    30,    56,    57,    58,    16,     0,    58,    49,
      16,    50,    63,    64,    65,    22,    23,    24,    25,    26,
      27,    28,    29,    66,    46,    50,    47,    46,    41,    62,
      46,    65,    16,    66,     3,     4,    15,    16,    17,    18,
      19,    20,    21,    31,    33,    36,    37,    38,    39,    40,
      42,    43,    49,    51,    57,    67,    68,    69,    70,    73,
      74,    76,    77,    78,    80,    81,    82,    83,    84,    87,
      41,    61,    60,    16,    39,    87,    44,    49,    85,    86,
      87,    46,    87,    49,    46,    16,    47,    87,    54,    71,
      72,    87,    87,    68,    48,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    66,    67,    67,
      16,    39,    87,    80,    67,    32,    46,    87,    46,    16,
      69,    67,    68,    84,    49,    47,    22,    23,    24,    25,
      26,    68,    72,    84,    50,    52,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    59,
      49,    16,    47,    50,    32,    68,    84,    47,    68,    84,
      44,    87,    36,    36,    36,    80,    46,    46,    46,    46,
      46,    67,    80,    49,    34,    34,    35,    75,    47,    87,
      87,    87,    50,    16,    16,    16,    16,    16,    50,    80,
      46,    46,    87,    34,    35,    16,    79,    87,    47,    47,
      47,    47,    46,    47,    46,    47,    47,    46,    47,    46,
      47,    50,    68,    84,    46,    46,    87,    44,    50,    19,
      17,    20,    21,    18,    47,    84,    84,    46,    87,    46,
      47,    47,    47,    47,    47,    84,    68,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    59,    58,    60,    58,
      61,    58,    62,    58,    63,    63,    64,    64,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      83,    85,    84,    86,    84,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     0,    10,     0,     9,
       0,     8,     0,     7,     1,     0,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     2,     1,     5,     5,     5,     5,
       5,     7,     7,     7,     7,     7,     3,     2,     7,     4,
       4,     7,     8,     4,     5,     4,     4,     4,     6,     6,
       6,     9,     9,     3,     1,     1,     0,     3,     1,     8,
       6,     0,     4,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     3,
       3,     2
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
#line 53 "parser.y"
              {
        print_ast((yyvsp[0].ast), 0);
    }
#line 1425 "parser.tab.c"
    break;

  case 3: /* program: error  */
#line 56 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1433 "parser.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 62 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1439 "parser.tab.c"
    break;

  case 5: /* func_list: function  */
#line 63 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1445 "parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 66 "parser.y"
                                                     {
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
        // In each function declaration rule
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
        // Add this check in the function declaration rule actions
        if (get_type_from_name((yyvsp[0].ast)->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
    }
#line 1482 "parser.tab.c"
    break;

  case 7: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type $@1 stmt_list  */
#line 97 "parser.y"
                {
        inside_main = 0;
        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-8].sval), 0),
             (yyvsp[-6].ast),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }
#line 1497 "parser.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 108 "parser.y"
                                            {
        if (symbol_exists_in_current_scope((yyvsp[-5].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-5].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  // במקרה זה, אין פרמטרים
            insert_function_with_param_types((yyvsp[-5].sval), get_type_from_name((yyvsp[0].ast)->name), 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-5].sval), current_scope);
        }
        // In each function declaration rule
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
    }
#line 1528 "parser.tab.c"
    break;

  case 9: /* function: DEF ID LPAREN RPAREN COLON RETURNS type $@2 stmt_list  */
#line 133 "parser.y"
                {
        inside_main = 0;
        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-7].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, (yyvsp[-2].ast)),
             make_node("BODY", 1, (yyvsp[0].ast)));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }
#line 1543 "parser.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 144 "parser.y"
                                        {
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
        // In each function declaration rule
        strcpy(current_function_name, (yyvsp[-4].sval));

        if (strcmp((yyvsp[-4].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ((yyvsp[-2].ast)->child_count > 0 && strcmp((yyvsp[-2].ast)->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");
        }
    }
#line 1573 "parser.tab.c"
    break;

  case 11: /* function: DEF ID LPAREN par_list RPAREN COLON $@3 stmt_list  */
#line 168 "parser.y"
                {
        inside_main = 0;
        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-6].sval), 0),
             (yyvsp[-4].ast),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));
             // At the end of each function rule, after creating the AST node
current_function_name[0] = '\0';  // Clear the current function name
    }
#line 1588 "parser.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 179 "parser.y"
                               {
        if (symbol_exists_in_current_scope((yyvsp[-3].sval))) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", (yyvsp[-3].sval));
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  // במקרה זה, אין פרמטרים
            insert_function_with_param_types((yyvsp[-3].sval), DT_VOID, 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", (yyvsp[-3].sval), current_scope);
        }
        // In each function declaration rule
    strcpy(current_function_name, (yyvsp[-3].sval));

        if (strcmp((yyvsp[-3].sval), "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;
        }
    }
#line 1613 "parser.tab.c"
    break;

  case 13: /* function: DEF ID LPAREN RPAREN COLON $@4 stmt_list  */
#line 198 "parser.y"
                {
        inside_main = 0;
        (yyval.ast) = make_node("FUNCTION", 4,
             make_node((yyvsp[-5].sval), 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, (yyvsp[0].ast)));

             // At the end of each function rule, after creating the AST node
        current_function_name[0] = '\0';  // Clear the current function name
    }
#line 1629 "parser.tab.c"
    break;

  case 14: /* par_list: param_list_item_list  */
#line 212 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1635 "parser.tab.c"
    break;

  case 15: /* par_list: %empty  */
#line 213 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1641 "parser.tab.c"
    break;

  case 16: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 217 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1649 "parser.tab.c"
    break;

  case 17: /* param_list_item_list: par_list_item  */
#line 220 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1657 "parser.tab.c"
    break;

  case 18: /* par_list_item: ID type COLON ID  */
#line 227 "parser.y"
                     {
        // טיפוס הפרמטר הוא get_type_from_name($2->name)
        insert_symbol((yyvsp[0].sval), VAR_SYM, get_type_from_name((yyvsp[-2].ast)->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", (yyvsp[0].sval), current_scope);
        
        (yyval.ast) = make_node("", 3, make_node((yyvsp[-3].sval), 0), make_node((yyvsp[-2].ast)->name, 0), make_node((yyvsp[0].sval), 0));
    }
#line 1669 "parser.tab.c"
    break;

  case 19: /* type: TYPE_INT  */
#line 237 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1675 "parser.tab.c"
    break;

  case 20: /* type: TYPE_CHAR  */
#line 238 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1681 "parser.tab.c"
    break;

  case 21: /* type: TYPE_REAL  */
#line 239 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1687 "parser.tab.c"
    break;

  case 22: /* type: TYPE_BOOL  */
#line 240 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1693 "parser.tab.c"
    break;

  case 23: /* type: TYPE_STRING  */
#line 241 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1699 "parser.tab.c"
    break;

  case 24: /* type: TYPE_INT_PTR  */
#line 242 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1705 "parser.tab.c"
    break;

  case 25: /* type: TYPE_CHAR_PTR  */
#line 243 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1711 "parser.tab.c"
    break;

  case 26: /* type: TYPE_REAL_PTR  */
#line 244 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1717 "parser.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt  */
#line 248 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 1726 "parser.tab.c"
    break;

  case 28: /* stmt_list: stmt  */
#line 252 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1735 "parser.tab.c"
    break;

  case 41: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 274 "parser.y"
                             {
        Symbol* sym = lookup_any_scope((yyvsp[-3].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-3].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast));
    }
#line 1749 "parser.tab.c"
    break;

  case 42: /* var_stmt: VAR type_decls block  */
#line 285 "parser.y"
                         {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1757 "parser.tab.c"
    break;

  case 43: /* var_stmt: VAR type_decls stmt  */
#line 288 "parser.y"
                        {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1765 "parser.tab.c"
    break;

  case 44: /* type_decls: type_decls type_decl  */
#line 293 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 1773 "parser.tab.c"
    break;

  case 45: /* type_decls: type_decl  */
#line 296 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1781 "parser.tab.c"
    break;

  case 46: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 301 "parser.y"
                                     {
        insert_checked_variable((yyvsp[-1].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1790 "parser.tab.c"
    break;

  case 47: /* type_decl: TYPE TYPE_BOOL COLON ID SEMICOLON  */
#line 305 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1799 "parser.tab.c"
    break;

  case 48: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 309 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1808 "parser.tab.c"
    break;

  case 49: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 313 "parser.y"
                                        {
        insert_checked_variable((yyvsp[-1].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1817 "parser.tab.c"
    break;

  case 50: /* type_decl: TYPE TYPE_REAL COLON ID SEMICOLON  */
#line 317 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 1826 "parser.tab.c"
    break;

  case 51: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 321 "parser.y"
                                               {
        insert_checked_variable((yyvsp[-3].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 1835 "parser.tab.c"
    break;

  case 52: /* type_decl: TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON  */
#line 325 "parser.y"
                                                         {
        insert_checked_variable((yyvsp[-3].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 1844 "parser.tab.c"
    break;

  case 53: /* type_decl: TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON  */
#line 329 "parser.y"
                                                             {
        insert_checked_variable((yyvsp[-3].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 1853 "parser.tab.c"
    break;

  case 54: /* type_decl: TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON  */
#line 333 "parser.y"
                                                 {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("true", 0)));
    }
#line 1862 "parser.tab.c"
    break;

  case 55: /* type_decl: TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON  */
#line 337 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("false", 0)));
    }
#line 1871 "parser.tab.c"
    break;

  case 56: /* return_stmt: RETURN expr SEMICOLON  */
#line 345 "parser.y"
                          {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);
        if (inside_main) {
            yyerror("Semantic Error: _main_ function cannot return a value");
        }
        
        // Check if return type matches function declaration
        check_return_type((yyvsp[-1].ast), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 1887 "parser.tab.c"
    break;

  case 57: /* return_stmt: RETURN SEMICOLON  */
#line 356 "parser.y"
                     {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        // Empty return is equivalent to "return void"
        check_return_type(make_node("NONE", 0), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 1900 "parser.tab.c"
    break;

  case 58: /* if_stmt: IF expr COLON block ELSE COLON block  */
#line 368 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 1909 "parser.tab.c"
    break;

  case 59: /* if_stmt: IF expr COLON block  */
#line 373 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1918 "parser.tab.c"
    break;

  case 60: /* if_stmt: IF expr COLON stmt  */
#line 378 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1927 "parser.tab.c"
    break;

  case 61: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 383 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 1936 "parser.tab.c"
    break;

  case 62: /* if_stmt: IF expr COLON block elif_list ELSE COLON block  */
#line 388 "parser.y"
    {
        check_boolean_condition((yyvsp[-6].ast), "if");
        (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 1945 "parser.tab.c"
    break;

  case 63: /* elif_list: ELIF expr COLON block  */
#line 397 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1954 "parser.tab.c"
    break;

  case 64: /* elif_list: elif_list ELIF expr COLON block  */
#line 402 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF - ...", 3, (yyvsp[-4].ast), make_node("elif", 2, (yyvsp[-2].ast), (yyvsp[0].ast)));
    }
#line 1963 "parser.tab.c"
    break;

  case 65: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 409 "parser.y"
    {
        check_boolean_condition((yyvsp[-1].ast), "while");
        (yyval.ast) = make_node("while", 1, (yyvsp[-1].ast));
    }
#line 1972 "parser.tab.c"
    break;

  case 66: /* while_stmt: WHILE expr COLON block  */
#line 414 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1981 "parser.tab.c"
    break;

  case 67: /* while_stmt: WHILE expr COLON stmt  */
#line 419 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1990 "parser.tab.c"
    break;

  case 68: /* do_while_stmt: DO COLON stmt_list WHILE expr SEMICOLON  */
#line 425 "parser.y"
                                            {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 1999 "parser.tab.c"
    break;

  case 69: /* do_while_stmt: DO COLON stmt WHILE expr SEMICOLON  */
#line 430 "parser.y"
                                       {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2008 "parser.tab.c"
    break;

  case 70: /* do_while_stmt: DO COLON block WHILE expr SEMICOLON  */
#line 435 "parser.y"
                                        {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2017 "parser.tab.c"
    break;

  case 71: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block  */
#line 442 "parser.y"
                                                                        {
        check_boolean_condition((yyvsp[-5].ast), "for"); // Check the loop condition expression is boolean
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2026 "parser.tab.c"
    break;

  case 72: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt  */
#line 447 "parser.y"
                                                                       {
        check_boolean_condition((yyvsp[-5].ast), "for"); // Check the loop condition expression is boolean
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2035 "parser.tab.c"
    break;

  case 73: /* update_expr: ID ASSIGN expr  */
#line 454 "parser.y"
                   {
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-2].sval), 0), (yyvsp[0].ast));
    }
#line 2043 "parser.tab.c"
    break;

  case 74: /* update_expr: expr  */
#line 457 "parser.y"
           {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2051 "parser.tab.c"
    break;

  case 75: /* call_args: call_list  */
#line 462 "parser.y"
              { (yyval.ast) = make_node("args", 1, (yyvsp[0].ast)); }
#line 2057 "parser.tab.c"
    break;

  case 76: /* call_args: %empty  */
#line 463 "parser.y"
                { (yyval.ast) = make_node("args", 1, make_node("none", 0)); }
#line 2063 "parser.tab.c"
    break;

  case 77: /* call_list: call_list COMMA expr  */
#line 468 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2071 "parser.tab.c"
    break;

  case 78: /* call_list: expr  */
#line 472 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 2079 "parser.tab.c"
    break;

  case 79: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 479 "parser.y"
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
                // בדיקת טיפוסי פרמטרים
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("ASSIGN-CALL", 2,
                       make_node((yyvsp[-7].sval), 0),
                       make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast)));
    }
#line 2111 "parser.tab.c"
    break;

  case 80: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 509 "parser.y"
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
                // בדיקת טיפוסי פרמטרים
                check_param_types((yyvsp[-4].sval), (yyvsp[-2].ast));
            }
        }

        (yyval.ast) = make_node("CALL", 2, make_node((yyvsp[-4].sval), 0), (yyvsp[-2].ast));
    }
#line 2141 "parser.tab.c"
    break;

  case 81: /* $@5: %empty  */
#line 537 "parser.y"
            {
        enter_scope();
    }
#line 2149 "parser.tab.c"
    break;

  case 82: /* block: T_BEGIN $@5 stmt_list T_END  */
#line 540 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
    }
#line 2158 "parser.tab.c"
    break;

  case 83: /* $@6: %empty  */
#line 544 "parser.y"
                 {
        enter_scope();
    }
#line 2166 "parser.tab.c"
    break;

  case 84: /* block: T_BEGIN $@6 T_END  */
#line 547 "parser.y"
           {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
     }
#line 2175 "parser.tab.c"
    break;

  case 85: /* expr: expr PLUS expr  */
#line 554 "parser.y"
                     { (yyval.ast) = make_node("+", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2181 "parser.tab.c"
    break;

  case 86: /* expr: expr MINUS expr  */
#line 555 "parser.y"
                     { (yyval.ast) = make_node("-", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2187 "parser.tab.c"
    break;

  case 87: /* expr: expr MULT expr  */
#line 556 "parser.y"
                     { (yyval.ast) = make_node("*", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2193 "parser.tab.c"
    break;

  case 88: /* expr: expr DIV expr  */
#line 557 "parser.y"
                     { (yyval.ast) = make_node("/", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2199 "parser.tab.c"
    break;

  case 89: /* expr: expr EQ expr  */
#line 558 "parser.y"
                     { (yyval.ast) = make_node("==", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2205 "parser.tab.c"
    break;

  case 90: /* expr: expr NE expr  */
#line 559 "parser.y"
                     { (yyval.ast) = make_node("!=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2211 "parser.tab.c"
    break;

  case 91: /* expr: expr LT expr  */
#line 560 "parser.y"
                     { (yyval.ast) = make_node("<", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2217 "parser.tab.c"
    break;

  case 92: /* expr: expr GT expr  */
#line 561 "parser.y"
                     { (yyval.ast) = make_node(">", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2223 "parser.tab.c"
    break;

  case 93: /* expr: expr LE expr  */
#line 562 "parser.y"
                     { (yyval.ast) = make_node("<=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2229 "parser.tab.c"
    break;

  case 94: /* expr: expr GE expr  */
#line 563 "parser.y"
                     { (yyval.ast) = make_node(">=", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2235 "parser.tab.c"
    break;

  case 95: /* expr: LPAREN expr RPAREN  */
#line 564 "parser.y"
                       { (yyval.ast) = (yyvsp[-1].ast); }
#line 2241 "parser.tab.c"
    break;

  case 96: /* expr: LBRACK expr RBRACK  */
#line 565 "parser.y"
                      {(yyval.ast)=(yyvsp[-1].ast);}
#line 2247 "parser.tab.c"
    break;

  case 97: /* expr: NUM  */
#line 566 "parser.y"
                    { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2253 "parser.tab.c"
    break;

  case 98: /* expr: ID  */
#line 567 "parser.y"
       {
        Symbol* sym = lookup_any_scope((yyvsp[0].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node((yyvsp[0].sval), 0);
    }
#line 2267 "parser.tab.c"
    break;

  case 99: /* expr: CHAR_LITERAL  */
#line 576 "parser.y"
                      { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2273 "parser.tab.c"
    break;

  case 100: /* expr: STRING_LITERAL  */
#line 577 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2279 "parser.tab.c"
    break;

  case 101: /* expr: NULLPTR  */
#line 578 "parser.y"
           { (yyval.ast) = make_node("nullptr", 0); }
#line 2285 "parser.tab.c"
    break;

  case 102: /* expr: TRUE  */
#line 579 "parser.y"
        { (yyval.ast) = make_node("true", 0); }
#line 2291 "parser.tab.c"
    break;

  case 103: /* expr: FALSE  */
#line 580 "parser.y"
         { (yyval.ast) = make_node("false", 0); }
#line 2297 "parser.tab.c"
    break;

  case 104: /* expr: AND  */
#line 581 "parser.y"
       { (yyval.ast) = make_node("and", 0); }
#line 2303 "parser.tab.c"
    break;

  case 105: /* expr: OR  */
#line 582 "parser.y"
      { (yyval.ast) = make_node("or", 0); }
#line 2309 "parser.tab.c"
    break;

  case 106: /* expr: NOT  */
#line 583 "parser.y"
       { (yyval.ast) = make_node("not", 0); }
#line 2315 "parser.tab.c"
    break;

  case 107: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 584 "parser.y"
                                    { 
        Symbol* func = lookup_any_scope((yyvsp[-3].sval));
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-1].ast));
            if (expected == actual) {
                // בדיקת טיפוסי פרמטרים
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast)); 
    }
#line 2332 "parser.tab.c"
    break;

  case 108: /* expr: ID LPAREN call_args RPAREN  */
#line 596 "parser.y"
                                 { 
        Symbol* func = lookup_any_scope((yyvsp[-3].sval));
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params((yyvsp[-1].ast));
            if (expected == actual) {
                // בדיקת טיפוסי פרמטרים
                check_param_types((yyvsp[-3].sval), (yyvsp[-1].ast));
            }
        }
        (yyval.ast) = make_node("call", 2, make_node((yyvsp[-3].sval), 0), (yyvsp[-1].ast)); 
    }
#line 2349 "parser.tab.c"
    break;

  case 109: /* expr: expr AND expr  */
#line 608 "parser.y"
                    { (yyval.ast) = make_node("and", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2355 "parser.tab.c"
    break;

  case 110: /* expr: expr OR expr  */
#line 609 "parser.y"
                   { (yyval.ast) = make_node("or", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2361 "parser.tab.c"
    break;

  case 111: /* expr: NOT expr  */
#line 610 "parser.y"
               { (yyval.ast) = make_node("not", 1, (yyvsp[0].ast)); }
#line 2367 "parser.tab.c"
    break;


#line 2371 "parser.tab.c"

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

#line 613 "parser.y"


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
