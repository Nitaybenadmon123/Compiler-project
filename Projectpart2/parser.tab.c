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
    char current_function_name[256] = "";
    int current_param_index = 0;

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
#define YYLAST   1356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  358

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
       0,    55,    55,    58,    64,    65,    68,    69,    70,    71,
      74,    79,    80,    83,    83,   130,   130,   171,   171,   212,
     212,   250,   251,   255,   258,   265,   280,   281,   282,   283,
     284,   285,   286,   287,   291,   295,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   316,   343,   367,
     396,   403,   404,   409,   409,   415,   415,   425,   430,   437,
     440,   445,   449,   453,   457,   461,   465,   469,   473,   477,
     481,   485,   489,   499,   503,   507,   512,   516,   520,   524,
     528,   532,   536,   540,   553,   557,   561,   565,   569,   576,
     579,   586,   587,   588,   589,   590,   595,   603,   613,   618,
     623,   628,   633,   641,   646,   653,   658,   663,   670,   675,
     680,   687,   692,   699,   702,   707,   708,   712,   716,   724,
     753,   780,   783,   788,   788,   796,   796,   807,   818,   829,
     840,   851,   862,   873,   884,   895,   906,   917,   919,   936,
     943,   944,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   972,  1000,  1001,  1002,  1004,  1036,  1059
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

#define YYPACT_NINF (-287)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,  -287,    18,    42,    19,  -287,    46,  -287,  -287,    -7,
     108,    67,    89,   101,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,   105,   114,   118,   191,   193,   108,   -10,
     160,  -287,  -287,  -287,   310,   231,  -287,   108,   -10,   -10,
    -287,  -287,   932,   157,   -22,  -287,  -287,  -287,  -287,  -287,
     353,  -287,   975,   876,   240,   247,   296,   925,  -287,  -287,
     299,   975,   975,   396,  -287,   439,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,   275,  -287,  -287,  -287,  1322,
     354,   -17,  -287,  -287,  -287,  -287,   975,   -21,   308,   329,
     270,     7,  -287,   982,   975,   975,  -287,   482,  1251,   975,
    1266,     9,   783,   302,  -287,  1092,   231,   231,    -6,  1044,
     181,  -287,   525,  -287,  -287,   975,   975,   975,   975,   975,
     975,   975,   975,   975,   975,   975,   975,   975,   312,   321,
     341,   342,     1,   348,   351,   355,   568,  -287,   -10,   975,
     975,   305,   324,   389,  1104,   356,   214,  -287,   826,  1119,
     783,   391,    -5,   392,   975,   869,   373,   374,   975,  -287,
     -13,   107,   975,   975,  -287,  -287,  -287,  1322,  1136,   949,
     325,   325,   270,   270,  -287,  -287,  -287,  -287,  -287,  -287,
     402,   403,   404,   405,  -287,   406,    39,   407,   408,   409,
    -287,   611,  -287,  1149,   234,   975,   379,  -287,  -287,   386,
     353,   397,    29,  -287,  -287,  -287,   393,   975,   975,   400,
    1164,   876,   975,   975,   390,   654,  -287,  -287,  1176,   264,
      56,    24,    61,    95,   106,   112,   116,   120,   132,   135,
     150,   156,    54,   164,   432,   430,   414,   167,   415,   182,
     416,   184,  -287,  -287,  -287,   401,   975,   975,   783,   418,
     419,   420,   975,   253,   292,  1025,  1074,  1194,  1221,   417,
    -287,   697,  -287,  -287,    98,  -287,  -287,  -287,   436,   238,
    -287,  -287,  -287,   244,  -287,  -287,  -287,   290,  -287,  -287,
    -287,   301,  -287,   434,  -287,  -287,   421,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,   424,  1239,   740,  -287,   783,   437,
    1295,   423,   975,   386,    45,   433,  1322,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,   440,  -287,  -287,  -287,   445,   446,
    -287,   447,   448,   449,   457,   428,   458,   459,  -287,  -287,
    -287,  -287,  -287,   461,   437,  1310,   975,   462,  -287,   345,
    -287,  -287,  -287,  -287,  -287,   460,  -287,  -287,  -287,  -287,
     461,  1322,   783,  -287,  -287,  -287,  -287,  -287
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
     148,   147,     0,   149,   141,   142,   143,   140,   145,   146,
       0,     8,     0,     0,     0,     0,     0,     0,    53,   144,
       0,     0,     0,   116,    12,     0,    35,    36,    44,    38,
      37,    40,    43,    41,    42,   115,    46,    45,    39,   118,
       0,     0,    60,    13,    18,    16,     0,   141,     0,     0,
     155,   141,   154,     0,   116,     0,   122,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,   156,     0,
       0,    11,     0,     6,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,   156,     0,     0,     0,     0,   121,   116,     0,
     116,     0,     0,     0,     0,     0,    35,    39,   116,    96,
       0,   116,     0,     0,   137,   139,     7,   117,   153,   152,
     127,   128,   129,   130,   131,   132,   134,   136,   133,   135,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      10,     0,    14,     0,     0,   116,     0,    47,   151,   138,
       0,   100,    99,   105,   107,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    56,     0,     0,
      51,     0,     0,    51,     0,     0,    51,     0,     0,    51,
       0,     0,     0,     0,     0,     0,    51,     0,    51,     0,
      51,     0,     9,    49,   138,     0,   116,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
      58,     0,    50,   157,     0,    61,    76,    85,     0,     0,
      63,    78,    86,     0,    65,    79,    88,     0,    62,    77,
      84,     0,    64,     0,    87,    52,     0,    73,    80,    74,
      81,    75,    82,   150,     0,     0,     0,   126,   116,     0,
       0,     0,     0,     0,   141,     0,   114,   108,   109,   110,
     120,    57,    94,    95,    91,    92,    93,    89,     0,    94,
      91,    91,    92,    93,    95,     0,     0,   150,    48,   124,
     101,   123,    98,     0,     0,     0,     0,     0,    67,     0,
      68,    66,    70,    71,    69,     0,    83,   119,   103,   102,
       0,   113,   116,    90,    72,   104,   112,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -287,  -287,  -287,   -31,  -287,     2,  -287,  -287,  -287,  -287,
    -287,  -287,   441,    -4,   -32,   -62,   410,  -121,  -287,  -287,
    -287,  -287,   185,   -69,    68,   170,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,   -89,  -287,  -287,  -287,   -98,  -286,  -287,
    -287,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    36,    63,     5,   138,    39,    38,    29,
      12,    13,    14,    23,    97,    66,    67,   186,    68,   106,
     107,   216,    81,    82,   222,   317,    69,    70,   253,    71,
      72,    73,   305,    74,    75,    76,    77,    78,   202,   248,
     249,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    92,    65,   114,   157,   145,     8,    84,    85,    10,
      98,   100,   137,   332,   136,   105,   151,   184,   215,   109,
     110,    34,    93,   139,    33,   152,     1,    94,    94,    95,
     140,   112,    35,    83,     6,   114,    64,    80,   162,   207,
     156,    80,     7,    11,    90,   163,   208,   185,   349,     2,
     114,   144,   205,   146,   153,     2,    94,   149,   140,   221,
     224,   227,   230,   251,   252,   111,   237,   239,   241,   214,
     155,   266,   234,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   201,   234,   204,   336,
     235,   137,   137,   114,    94,     9,   140,   193,   194,   217,
     281,   282,   264,   265,   191,   283,   245,   192,   267,   268,
      40,    41,   210,    24,    42,   312,   313,   314,   315,   316,
     218,   219,    43,    44,    45,    46,    47,    48,    49,   114,
      15,    16,    17,    18,    19,    20,    21,    22,    50,    25,
      52,   269,   270,    53,    54,    55,    56,    57,    26,    58,
      59,    27,    60,   271,   234,    28,    61,   294,    62,   272,
     268,    80,   273,   274,    30,   144,   254,   275,   234,   256,
     257,   258,    43,    91,    45,    46,    47,    48,    49,   276,
     268,   277,   278,   261,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    88,   279,   234,   114,
      59,    37,    89,   280,   268,   295,    61,    10,    62,    32,
     300,   284,   268,   306,   288,   234,   296,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   290,
     234,   292,   234,   165,   114,   348,   330,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   225,
     228,   231,   355,   233,   357,   319,   313,   320,   315,   316,
     335,   312,   313,   321,   315,   316,   199,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   122,
     123,   124,   125,   126,   127,    80,   244,   301,   302,   101,
     356,   160,   161,   102,   351,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   312,   313,   320,
     322,   323,   103,    40,    41,   108,   263,    42,   312,   324,
     320,   315,   316,   115,   141,    43,    44,    45,    46,    47,
      48,    49,   120,   121,   122,   123,   124,   125,   126,   127,
       2,    50,    51,    52,   303,   142,    53,    54,    55,    56,
      57,   158,    58,    59,   195,    60,    40,    41,   180,    61,
      42,    62,   312,   313,   320,   315,   316,   181,    43,    44,
      45,    46,    47,    48,    49,   163,   128,   129,   130,   131,
     132,   133,   134,   135,    50,    96,    52,   182,   183,    53,
      54,    55,    56,    57,   187,    58,    59,   188,    60,    40,
      41,   189,    61,    42,    62,   196,   198,   206,   209,   212,
     213,    43,    44,    45,    46,    47,    48,    49,   220,   223,
     226,   229,   232,   236,   238,   240,     2,    50,   246,    52,
     247,   250,    53,    54,    55,    56,    57,   139,    58,    59,
     259,    60,    40,    41,   162,    61,    42,    62,   285,   286,
     297,   293,   318,   325,    43,    44,    45,    46,    47,    48,
      49,   287,   289,   291,   310,   298,   299,    31,   331,   334,
      50,   113,    52,   326,   327,    53,    54,    55,    56,    57,
     345,    58,    59,   337,    60,    40,    41,   338,    61,    42,
      62,   339,    50,   340,   341,   342,   343,    43,    44,    45,
      46,    47,    48,    49,   344,   346,   347,   354,   352,   353,
       0,   154,     0,    50,   147,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,     0,    60,    40,    41,
       0,    61,    42,    62,     0,     0,     0,     0,     0,     0,
      43,    44,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,   166,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,     0,
      60,    40,    41,     0,    61,    42,    62,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
     190,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,     0,    60,    40,    41,     0,    61,    42,    62,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,   242,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,     0,    60,    40,    41,     0,
      61,    42,    62,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,   260,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,     0,    60,
      40,    41,     0,    61,    42,    62,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,   311,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,     0,    60,    40,    41,     0,    61,    42,    62,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,   329,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,     0,    60,    40,    41,     0,    61,
      42,    62,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46,    47,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    52,     0,     0,    53,
      54,    55,    56,    57,     0,    58,    59,     0,    60,    40,
      41,     0,    61,    42,    62,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
       0,    60,    40,    41,     0,    61,    42,    62,     0,    40,
      41,     0,     0,    86,    43,    44,    45,    46,    47,    48,
      49,    43,    91,    45,    46,    47,    48,    49,     0,     0,
      50,     0,    52,     0,     0,   211,    54,    55,    56,    57,
       0,    58,    59,     0,    60,    88,     0,     0,    61,    59,
      62,    89,    99,     0,     0,    61,     0,    62,    40,    41,
       0,     0,    86,     0,     0,    40,    41,     0,     0,    86,
      43,    91,    45,    46,    47,    48,    49,    43,    87,    45,
      46,    47,    48,    49,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    88,     0,     0,     0,    59,     0,
      89,    88,   104,     0,    61,    59,    62,    89,    40,    41,
       0,    61,    86,    62,     0,    40,    41,     0,     0,    86,
      43,    91,    45,    46,    47,    48,    49,    43,    91,    45,
      46,    47,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,    59,     0,
      89,   143,     0,     0,    61,    59,    62,    89,    40,    41,
       0,    61,    86,    62,     0,     0,     0,     0,     0,     0,
      43,   304,    45,    46,    47,    48,    49,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,    88,     0,     0,     0,    59,     0,
      89,     0,     0,     0,    61,     0,    62,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,   164,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     150,   307,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,   159,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   197,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,   203,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,   243,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,   308,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,   309,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,   328,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,     0,   150,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   350
};

static const yytype_int16 yycheck[] =
{
      42,    43,    34,    65,   102,    94,     4,    38,    39,    16,
      52,    53,    81,   299,    31,    57,     7,    16,    31,    61,
      62,    31,    44,    44,    28,    16,     1,    49,    49,    51,
      51,    63,    42,    37,    16,    97,    34,    54,    44,    44,
     102,    54,     0,    50,    86,    51,    51,    46,   334,    30,
     112,    93,   150,    95,    45,    30,    49,    99,    51,   180,
     181,   182,   183,    34,    35,    63,   187,   188,   189,   158,
     102,    47,    48,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   148,    48,   150,    44,
      51,   160,   161,   155,    49,    49,    51,   139,   140,   161,
      46,    47,    46,    47,   136,    51,   195,   138,    47,    48,
       3,     4,   154,    46,     7,    17,    18,    19,    20,    21,
     162,   163,    15,    16,    17,    18,    19,    20,    21,   191,
      22,    23,    24,    25,    26,    27,    28,    29,    31,    50,
      33,    46,    47,    36,    37,    38,    39,    40,    47,    42,
      43,    46,    45,    47,    48,    41,    49,   246,    51,    47,
      48,    54,    46,    47,    46,   207,   208,    47,    48,   211,
     212,   213,    15,    16,    17,    18,    19,    20,    21,    47,
      48,    46,    47,   215,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    39,    47,    48,   261,
      43,    41,    45,    47,    48,   247,    49,    16,    51,    16,
     252,    47,    48,   255,    47,    48,   248,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    47,
      48,    47,    48,    52,   296,   333,   298,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   181,
     182,   183,   350,   185,   352,    17,    18,    19,    20,    21,
     302,    17,    18,    19,    20,    21,    52,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     9,
      10,    11,    12,    13,    14,    54,    52,    34,    35,    49,
     352,   106,   107,    46,   336,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    17,    18,    19,
      20,    21,    16,     3,     4,    16,    52,     7,    17,    18,
      19,    20,    21,    48,    16,    15,    16,    17,    18,    19,
      20,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      30,    31,    32,    33,    52,    16,    36,    37,    38,    39,
      40,    49,    42,    43,    49,    45,     3,     4,    46,    49,
       7,    51,    17,    18,    19,    20,    21,    46,    15,    16,
      17,    18,    19,    20,    21,    51,    22,    23,    24,    25,
      26,    27,    28,    29,    31,    32,    33,    46,    46,    36,
      37,    38,    39,    40,    46,    42,    43,    46,    45,     3,
       4,    46,    49,     7,    51,    16,    50,    16,    16,    36,
      36,    15,    16,    17,    18,    19,    20,    21,    16,    16,
      16,    16,    16,    16,    16,    16,    30,    31,    49,    33,
      44,    34,    36,    37,    38,    39,    40,    44,    42,    43,
      50,    45,     3,     4,    44,    49,     7,    51,    16,    19,
      32,    50,    16,    19,    15,    16,    17,    18,    19,    20,
      21,    47,    47,    47,    47,    46,    46,    26,    31,    46,
      31,    32,    33,    52,    50,    36,    37,    38,    39,    40,
      52,    42,    43,    50,    45,     3,     4,    47,    49,     7,
      51,    46,    31,    47,    47,    47,    47,    15,    16,    17,
      18,    19,    20,    21,    47,    47,    47,    47,    46,   339,
      -1,   101,    -1,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    42,    43,    -1,    45,     3,     4,
      -1,    49,     7,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    42,    43,    -1,
      45,     3,     4,    -1,    49,     7,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      42,    43,    -1,    45,     3,     4,    -1,    49,     7,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    -1,    45,     3,     4,    -1,
      49,     7,    51,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
       3,     4,    -1,    49,     7,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39,    40,    -1,    42,
      43,    -1,    45,     3,     4,    -1,    49,     7,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    42,    43,    -1,    45,     3,     4,    -1,    49,
       7,    51,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    45,     3,
       4,    -1,    49,     7,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      -1,    45,     3,     4,    -1,    49,     7,    51,    -1,     3,
       4,    -1,    -1,     7,    15,    16,    17,    18,    19,    20,
      21,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      31,    -1,    33,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    42,    43,    -1,    45,    39,    -1,    -1,    49,    43,
      51,    45,    46,    -1,    -1,    49,    -1,    51,     3,     4,
      -1,    -1,     7,    -1,    -1,     3,     4,    -1,    -1,     7,
      15,    16,    17,    18,    19,    20,    21,    15,    16,    17,
      18,    19,    20,    21,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    39,    -1,    -1,    -1,    43,    -1,
      45,    39,    47,    -1,    49,    43,    51,    45,     3,     4,
      -1,    49,     7,    51,    -1,     3,     4,    -1,    -1,     7,
      15,    16,    17,    18,    19,    20,    21,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    39,    -1,    -1,    49,    43,    51,    45,     3,     4,
      -1,    49,     7,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    49,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    50,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      46,    47,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    47,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    47,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    47,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    46,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46
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
      96,    16,    96,    44,    49,    51,    32,    69,    96,    46,
      96,    49,    46,    16,    47,    96,    74,    75,    16,    96,
      96,    60,    69,    32,    70,    48,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    22,    23,
      24,    25,    26,    27,    28,    29,    31,    78,    61,    44,
      51,    16,    16,    39,    96,    88,    96,    32,    46,    96,
      46,     7,    16,    45,    71,    69,    70,    92,    49,    47,
      77,    77,    44,    51,    50,    52,    32,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      46,    46,    46,    46,    16,    46,    72,    46,    46,    46,
      32,    69,    58,    96,    96,    49,    16,    47,    50,    52,
      31,    70,    93,    47,    70,    92,    16,    44,    51,    16,
      96,    36,    36,    36,    88,    31,    76,    70,    96,    96,
      16,    72,    79,    16,    72,    79,    16,    72,    79,    16,
      72,    79,    16,    79,    48,    51,    16,    72,    16,    72,
      16,    72,    32,    47,    52,    88,    49,    44,    94,    95,
      34,    34,    35,    83,    96,    47,    96,    96,    96,    50,
      32,    69,    47,    52,    46,    47,    47,    47,    48,    46,
      47,    47,    47,    46,    47,    47,    47,    46,    47,    47,
      47,    46,    47,    51,    47,    16,    19,    47,    47,    47,
      47,    47,    47,    50,    88,    96,    69,    32,    46,    46,
      96,    34,    35,    52,    16,    87,    96,    47,    47,    47,
      47,    32,    17,    18,    19,    20,    21,    80,    16,    17,
      19,    19,    20,    21,    18,    19,    52,    50,    47,    32,
      70,    31,    93,    46,    46,    96,    44,    50,    47,    46,
      47,    47,    47,    47,    47,    52,    47,    47,    92,    93,
      46,    96,    46,    80,    47,    92,    70,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    61,    60,    62,    60,    63,    60,    64,
      60,    65,    65,    66,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    74,    73,    75,    73,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      91,    92,    92,    94,    93,    95,    93,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     4,     2,     5,
       4,     2,     1,     0,    10,     0,     9,     0,     8,     0,
       7,     1,     0,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     5,
       5,     1,     3,     0,     4,     0,     4,     3,     2,     2,
       1,     5,     5,     5,     5,     5,     7,     7,     7,     7,
       7,     7,     8,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     7,     5,     5,     5,     5,     5,     3,
       5,     1,     1,     1,     1,     1,     3,     2,     7,     4,
       4,     7,     8,     4,     5,     4,     4,     4,     6,     6,
       6,     9,     9,     3,     1,     1,     0,     3,     1,     8,
       6,     3,     2,     0,     4,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     3,     3,     2,     2,     2,     5
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
#line 55 "parser.y"
              {
        print_ast((yyvsp[0].ast), 0);
    }
#line 1612 "parser.tab.c"
    break;

  case 3: /* program: error  */
#line 58 "parser.y"
          {
        yyerror("Could not parse input");
    }
#line 1620 "parser.tab.c"
    break;

  case 4: /* func_list: func_list function  */
#line 64 "parser.y"
                       { (yyval.ast) = make_node("CODE", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1626 "parser.tab.c"
    break;

  case 5: /* func_list: function  */
#line 65 "parser.y"
             { (yyval.ast) = make_node("CODE", 1, (yyvsp[0].ast)); }
#line 1632 "parser.tab.c"
    break;

  case 6: /* function_body: T_BEGIN stmt_list T_END  */
#line 68 "parser.y"
                            { (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); }
#line 1638 "parser.tab.c"
    break;

  case 7: /* function_body: T_BEGIN nested_func_list stmt_list T_END  */
#line 69 "parser.y"
                                             { (yyval.ast) = make_node("BLOCK", 2, (yyvsp[-2].ast), (yyvsp[-1].ast)); }
#line 1644 "parser.tab.c"
    break;

  case 8: /* function_body: T_BEGIN T_END  */
#line 70 "parser.y"
                  { (yyval.ast) = make_node("BLOCK", 0); }
#line 1650 "parser.tab.c"
    break;

  case 9: /* function_body: VAR type_decls T_BEGIN stmt_list T_END  */
#line 71 "parser.y"
                                            { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-3].ast), make_node("BLOCK", 1, (yyvsp[-1].ast))); 
    }
#line 1658 "parser.tab.c"
    break;

  case 10: /* function_body: VAR type_decls T_BEGIN T_END  */
#line 74 "parser.y"
                                 { 
        (yyval.ast) = make_node("VAR_BLOCK", 2, (yyvsp[-2].ast), make_node("BLOCK", 0)); 
    }
#line 1666 "parser.tab.c"
    break;

  case 11: /* nested_func_list: nested_func_list function  */
#line 79 "parser.y"
                              { (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 1672 "parser.tab.c"
    break;

  case 12: /* nested_func_list: function  */
#line 80 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1678 "parser.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 83 "parser.y"
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
#line 1717 "parser.tab.c"
    break;

  case 14: /* function: DEF ID LPAREN par_list RPAREN COLON RETURNS type $@1 function_body  */
#line 116 "parser.y"
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
#line 1735 "parser.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 130 "parser.y"
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
#line 1768 "parser.tab.c"
    break;

  case 16: /* function: DEF ID LPAREN RPAREN COLON RETURNS type $@2 function_body  */
#line 157 "parser.y"
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
#line 1786 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 171 "parser.y"
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
#line 1819 "parser.tab.c"
    break;

  case 18: /* function: DEF ID LPAREN par_list RPAREN COLON $@3 function_body  */
#line 198 "parser.y"
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
#line 1837 "parser.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 212 "parser.y"
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
#line 1864 "parser.tab.c"
    break;

  case 20: /* function: DEF ID LPAREN RPAREN COLON $@4 function_body  */
#line 233 "parser.y"
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
#line 1883 "parser.tab.c"
    break;

  case 21: /* par_list: param_list_item_list  */
#line 250 "parser.y"
                         { (yyval.ast) = make_node("ARGS", 1, (yyvsp[0].ast)); }
#line 1889 "parser.tab.c"
    break;

  case 22: /* par_list: %empty  */
#line 251 "parser.y"
                { (yyval.ast) = make_node("ARGS", 1, make_node("NONE", 0)); }
#line 1895 "parser.tab.c"
    break;

  case 23: /* param_list_item_list: param_list_item_list SEMICOLON par_list_item  */
#line 255 "parser.y"
                                                 {
        (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1903 "parser.tab.c"
    break;

  case 24: /* param_list_item_list: par_list_item  */
#line 258 "parser.y"
                  {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1911 "parser.tab.c"
    break;

  case 25: /* par_list_item: ID type COLON ID  */
#line 265 "parser.y"
                     {
        current_param_index++;
        
        check_param_order((yyvsp[-3].sval), current_param_index);
        
        insert_symbol((yyvsp[0].sval), VAR_SYM, get_type_from_name((yyvsp[-2].ast)->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", (yyvsp[0].sval), current_scope);
        
    
              (yyval.ast) = make_node((yyvsp[-3].sval), 2,
          make_node((yyvsp[-2].ast)->name, 0),
            make_node((yyvsp[0].sval),      0));
    }
#line 1929 "parser.tab.c"
    break;

  case 26: /* type: TYPE_INT  */
#line 280 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1935 "parser.tab.c"
    break;

  case 27: /* type: TYPE_CHAR  */
#line 281 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1941 "parser.tab.c"
    break;

  case 28: /* type: TYPE_REAL  */
#line 282 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1947 "parser.tab.c"
    break;

  case 29: /* type: TYPE_BOOL  */
#line 283 "parser.y"
               { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1953 "parser.tab.c"
    break;

  case 30: /* type: TYPE_STRING  */
#line 284 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1959 "parser.tab.c"
    break;

  case 31: /* type: TYPE_INT_PTR  */
#line 285 "parser.y"
                 { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1965 "parser.tab.c"
    break;

  case 32: /* type: TYPE_CHAR_PTR  */
#line 286 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1971 "parser.tab.c"
    break;

  case 33: /* type: TYPE_REAL_PTR  */
#line 287 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 1977 "parser.tab.c"
    break;

  case 34: /* stmt_list: stmt_list stmt  */
#line 291 "parser.y"
                   { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = make_node("", 2, (yyvsp[-1].ast), (yyvsp[0].ast)); 
    }
#line 1986 "parser.tab.c"
    break;

  case 35: /* stmt_list: stmt  */
#line 295 "parser.y"
           { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        (yyval.ast) = (yyvsp[0].ast); 
    }
#line 1995 "parser.tab.c"
    break;

  case 47: /* assignment: ID ASSIGN expr SEMICOLON  */
#line 316 "parser.y"
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
#line 2027 "parser.tab.c"
    break;

  case 48: /* assignment: ID LBRACK expr RBRACK ASSIGN expr SEMICOLON  */
#line 343 "parser.y"
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
#line 2056 "parser.tab.c"
    break;

  case 49: /* assignment: MULT ID ASSIGN expr SEMICOLON  */
#line 367 "parser.y"
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
#line 2090 "parser.tab.c"
    break;

  case 50: /* assignment: ADDRESS ID ASSIGN expr SEMICOLON  */
#line 396 "parser.y"
                                       {
        yyerror("Semantic Error: Cannot use address operator on left side of assignment");
        (yyval.ast) = make_node("error", 2, make_node("&", 1, make_node((yyvsp[-3].sval), 0)), (yyvsp[-1].ast));
   }
#line 2099 "parser.tab.c"
    break;

  case 51: /* id_list: ID  */
#line 403 "parser.y"
                                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2105 "parser.tab.c"
    break;

  case 52: /* id_list: id_list COMMA ID  */
#line 404 "parser.y"
                               { (yyval.ast) = make_node("", 2, (yyvsp[-2].ast), make_node((yyvsp[0].sval), 0)); }
#line 2111 "parser.tab.c"
    break;

  case 53: /* $@5: %empty  */
#line 409 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2120 "parser.tab.c"
    break;

  case 54: /* var_stmt: VAR $@5 type_decls block_content  */
#line 412 "parser.y"
                               {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2128 "parser.tab.c"
    break;

  case 55: /* $@6: %empty  */
#line 415 "parser.y"
        {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    }
#line 2137 "parser.tab.c"
    break;

  case 56: /* var_stmt: VAR $@6 type_decls stmt  */
#line 418 "parser.y"
                      {
        (yyval.ast) = make_node("VAR", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
        exit_scope();
        printf("DEBUG: Exited VAR scope\n");
    }
#line 2147 "parser.tab.c"
    break;

  case 57: /* block_content: T_BEGIN stmt_list T_END  */
#line 425 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from block_content\n");
    }
#line 2157 "parser.tab.c"
    break;

  case 58: /* block_content: T_BEGIN T_END  */
#line 430 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from empty block_content\n");
    }
#line 2167 "parser.tab.c"
    break;

  case 59: /* type_decls: type_decls type_decl  */
#line 437 "parser.y"
                         {
        (yyval.ast) = make_node("DECLS", 2, (yyvsp[-1].ast), (yyvsp[0].ast));
    }
#line 2175 "parser.tab.c"
    break;

  case 60: /* type_decls: type_decl  */
#line 440 "parser.y"
              {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2183 "parser.tab.c"
    break;

  case 61: /* type_decl: TYPE TYPE_INT COLON ID SEMICOLON  */
#line 445 "parser.y"
                                     {
        insert_checked_variable((yyvsp[-1].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2192 "parser.tab.c"
    break;

  case 62: /* type_decl: TYPE TYPE_BOOL COLON ID SEMICOLON  */
#line 449 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2201 "parser.tab.c"
    break;

  case 63: /* type_decl: TYPE TYPE_CHAR COLON ID SEMICOLON  */
#line 453 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2210 "parser.tab.c"
    break;

  case 64: /* type_decl: TYPE TYPE_STRING COLON ID SEMICOLON  */
#line 457 "parser.y"
                                        {
        insert_checked_variable((yyvsp[-1].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2219 "parser.tab.c"
    break;

  case 65: /* type_decl: TYPE TYPE_REAL COLON ID SEMICOLON  */
#line 461 "parser.y"
                                      {
        insert_checked_variable((yyvsp[-1].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2228 "parser.tab.c"
    break;

  case 66: /* type_decl: TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON  */
#line 465 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real", 0), make_node((yyvsp[-3].sval), 1,make_node((yyvsp[-1].sval),0)));
    }
#line 2237 "parser.tab.c"
    break;

  case 67: /* type_decl: TYPE TYPE_INT COLON ID COLON NUM SEMICOLON  */
#line 469 "parser.y"
                                               {
        insert_checked_variable((yyvsp[-3].sval), DT_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2246 "parser.tab.c"
    break;

  case 68: /* type_decl: TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON  */
#line 473 "parser.y"
                                                         {
        insert_checked_variable((yyvsp[-3].sval), DT_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2255 "parser.tab.c"
    break;

  case 69: /* type_decl: TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON  */
#line 477 "parser.y"
                                                             {
        insert_checked_variable((yyvsp[-3].sval), DT_STRING);
        (yyval.ast) = make_node("TYPE", 2, make_node("string", 0), make_node((yyvsp[-3].sval), 1, make_node((yyvsp[-1].sval), 0)));
    }
#line 2264 "parser.tab.c"
    break;

  case 70: /* type_decl: TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON  */
#line 481 "parser.y"
                                                 {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("true", 0)));
    }
#line 2273 "parser.tab.c"
    break;

  case 71: /* type_decl: TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON  */
#line 485 "parser.y"
                                                  {
        insert_checked_variable((yyvsp[-3].sval), DT_BOOL);
        (yyval.ast) = make_node("TYPE", 2, make_node("bool", 0), make_node((yyvsp[-3].sval), 1, make_node("false", 0)));
    }
#line 2282 "parser.tab.c"
    break;

  case 72: /* type_decl: TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON  */
#line 489 "parser.y"
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
#line 2297 "parser.tab.c"
    break;

  case 73: /* type_decl: TYPE TYPE_INT_PTR COLON ID SEMICOLON  */
#line 499 "parser.y"
                                           {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE", 2, make_node("int*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2306 "parser.tab.c"
    break;

  case 74: /* type_decl: TYPE TYPE_CHAR_PTR COLON ID SEMICOLON  */
#line 503 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE", 2, make_node("char*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2315 "parser.tab.c"
    break;

  case 75: /* type_decl: TYPE TYPE_REAL_PTR COLON ID SEMICOLON  */
#line 507 "parser.y"
                                          {
        insert_checked_variable((yyvsp[-1].sval), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE", 2, make_node("real*", 0), make_node((yyvsp[-1].sval), 0));
    }
#line 2324 "parser.tab.c"
    break;

  case 76: /* type_decl: TYPE TYPE_INT COLON id_list SEMICOLON  */
#line 512 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int", 0), (yyvsp[-1].ast));
    }
#line 2333 "parser.tab.c"
    break;

  case 77: /* type_decl: TYPE TYPE_BOOL COLON id_list SEMICOLON  */
#line 516 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_BOOL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("bool", 0), (yyvsp[-1].ast));
    }
#line 2342 "parser.tab.c"
    break;

  case 78: /* type_decl: TYPE TYPE_CHAR COLON id_list SEMICOLON  */
#line 520 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char", 0), (yyvsp[-1].ast));
    }
#line 2351 "parser.tab.c"
    break;

  case 79: /* type_decl: TYPE TYPE_REAL COLON id_list SEMICOLON  */
#line 524 "parser.y"
                                           {
        add_multiple_variables((yyvsp[-1].ast), DT_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real", 0), (yyvsp[-1].ast));
    }
#line 2360 "parser.tab.c"
    break;

  case 80: /* type_decl: TYPE TYPE_INT_PTR COLON id_list SEMICOLON  */
#line 528 "parser.y"
                                              {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_INT);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("int*", 0), (yyvsp[-1].ast));
    }
#line 2369 "parser.tab.c"
    break;

  case 81: /* type_decl: TYPE TYPE_CHAR_PTR COLON id_list SEMICOLON  */
#line 532 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_CHAR);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("char*", 0), (yyvsp[-1].ast));
    }
#line 2378 "parser.tab.c"
    break;

  case 82: /* type_decl: TYPE TYPE_REAL_PTR COLON id_list SEMICOLON  */
#line 536 "parser.y"
                                               {
        add_multiple_variables((yyvsp[-1].ast), DT_PTR_REAL);
        (yyval.ast) = make_node("TYPE_MULTI", 2, make_node("real*", 0), (yyvsp[-1].ast));
    }
#line 2387 "parser.tab.c"
    break;

  case 83: /* type_decl: TYPE TYPE_STRING id_list LBRACK NUM RBRACK SEMICOLON  */
#line 540 "parser.y"
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
#line 2405 "parser.tab.c"
    break;

  case 84: /* type_decl: TYPE TYPE_BOOL COLON id_value_list SEMICOLON  */
#line 553 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_BOOL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("bool", 0), (yyvsp[-1].ast));
}
#line 2414 "parser.tab.c"
    break;

  case 85: /* type_decl: TYPE TYPE_INT COLON id_value_list SEMICOLON  */
#line 557 "parser.y"
                                              {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_INT);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("int", 0), (yyvsp[-1].ast));
}
#line 2423 "parser.tab.c"
    break;

  case 86: /* type_decl: TYPE TYPE_CHAR COLON id_value_list SEMICOLON  */
#line 561 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_CHAR);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("char", 0), (yyvsp[-1].ast));
}
#line 2432 "parser.tab.c"
    break;

  case 87: /* type_decl: TYPE TYPE_STRING COLON id_value_list SEMICOLON  */
#line 565 "parser.y"
                                                 {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_STRING);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("string", 0), (yyvsp[-1].ast));
}
#line 2441 "parser.tab.c"
    break;

  case 88: /* type_decl: TYPE TYPE_REAL COLON id_value_list SEMICOLON  */
#line 569 "parser.y"
                                               {
    add_multiple_variables_with_values((yyvsp[-1].ast), DT_REAL);
    (yyval.ast) = make_node("TYPE_MULTI_INIT", 2, make_node("real", 0), (yyvsp[-1].ast));
}
#line 2450 "parser.tab.c"
    break;

  case 89: /* id_value_list: ID COLON literal  */
#line 576 "parser.y"
                       {
          (yyval.ast) = make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast));  // $3 כבר AST
      }
#line 2458 "parser.tab.c"
    break;

  case 90: /* id_value_list: id_value_list COMMA ID COLON literal  */
#line 579 "parser.y"
                                           {
          (yyval.ast) = make_node("", 2, (yyvsp[-4].ast), make_node((yyvsp[-2].sval), 1, (yyvsp[0].ast)));
      }
#line 2466 "parser.tab.c"
    break;

  case 91: /* literal: NUM  */
#line 586 "parser.y"
                  { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2472 "parser.tab.c"
    break;

  case 92: /* literal: TRUE  */
#line 587 "parser.y"
                { (yyval.ast) = make_node("true", 0); }
#line 2478 "parser.tab.c"
    break;

  case 93: /* literal: FALSE  */
#line 588 "parser.y"
                { (yyval.ast) = make_node("false", 0); }
#line 2484 "parser.tab.c"
    break;

  case 94: /* literal: CHAR_LITERAL  */
#line 589 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2490 "parser.tab.c"
    break;

  case 95: /* literal: STRING_LITERAL  */
#line 590 "parser.y"
                { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 2496 "parser.tab.c"
    break;

  case 96: /* return_stmt: RETURN expr SEMICOLON  */
#line 595 "parser.y"
                          {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);

        
        check_return_type((yyvsp[-1].ast), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, (yyvsp[-1].ast));
    }
#line 2509 "parser.tab.c"
    break;

  case 97: /* return_stmt: RETURN SEMICOLON  */
#line 603 "parser.y"
                     {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        check_return_type(make_node("NONE", 0), current_function_name);
        
        (yyval.ast) = make_node("RETURN", 1, make_node("NONE", 0));
    }
#line 2521 "parser.tab.c"
    break;

  case 98: /* if_stmt: IF expr COLON nested_block ELSE COLON nested_block  */
#line 614 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2530 "parser.tab.c"
    break;

  case 99: /* if_stmt: IF expr COLON nested_block  */
#line 619 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2539 "parser.tab.c"
    break;

  case 100: /* if_stmt: IF expr COLON stmt  */
#line 624 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "if");
        (yyval.ast) = make_node("IF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2548 "parser.tab.c"
    break;

  case 101: /* if_stmt: IF expr COLON stmt ELSE COLON stmt  */
#line 629 "parser.y"
    {
        check_boolean_condition((yyvsp[-5].ast), "if");
        (yyval.ast) = make_node("IF-ELSE", 3, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2557 "parser.tab.c"
    break;

  case 102: /* if_stmt: IF expr COLON nested_block elif_list ELSE COLON nested_block  */
#line 634 "parser.y"
    {
        check_boolean_condition((yyvsp[-6].ast), "if");
        (yyval.ast) = make_node("IF-ELIF-ELSE", 4, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2566 "parser.tab.c"
    break;

  case 103: /* elif_list: ELIF expr COLON block  */
#line 642 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2575 "parser.tab.c"
    break;

  case 104: /* elif_list: elif_list ELIF expr COLON block  */
#line 647 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "elif");
        (yyval.ast) = make_node("ELIF - ...", 3, (yyvsp[-4].ast), make_node("elif", 2, (yyvsp[-2].ast), (yyvsp[0].ast)));
    }
#line 2584 "parser.tab.c"
    break;

  case 105: /* while_stmt: WHILE COLON expr SEMICOLON  */
#line 654 "parser.y"
    {
        check_boolean_condition((yyvsp[-1].ast), "while");
        (yyval.ast) = make_node("while", 1, (yyvsp[-1].ast));
    }
#line 2593 "parser.tab.c"
    break;

  case 106: /* while_stmt: WHILE expr COLON block  */
#line 659 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2602 "parser.tab.c"
    break;

  case 107: /* while_stmt: WHILE expr COLON stmt  */
#line 664 "parser.y"
    {
        check_boolean_condition((yyvsp[-2].ast), "while");
        (yyval.ast) = make_node("while2", 2, (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2611 "parser.tab.c"
    break;

  case 108: /* do_while_stmt: DO COLON stmt_list WHILE expr SEMICOLON  */
#line 670 "parser.y"
                                            {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2620 "parser.tab.c"
    break;

  case 109: /* do_while_stmt: DO COLON stmt WHILE expr SEMICOLON  */
#line 675 "parser.y"
                                       {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2629 "parser.tab.c"
    break;

  case 110: /* do_while_stmt: DO COLON block WHILE expr SEMICOLON  */
#line 680 "parser.y"
                                        {
        check_boolean_condition((yyvsp[-1].ast), "do-while");
        (yyval.ast) = make_node("do-while", 2, (yyvsp[-3].ast), (yyvsp[-1].ast));
    }
#line 2638 "parser.tab.c"
    break;

  case 111: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block  */
#line 687 "parser.y"
                                                                        {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2647 "parser.tab.c"
    break;

  case 112: /* for_stmt: FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt  */
#line 692 "parser.y"
                                                                       {
        check_boolean_condition((yyvsp[-5].ast), "for"); 
        (yyval.ast) = make_node("for", 4, (yyvsp[-6].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[0].ast));
    }
#line 2656 "parser.tab.c"
    break;

  case 113: /* update_expr: ID ASSIGN expr  */
#line 699 "parser.y"
                   {
        (yyval.ast) = make_node("=", 2, make_node((yyvsp[-2].sval), 0), (yyvsp[0].ast));
    }
#line 2664 "parser.tab.c"
    break;

  case 114: /* update_expr: expr  */
#line 702 "parser.y"
           {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2672 "parser.tab.c"
    break;

  case 115: /* call_args: call_list  */
#line 707 "parser.y"
              { (yyval.ast) = make_node("args", 1, (yyvsp[0].ast)); }
#line 2678 "parser.tab.c"
    break;

  case 116: /* call_args: %empty  */
#line 708 "parser.y"
                { (yyval.ast) = make_node("args", 1, make_node("none", 0)); }
#line 2684 "parser.tab.c"
    break;

  case 117: /* call_list: call_list COMMA expr  */
#line 713 "parser.y"
    {
        (yyval.ast)= make_node ("par",2,(yyvsp[-2].ast),(yyvsp[0].ast));
    }
#line 2692 "parser.tab.c"
    break;

  case 118: /* call_list: expr  */
#line 717 "parser.y"
    {
          (yyval.ast)= make_node ("par",1,(yyvsp[0].ast));
    }
#line 2700 "parser.tab.c"
    break;

  case 119: /* assignment_call: ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 724 "parser.y"
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
#line 2731 "parser.tab.c"
    break;

  case 120: /* void_call: CALL ID LPAREN call_args RPAREN SEMICOLON  */
#line 753 "parser.y"
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
#line 2760 "parser.tab.c"
    break;

  case 121: /* block: T_BEGIN stmt_list T_END  */
#line 780 "parser.y"
                            {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
    }
#line 2768 "parser.tab.c"
    break;

  case 122: /* block: T_BEGIN T_END  */
#line 783 "parser.y"
                    {
        (yyval.ast) = make_node("BLOCK", 0); 
    }
#line 2776 "parser.tab.c"
    break;

  case 123: /* $@7: %empty  */
#line 788 "parser.y"
            {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2785 "parser.tab.c"
    break;

  case 124: /* nested_block: T_BEGIN $@7 stmt_list T_END  */
#line 791 "parser.y"
                      {
        (yyval.ast) = make_node("BLOCK", 1, (yyvsp[-1].ast)); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2795 "parser.tab.c"
    break;

  case 125: /* $@8: %empty  */
#line 796 "parser.y"
              {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    }
#line 2804 "parser.tab.c"
    break;

  case 126: /* nested_block: T_BEGIN $@8 T_END  */
#line 799 "parser.y"
            {
        (yyval.ast) = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
#line 2814 "parser.tab.c"
    break;

  case 127: /* expr: expr PLUS expr  */
#line 807 "parser.y"
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
#line 2830 "parser.tab.c"
    break;

  case 128: /* expr: expr MINUS expr  */
#line 818 "parser.y"
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
#line 2846 "parser.tab.c"
    break;

  case 129: /* expr: expr MULT expr  */
#line 829 "parser.y"
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
#line 2862 "parser.tab.c"
    break;

  case 130: /* expr: expr DIV expr  */
#line 840 "parser.y"
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
#line 2878 "parser.tab.c"
    break;

  case 131: /* expr: expr EQ expr  */
#line 851 "parser.y"
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
#line 2894 "parser.tab.c"
    break;

  case 132: /* expr: expr NE expr  */
#line 862 "parser.y"
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
#line 2910 "parser.tab.c"
    break;

  case 133: /* expr: expr LT expr  */
#line 873 "parser.y"
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
#line 2926 "parser.tab.c"
    break;

  case 134: /* expr: expr GT expr  */
#line 884 "parser.y"
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
#line 2942 "parser.tab.c"
    break;

  case 135: /* expr: expr LE expr  */
#line 895 "parser.y"
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
#line 2958 "parser.tab.c"
    break;

  case 136: /* expr: expr GE expr  */
#line 906 "parser.y"
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
#line 2974 "parser.tab.c"
    break;

  case 137: /* expr: LPAREN expr RPAREN  */
#line 917 "parser.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2980 "parser.tab.c"
    break;

  case 138: /* expr: ID LBRACK expr RBRACK  */
#line 919 "parser.y"
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
#line 3001 "parser.tab.c"
    break;

  case 139: /* expr: LBRACK expr RBRACK  */
#line 936 "parser.y"
                         {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        (yyval.ast) = (yyvsp[-1].ast); 
    }
#line 3012 "parser.tab.c"
    break;

  case 140: /* expr: NUM  */
#line 943 "parser.y"
          { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3018 "parser.tab.c"
    break;

  case 141: /* expr: ID  */
#line 944 "parser.y"
         {
        Symbol* sym = lookup_any_scope((yyvsp[0].sval));
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[0].sval));
            yyerror(error_msg);
        }
        (yyval.ast) = make_node((yyvsp[0].sval), 0);
    }
#line 3032 "parser.tab.c"
    break;

  case 142: /* expr: CHAR_LITERAL  */
#line 953 "parser.y"
                   { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3038 "parser.tab.c"
    break;

  case 143: /* expr: STRING_LITERAL  */
#line 954 "parser.y"
                     { (yyval.ast) = make_node((yyvsp[0].sval), 0); }
#line 3044 "parser.tab.c"
    break;

  case 144: /* expr: NULLPTR  */
#line 955 "parser.y"
              { (yyval.ast) = make_node("nullptr", 0); }
#line 3050 "parser.tab.c"
    break;

  case 145: /* expr: TRUE  */
#line 956 "parser.y"
           { (yyval.ast) = make_node("true", 0); }
#line 3056 "parser.tab.c"
    break;

  case 146: /* expr: FALSE  */
#line 957 "parser.y"
            { (yyval.ast) = make_node("false", 0); }
#line 3062 "parser.tab.c"
    break;

  case 147: /* expr: AND  */
#line 958 "parser.y"
          { (yyval.ast) = make_node("and", 0); }
#line 3068 "parser.tab.c"
    break;

  case 148: /* expr: OR  */
#line 959 "parser.y"
         { (yyval.ast) = make_node("or", 0); }
#line 3074 "parser.tab.c"
    break;

  case 149: /* expr: NOT  */
#line 960 "parser.y"
          { (yyval.ast) = make_node("not", 0); }
#line 3080 "parser.tab.c"
    break;

  case 150: /* expr: CALL ID LPAREN call_args RPAREN  */
#line 961 "parser.y"
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
#line 3096 "parser.tab.c"
    break;

  case 151: /* expr: ID LPAREN call_args RPAREN  */
#line 972 "parser.y"
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
#line 3129 "parser.tab.c"
    break;

  case 152: /* expr: expr AND expr  */
#line 1000 "parser.y"
                    { (yyval.ast) = make_node("and", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3135 "parser.tab.c"
    break;

  case 153: /* expr: expr OR expr  */
#line 1001 "parser.y"
                   { (yyval.ast) = make_node("or", 2, (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3141 "parser.tab.c"
    break;

  case 154: /* expr: NOT expr  */
#line 1002 "parser.y"
               { (yyval.ast) = make_node("not", 1, (yyvsp[0].ast)); }
#line 3147 "parser.tab.c"
    break;

  case 155: /* expr: MULT expr  */
#line 1004 "parser.y"
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
#line 3184 "parser.tab.c"
    break;

  case 156: /* expr: ADDRESS ID  */
#line 1036 "parser.y"
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
#line 3211 "parser.tab.c"
    break;

  case 157: /* expr: ADDRESS ID LBRACK expr RBRACK  */
#line 1059 "parser.y"
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
#line 3234 "parser.tab.c"
    break;


#line 3238 "parser.tab.c"

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

#line 1080 "parser.y"


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

    if (!main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    return result;
}
