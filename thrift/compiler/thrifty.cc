/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "thrifty.yy" /* yacc.c:339  */

/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**
 * Thrift parser.
 *
 * This parser is used on a thrift definition file.
 *
 */

#define __STDC_LIMIT_MACROS
#define __STDC_FORMAT_MACROS
#include <cassert>
#include <stdio.h>
#include <inttypes.h>
#include <limits.h>
#include <stack>
#include <utility>
#include "thrift/compiler/common.h"
#include "thrift/compiler/globals.h"
#include "thrift/compiler/parse/t_program.h"
#include "thrift/compiler/parse/t_scope.h"

/**
 * This global variable is used for automatic numbering of field indices etc.
 * when parsing the members of a struct. Field values are automatically
 * assigned starting from -1 and working their way down.
 */
int y_field_val = -1;
/**
 * This global variable is used for automatic numbering of enum values.
 * y_enum_val is the last value assigned; the next auto-assigned value will be
 * y_enum_val+1, and then it continues working upwards.  Explicitly specified
 * enum values reset y_enum_val to that value.
 */
int32_t y_enum_val = -1;
int g_arglist = 0;
const int struct_is_struct = 0;
const int struct_is_union = 1;
char* y_enum_name = nullptr;

// Define an enum class for all types that have lineno embedded.
enum class LineType {
  kTypedef,
  kEnum,
  kEnumValue,
  kConst,
  kStruct,
  kService,
  kFunction,
  kField,
  kXception,
};
// The LinenoStack class is used for keeping track of line number and automatic
// type checking
class LinenoStack {
 public:
  void push(LineType type, int lineno) {
    stack_.emplace(type, lineno);
  }
  int pop(LineType type) {
    if (type != stack_.top().first) {
      throw std::logic_error("Popping wrong type from line number stack");
    }
    int lineno = stack_.top().second;
    stack_.pop();
    return lineno;
  }
 private:
  std::stack<std::pair<LineType, int>> stack_;
};
LinenoStack lineno_stack;

#line 157 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "thrifty.hh".  */
#ifndef YY_YY_HOME_HEMANT_FBTHRIFT_THRIFT_COMPILER_THRIFTY_HH_INCLUDED
# define YY_YY_HOME_HEMANT_FBTHRIFT_THRIFT_COMPILER_THRIFTY_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tok_identifier = 258,
    tok_client = 259,
    tok_literal = 260,
    tok_doctext = 261,
    tok_st_identifier = 262,
    tok_bool_constant = 263,
    tok_int_constant = 264,
    tok_dub_constant = 265,
    tok_include = 266,
    tok_namespace = 267,
    tok_cpp_namespace = 268,
    tok_cpp_include = 269,
    tok_hs_include = 270,
    tok_php_namespace = 271,
    tok_py_module = 272,
    tok_perl_package = 273,
    tok_java_package = 274,
    tok_ruby_namespace = 275,
    tok_smalltalk_category = 276,
    tok_smalltalk_prefix = 277,
    tok_cocoa_prefix = 278,
    tok_csharp_namespace = 279,
    tok_void = 280,
    tok_bool = 281,
    tok_byte = 282,
    tok_string = 283,
    tok_binary = 284,
    tok_slist = 285,
    tok_i16 = 286,
    tok_i32 = 287,
    tok_i64 = 288,
    tok_double = 289,
    tok_float = 290,
    tok_map = 291,
    tok_hash_map = 292,
    tok_list = 293,
    tok_set = 294,
    tok_hash_set = 295,
    tok_stream = 296,
    tok_oneway = 297,
    tok_typedef = 298,
    tok_struct = 299,
    tok_xception = 300,
    tok_throws = 301,
    tok_extends = 302,
    tok_service = 303,
    tok_enum = 304,
    tok_const = 305,
    tok_required = 306,
    tok_optional = 307,
    tok_union = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "thrifty.yy" /* yacc.c:355  */

  char*          id;
  int64_t        iconst;
  double         dconst;
  bool           tbool;
  t_doc*         tdoc;
  t_type*        ttype;
  t_base_type*   tbase;
  t_typedef*     ttypedef;
  t_enum*        tenum;
  t_enum_value*  tenumv;
  t_const*       tconst;
  t_const_value* tconstv;
  t_struct*      tstruct;
  t_structpair*  tstructpair;
  t_service*     tservice;
  t_function*    tfunction;
  t_field*       tfield;
  char*          dtext;
  t_field::e_req ereq;
  t_annotation*  tannot;
  t_field_id     tfieldid;

#line 275 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HEMANT_FBTHRIFT_THRIFT_COMPILER_THRIFTY_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 292 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      62,    63,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    55,
      64,    58,    65,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   279,   279,   292,   303,   312,   317,   322,   326,   333,
     341,   349,   356,   361,   370,   379,   388,   397,   406,   415,
     424,   433,   443,   459,   467,   472,   480,   488,   499,   506,
     513,   520,   530,   529,   546,   548,   551,   555,   559,   554,
     577,   600,   607,   621,   640,   655,   654,   672,   678,   687,
     693,   698,   716,   721,   728,   735,   742,   749,   756,   763,
     770,   774,   781,   780,   800,   799,   850,   849,   866,   871,
     876,   892,   897,   904,   910,   927,   935,   943,   949,   958,
     964,   972,   979,   984,   989,   993,   997,  1001,  1006,  1012,
    1019,  1029,  1035,  1071,  1108,  1115,  1126,  1138,  1143,  1152,
    1157,  1162,  1167,  1174,  1181,  1207,  1212,  1218,  1231,  1236,
    1241,  1246,  1251,  1256,  1261,  1266,  1271,  1276,  1282,  1293,
    1298,  1303,  1308,  1313,  1318,  1325,  1332,  1339,  1346,  1353,
    1360,  1367,  1373,  1379,  1387,  1393,  1402,  1408,  1414,  1441,
    1447,  1455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tok_identifier", "tok_client",
  "tok_literal", "tok_doctext", "tok_st_identifier", "tok_bool_constant",
  "tok_int_constant", "tok_dub_constant", "tok_include", "tok_namespace",
  "tok_cpp_namespace", "tok_cpp_include", "tok_hs_include",
  "tok_php_namespace", "tok_py_module", "tok_perl_package",
  "tok_java_package", "tok_ruby_namespace", "tok_smalltalk_category",
  "tok_smalltalk_prefix", "tok_cocoa_prefix", "tok_csharp_namespace",
  "tok_void", "tok_bool", "tok_byte", "tok_string", "tok_binary",
  "tok_slist", "tok_i16", "tok_i32", "tok_i64", "tok_double", "tok_float",
  "tok_map", "tok_hash_map", "tok_list", "tok_set", "tok_hash_set",
  "tok_stream", "tok_oneway", "tok_typedef", "tok_struct", "tok_xception",
  "tok_throws", "tok_extends", "tok_service", "tok_enum", "tok_const",
  "tok_required", "tok_optional", "tok_union", "','", "';'", "'{'", "'}'",
  "'='", "'['", "']'", "':'", "'('", "')'", "'<'", "'>'", "$accept",
  "Program", "CaptureDocText", "DestroyDocText", "HeaderList", "Header",
  "Include", "DefinitionList", "Definition", "TypeDefinition", "Typedef",
  "$@1", "CommaOrSemicolonOptional", "Enum", "$@2", "$@3", "EnumDefList",
  "EnumDef", "EnumValue", "Const", "$@4", "ConstValue", "ConstList",
  "ConstListContents", "ConstMap", "ConstMapContents", "StructHead",
  "Struct", "$@5", "Xception", "$@6", "Service", "$@7", "FlagArgs",
  "UnflagArgs", "Extends", "FunctionList", "Function",
  "MaybeStreamAndParamList", "ParamList", "EmptyParamList", "Param",
  "Oneway", "ThrowsThrows", "Throws", "ClientThrows", "FieldList", "Field",
  "FieldIdentifier", "FieldRequiredness", "FieldValue", "FunctionType",
  "PubsubStreamType", "FieldType", "BaseType", "SimpleBaseType",
  "ContainerType", "SimpleContainerType", "MapType", "HashMapType",
  "SetType", "HashSetType", "ListType", "StreamType", "TypeAnnotations",
  "TypeAnnotationList", "TypeAnnotation", "TypeAnnotationValue",
  "FunctionAnnotations", "IntOrLiteral", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    44,    59,   123,   125,    61,    91,
      93,    58,    40,    41,    60,    62
};
# endif

#define YYPACT_NINF -214

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-214)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    11,    86,  -214,   177,    13,     4,    12,    18,    22,
      30,    48,    52,    53,    56,    57,    54,    59,    60,    63,
    -214,  -214,    97,  -214,     5,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,   146,    64,    69,    70,   146,
      78,    21,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,    20,    24,    27,    28,    29,    32,    82,  -214,
      21,  -214,    21,  -214,  -214,  -214,  -214,  -214,  -214,    38,
      50,  -214,    92,    61,  -214,  -214,   146,   146,   146,   146,
     146,   146,    21,  -214,  -214,  -214,   113,    62,    65,    85,
    -214,     1,    66,    68,    79,    88,   106,   137,  -214,    71,
    -214,  -214,  -214,    31,    94,   145,  -214,  -214,   146,   146,
    -214,  -214,  -214,  -214,    21,   110,  -214,  -214,   147,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,   -25,  -214,  -214,    21,
      45,   -25,   140,   141,  -214,   148,   -14,   150,    21,   124,
    -214,    23,     9,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,   146,   166,   153,
    -214,  -214,   154,    21,  -214,   152,  -214,   -25,   208,  -214,
     129,    21,   205,   -25,    31,  -214,   157,  -214,    74,   213,
    -214,  -214,  -214,  -214,  -214,  -214,   -25,    31,    21,  -214,
     155,  -214,  -214,   -25,   178,  -214,   146,   158,   159,  -214,
     215,     3,  -214,  -214,   169,   162,   163,    21,   216,  -214,
    -214,  -214,  -214,  -214,   -25,  -214,   164,   165,   167,  -214,
    -214,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     4,     1,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,     0,    22,     0,    10,    11,    12,    13,    14,
      15,    19,    16,    17,    18,    20,    21,    32,    60,    64,
      66,    37,    45,    61,    23,    26,    28,    29,    25,    62,
      30,    31,    27,     8,     9,     0,     0,     0,     0,     0,
       0,   132,   111,   112,   108,   109,   110,   113,   114,   115,
     116,   117,     0,     0,     0,     0,     0,     0,     0,   105,
     132,   106,   132,   119,   120,   121,   122,   123,   124,     0,
      71,    38,     0,     0,   134,   104,     0,     0,     0,     0,
       0,     0,   132,   107,   118,    91,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,    33,     3,
      70,    68,    41,     0,     3,   137,   131,   133,     0,     0,
     129,   127,   128,   130,   132,    94,    90,    73,     3,    51,
      50,    47,    48,    49,    59,    56,    36,    52,    53,   132,
       0,    36,     0,     0,    65,     0,    97,     3,   132,     0,
      40,     0,     0,    34,    35,    46,    63,   139,   140,   141,
     136,   135,   125,   126,    93,    95,    96,     0,    83,     0,
      72,    39,    44,   132,    57,     0,    54,    36,     0,    82,
       0,   132,     0,    36,     0,    55,    99,   102,     0,     0,
     100,   101,   138,    67,    43,    42,    36,     0,   132,   103,
       0,    58,    98,    36,    80,    92,     0,     0,     3,    79,
       0,    87,    78,    81,    80,     0,     0,   132,    85,    86,
      80,    76,    91,    91,    36,    84,     3,     3,     3,    74,
      89,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,    -5,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -135,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -137,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,    -4,
       7,  -214,  -214,  -214,  -214,     6,  -107,  -213,  -214,  -214,
    -214,  -214,    15,   -53,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,   -60,  -214,  -214,  -214,     8,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   135,     4,     2,    20,    21,     5,    44,    45,
      46,    55,   165,    47,    58,   108,   138,   160,   183,    48,
      59,   146,   147,   162,   148,   161,    49,    50,    60,    51,
      56,    52,    57,   137,   179,   107,   157,   180,   217,   218,
     219,   222,   190,   227,   228,   229,   119,   136,   156,   177,
     208,   199,   200,   209,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   202,   111,   127,   151,   203,   170
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    95,    78,   124,   125,   223,    92,   225,    53,    23,
      54,     3,   139,    -2,   140,    24,   171,   141,   142,   143,
     103,    25,   104,   223,   185,   187,   139,    26,   140,   163,
     164,   141,   142,   143,   139,    27,   140,   175,   176,   141,
     142,   143,   118,   112,   113,   114,   115,   116,   117,   226,
     167,    28,   195,   168,   169,    29,    30,   206,   205,    31,
      32,    33,    34,    35,   126,   144,    36,    89,   145,   186,
     212,   211,    90,    91,   154,   152,   153,    61,   215,   144,
     184,    93,   145,    94,    96,   102,   -24,   144,    97,   166,
     145,    98,    99,   100,   105,   109,   101,   106,   181,   239,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,   120,   110,   121,   155,
     128,   122,   129,   193,   188,   237,   238,   182,   134,   -24,
     -24,   -24,    61,   159,   -24,   -24,   -24,   201,   101,   -24,
      37,    38,    39,   123,   130,    40,    41,    42,   213,    61,
      43,   149,   178,   131,   197,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     198,   132,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   133,   150,   158,   172,   173,   -69,   189,   174,
     191,   196,   192,   194,   204,   207,   210,   214,   224,   216,
     225,   221,   -77,   230,   232,   233,   236,   -75,   240,   220,
     241,   231,     0,     0,   235,   234
};

static const yytype_int16 yycheck[] =
{
       5,    61,    55,   110,     3,   218,    59,     4,     3,     5,
       5,     0,     3,     0,     5,     3,   151,     8,     9,    10,
      80,     3,    82,   236,   161,   162,     3,     5,     5,    54,
      55,     8,     9,    10,     3,     5,     5,    51,    52,     8,
       9,    10,   102,    96,    97,    98,    99,   100,   101,    46,
       5,     3,   187,     8,     9,     3,     3,   194,   193,     3,
       3,     7,     3,     3,    63,    56,     3,     3,    59,    60,
     207,   206,     3,     3,   134,   128,   129,     3,   213,    56,
      57,     3,    59,    62,    64,     3,     0,    56,    64,   149,
      59,    64,    64,    64,    56,     3,    64,    47,   158,   234,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     3,    56,    56,     9,
      54,    56,    54,   183,   177,   232,   233,     3,    57,    43,
      44,    45,     3,   138,    48,    49,    50,   190,    64,    53,
      43,    44,    45,    58,    65,    48,    49,    50,   208,     3,
      53,    57,   157,    65,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    65,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    65,    58,    57,    65,    65,    57,    42,    61,
      57,     3,    58,    61,     9,    58,     3,    62,     3,    41,
       4,    63,    63,    54,    62,    62,   230,    63,    63,   214,
      63,   224,    -1,    -1,   228,   227
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    70,     0,    69,    73,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      71,    72,    68,     5,     3,     3,     5,     5,     3,     3,
       3,     3,     3,     7,     3,     3,     3,    43,    44,    45,
      48,    49,    50,    53,    74,    75,    76,    79,    85,    92,
      93,    95,    97,     3,     5,    77,    96,    98,    80,    86,
      94,     3,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     3,
       3,     3,   119,     3,    62,   130,    64,    64,    64,    64,
      64,    64,     3,   130,   130,    56,    47,   101,    81,     3,
      56,   131,   119,   119,   119,   119,   119,   119,   130,   112,
       3,    56,    56,    58,   112,     3,    63,   132,    54,    54,
      65,    65,    65,    65,    57,    68,   113,    99,    82,     3,
       5,     8,     9,    10,    56,    59,    87,    88,    90,    57,
      58,   133,   119,   119,   130,     9,   114,   102,    57,    68,
      83,    91,    89,    54,    55,    78,   130,     5,     8,     9,
     135,    78,    65,    65,    61,    51,    52,   115,    68,   100,
     103,   130,     3,    84,    57,    87,    60,    87,   119,    42,
     108,    57,    58,   130,    61,    78,     3,    25,    41,   117,
     118,   119,   130,   134,     9,    78,    87,    58,   116,   119,
       3,    78,    87,   130,    62,    78,    41,   104,   105,   106,
     118,    63,   107,   113,     3,     4,    46,   109,   110,   111,
      54,   106,    62,    62,   134,   111,   105,   112,   112,    78,
      63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    77,    76,    78,    78,    78,    80,    81,    79,
      82,    82,    83,    84,    84,    86,    85,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    91,    91,
      92,    92,    94,    93,    96,    95,    98,    97,    99,   100,
     101,   101,   102,   102,   103,   104,   104,   104,   105,   105,
     106,   107,   108,   108,   109,   109,   109,   109,   110,   111,
     112,   112,   113,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   117,   118,   119,   119,   119,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   123,
     123,   123,   123,   123,   123,   124,   125,   126,   127,   128,
     129,   130,   130,   131,   131,   132,   133,   133,   134,   135,
     135,   135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     3,     0,     1,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     1,     0,     0,     0,     8,
       2,     0,     4,     3,     1,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     3,     5,     0,
       1,     1,     0,     7,     0,     7,     0,    10,     0,     0,
       2,     0,     2,     0,    10,     4,     3,     1,     2,     1,
       0,     1,     1,     0,     2,     1,     1,     0,     4,     4,
       2,     0,     8,     2,     0,     1,     1,     0,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     6,     6,     4,     4,     4,
       4,     3,     0,     2,     0,     3,     2,     0,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 280 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Program -> Headers DefinitionList");
      /*
      TODO(dreiss): Decide whether full-program doctext is worth the trouble.
      if ($1 != NULL) {
        g_program->set_doc($1);
      }
      */
      clear_doctext();
    }
#line 1576 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 292 "thrifty.yy" /* yacc.c:1646  */
    {
      if (g_parse_mode == PROGRAM) {
        (yyval.dtext) = g_doctext;
        g_doctext = NULL;
      } else {
        (yyval.dtext) = NULL;
      }
    }
#line 1589 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 303 "thrifty.yy" /* yacc.c:1646  */
    {
      if (g_parse_mode == PROGRAM) {
        clear_doctext();
      }
    }
#line 1599 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 313 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("HeaderList -> HeaderList Header");
    }
#line 1607 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 317 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("HeaderList -> ");
    }
#line 1615 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 323 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Header -> Include");
    }
#line 1623 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 327 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Header -> tok_namespace tok_identifier tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace((yyvsp[-1].id), (yyvsp[0].id));
      }
    }
#line 1634 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 334 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Header -> tok_namespace tok_identifier tok_literal");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace((yyvsp[-1].id), (yyvsp[0].id));
      }
    }
#line 1645 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 342 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'cpp_namespace' is deprecated. Use 'namespace cpp' instead");
      pdebug("Header -> tok_cpp_namespace tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("cpp", (yyvsp[0].id));
      }
    }
#line 1657 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 350 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Header -> tok_cpp_include tok_literal");
      if (g_parse_mode == PROGRAM) {
        g_program->add_cpp_include((yyvsp[0].id));
      }
    }
#line 1668 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 357 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Header -> tok_hs_include tok_literal");
      // Do nothing. This syntax is handled by the hs compiler
    }
#line 1677 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 362 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'php_namespace' is deprecated. Use 'namespace php' instead");
      pdebug("Header -> tok_php_namespace tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("php", (yyvsp[0].id));
      }
    }
#line 1689 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 371 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'py_module' is deprecated. Use 'namespace py' instead");
      pdebug("Header -> tok_py_module tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("py", (yyvsp[0].id));
      }
    }
#line 1701 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 380 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'perl_package' is deprecated. Use 'namespace perl' instead");
      pdebug("Header -> tok_perl_namespace tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("perl", (yyvsp[0].id));
      }
    }
#line 1713 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 389 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'ruby_namespace' is deprecated. Use 'namespace rb' instead");
      pdebug("Header -> tok_ruby_namespace tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("rb", (yyvsp[0].id));
      }
    }
#line 1725 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 398 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'smalltalk_category' is deprecated. Use 'namespace smalltalk.category' instead");
      pdebug("Header -> tok_smalltalk_category tok_st_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("smalltalk.category", (yyvsp[0].id));
      }
    }
#line 1737 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 407 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'smalltalk_prefix' is deprecated. Use 'namespace smalltalk.prefix' instead");
      pdebug("Header -> tok_smalltalk_prefix tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("smalltalk.prefix", (yyvsp[0].id));
      }
    }
#line 1749 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 416 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'java_package' is deprecated. Use 'namespace java' instead");
      pdebug("Header -> tok_java_package tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("java", (yyvsp[0].id));
      }
    }
#line 1761 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 425 "thrifty.yy" /* yacc.c:1646  */
    {
      pwarning(1, "'cocoa_prefix' is deprecated. Use 'namespace cocoa' instead");
      pdebug("Header -> tok_cocoa_prefix tok_identifier");
      if (g_parse_mode == PROGRAM) {
        g_program->set_namespace("cocoa", (yyvsp[0].id));
      }
    }
#line 1773 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 434 "thrifty.yy" /* yacc.c:1646  */
    {
     pwarning(1, "'csharp_namespace' is deprecated. Use 'namespace csharp' instead");
     pdebug("Header -> tok_csharp_namespace tok_identifier");
     if (g_parse_mode == PROGRAM) {
       g_program->set_namespace("csharp", (yyvsp[0].id));
     }
   }
#line 1785 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 444 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Include -> tok_include tok_literal");
      if (g_parse_mode == INCLUDES) {
        std::string path = include_file(std::string((yyvsp[0].id)));
        if (!path.empty()) {
          if (program_cache.find(path) == program_cache.end()) {
            program_cache[path] = g_program->add_include(path, std::string((yyvsp[0].id)));
          } else {
            g_program->add_include(program_cache[path]);
          }
        }
      }
    }
#line 1803 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 460 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("DefinitionList -> DefinitionList Definition");
      if ((yyvsp[-1].dtext) != NULL && (yyvsp[0].tdoc) != NULL) {
        (yyvsp[0].tdoc)->set_doc((yyvsp[-1].dtext));
      }
    }
#line 1814 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 467 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("DefinitionList -> ");
    }
#line 1822 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 473 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Definition -> Const");
      if (g_parse_mode == PROGRAM) {
        g_program->add_const((yyvsp[0].tconst));
      }
      (yyval.tdoc) = (yyvsp[0].tconst);
    }
#line 1834 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 481 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Definition -> TypeDefinition");
      if (g_parse_mode == PROGRAM) {
        g_scope_cache->add_type(g_program->get_name() + "." + (yyvsp[0].ttype)->get_name(), (yyvsp[0].ttype));
      }
      (yyval.tdoc) = (yyvsp[0].ttype);
    }
#line 1846 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 489 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Definition -> Service");
      if (g_parse_mode == PROGRAM) {
        g_scope_cache->add_service(g_program->get_name() + "." + (yyvsp[0].tservice)->get_name(), (yyvsp[0].tservice));
        g_program->add_service((yyvsp[0].tservice));
      }
      (yyval.tdoc) = (yyvsp[0].tservice);
    }
#line 1859 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 500 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeDefinition -> Typedef");
      if (g_parse_mode == PROGRAM) {
        g_program->add_typedef((yyvsp[0].ttypedef));
      }
    }
#line 1870 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 507 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeDefinition -> Enum");
      if (g_parse_mode == PROGRAM) {
        g_program->add_enum((yyvsp[0].tenum));
      }
    }
#line 1881 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 514 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeDefinition -> Struct");
      if (g_parse_mode == PROGRAM) {
        g_program->add_struct((yyvsp[0].tstruct));
      }
    }
#line 1892 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 521 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeDefinition -> Xception");
      if (g_parse_mode == PROGRAM) {
        g_program->add_xception((yyvsp[0].tstruct));
      }
    }
#line 1903 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 530 "thrifty.yy" /* yacc.c:1646  */
    {
      lineno_stack.push(LineType::kTypedef, yylineno);
    }
#line 1911 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 534 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeDef -> tok_typedef FieldType tok_identifier");
      t_typedef *td = new t_typedef(g_program, (yyvsp[-2].ttype), (yyvsp[-1].id), g_scope_cache);
      (yyval.ttypedef) = td;
      (yyval.ttypedef)->set_lineno(lineno_stack.pop(LineType::kTypedef));
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.ttypedef)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      }
    }
#line 1926 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 547 "thrifty.yy" /* yacc.c:1646  */
    {}
#line 1932 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 549 "thrifty.yy" /* yacc.c:1646  */
    {}
#line 1938 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 551 "thrifty.yy" /* yacc.c:1646  */
    {}
#line 1944 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 555 "thrifty.yy" /* yacc.c:1646  */
    {
      lineno_stack.push(LineType::kEnum, yylineno);
    }
#line 1952 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 559 "thrifty.yy" /* yacc.c:1646  */
    {
      assert(y_enum_name == nullptr);
      y_enum_name = (yyvsp[0].id);
    }
#line 1961 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 564 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Enum -> tok_enum tok_identifier { EnumDefList }");
      (yyval.tenum) = (yyvsp[-2].tenum);
      (yyval.tenum)->set_name((yyvsp[-5].id));
      (yyval.tenum)->set_lineno(lineno_stack.pop(LineType::kEnum));
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.tenum)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      }
      y_enum_name = nullptr;
    }
#line 1977 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 578 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EnumDefList -> EnumDefList EnumDef");
      (yyval.tenum) = (yyvsp[-1].tenum);
      (yyval.tenum)->append((yyvsp[0].tenumv));

      if (g_parse_mode == PROGRAM) {
        t_const_value* const_val = new t_const_value((yyvsp[0].tenumv)->get_value());
        const_val->set_is_enum();
        const_val->set_enum((yyval.tenum));
        const_val->set_enum_value((yyvsp[0].tenumv));
        t_const* tconst = new t_const(
            g_program, g_type_i32, (yyvsp[0].tenumv)->get_name(), const_val);

        assert(y_enum_name != nullptr);
        string type_prefix = string(y_enum_name) + ".";
        g_scope_cache->add_constant(
            g_program->get_name() + "." + (yyvsp[0].tenumv)->get_name(), tconst);
        g_scope_cache->add_constant(
            g_program->get_name() + "." + type_prefix + (yyvsp[0].tenumv)->get_name(), tconst);
      }
    }
#line 2003 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 600 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EnumDefList -> ");
      (yyval.tenum) = new t_enum(g_program);
      y_enum_val = -1;
    }
#line 2013 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 608 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EnumDef -> EnumValue");
      (yyval.tenumv) = (yyvsp[-2].tenumv);
      if ((yyvsp[-3].dtext) != NULL) {
        (yyval.tenumv)->set_doc((yyvsp[-3].dtext));
      }
      if ((yyvsp[-1].ttype) != NULL) {
        (yyval.tenumv)->annotations_ = (yyvsp[-1].ttype)->annotations_;
        delete (yyvsp[-1].ttype);
      }
    }
#line 2029 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 622 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EnumValue -> tok_identifier = tok_int_constant");
      if ((yyvsp[0].iconst) < 0 && !g_allow_neg_enum_vals) {
        pwarning(1, "Negative value supplied for enum %s.", (yyvsp[-2].id));
      }
      if ((yyvsp[0].iconst) < INT32_MIN || (yyvsp[0].iconst) > INT32_MAX) {
        // Note: this used to be just a warning.  However, since thrift always
        // treats enums as i32 values, I'm changing it to a fatal error.
        // I doubt this will affect many people, but users who run into this
        // will have to update their thrift files to manually specify the
        // truncated i32 value that thrift has always been using anyway.
        failure("64-bit value supplied for enum %s will be truncated.", (yyvsp[-2].id));
      }
      y_enum_val = (yyvsp[0].iconst);
      (yyval.tenumv) = new t_enum_value((yyvsp[-2].id), y_enum_val);
      (yyval.tenumv)->set_lineno(yylineno);
    }
#line 2051 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 641 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EnumValue -> tok_identifier");
      if (y_enum_val == INT32_MAX) {
        failure("enum value overflow at enum %s", (yyvsp[0].id));
      }
      (yyval.tenumv) = new t_enum_value((yyvsp[0].id));

      ++y_enum_val;
      (yyval.tenumv)->set_value(y_enum_val);
      (yyval.tenumv)->set_lineno(yylineno);
    }
#line 2067 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 655 "thrifty.yy" /* yacc.c:1646  */
    {
      lineno_stack.push(LineType::kConst, yylineno);
    }
#line 2075 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 659 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Const -> tok_const FieldType tok_identifier = ConstValue");
      if (g_parse_mode == PROGRAM) {
        (yyval.tconst) = new t_const(g_program, (yyvsp[-4].ttype), (yyvsp[-3].id), (yyvsp[-1].tconstv));
        (yyval.tconst)->set_lineno(lineno_stack.pop(LineType::kConst));
        validate_const_type((yyval.tconst));
        g_scope_cache->add_constant(g_program->get_name() + "." + (yyvsp[-3].id), (yyval.tconst));
      } else {
        (yyval.tconst) = NULL;
      }
    }
#line 2091 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 673 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => tok_int_constant");
      (yyval.tconstv) = new t_const_value();
      (yyval.tconstv)->set_bool((yyvsp[0].iconst));
    }
#line 2101 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 679 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("constvalue => tok_int_constant");
      (yyval.tconstv) = new t_const_value();
      (yyval.tconstv)->set_integer((yyvsp[0].iconst));
      if (!g_allow_64bit_consts && ((yyvsp[0].iconst) < INT32_MIN || (yyvsp[0].iconst) > INT32_MAX)) {
        pwarning(1, "64-bit constant \"%" PRIi64 "\" may not work in all languages.", (yyvsp[0].iconst));
      }
    }
#line 2114 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 688 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => tok_dub_constant");
      (yyval.tconstv) = new t_const_value();
      (yyval.tconstv)->set_double((yyvsp[0].dconst));
    }
#line 2124 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 694 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => tok_literal");
      (yyval.tconstv) = new t_const_value((yyvsp[0].id));
    }
#line 2133 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 699 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => tok_identifier");
      t_const* constant = g_scope_cache->get_constant((yyvsp[0].id));
      if (!constant) {
        constant = g_scope_cache->get_constant(g_program->get_name() + "." + (yyvsp[0].id));
      }
      if (constant != nullptr) {
        // Copy const_value to perform isolated mutations
        t_const_value* const_value = constant->get_value();
        (yyval.tconstv) = new t_const_value(*const_value);
      } else {
        if (g_parse_mode == PROGRAM) {
          pwarning(1, "Constant strings should be quoted: %s", (yyvsp[0].id));
        }
        (yyval.tconstv) = new t_const_value((yyvsp[0].id));
      }
    }
#line 2155 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 717 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => ConstList");
      (yyval.tconstv) = (yyvsp[0].tconstv);
    }
#line 2164 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 722 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstValue => ConstMap");
      (yyval.tconstv) = (yyvsp[0].tconstv);
    }
#line 2173 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 729 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstList => [ ConstListContents ]");
      (yyval.tconstv) = (yyvsp[-1].tconstv);
    }
#line 2182 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 736 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstListContents => ConstListContents ConstValue CommaOrSemicolonOptional");
      (yyval.tconstv) = (yyvsp[-2].tconstv);
      (yyval.tconstv)->add_list((yyvsp[-1].tconstv));
    }
#line 2192 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 742 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstListContents =>");
      (yyval.tconstv) = new t_const_value();
      (yyval.tconstv)->set_list();
    }
#line 2202 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 750 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstMap => { ConstMapContents }");
      (yyval.tconstv) = (yyvsp[-1].tconstv);
    }
#line 2211 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 757 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstMapContents => ConstMapContents ConstValue CommaOrSemicolonOptional");
      (yyval.tconstv) = (yyvsp[-4].tconstv);
      (yyval.tconstv)->add_map((yyvsp[-3].tconstv), (yyvsp[-1].tconstv));
    }
#line 2221 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 763 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ConstMapContents =>");
      (yyval.tconstv) = new t_const_value();
      (yyval.tconstv)->set_map();
    }
#line 2231 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 771 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.iconst) = struct_is_struct;
    }
#line 2239 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 775 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.iconst) = struct_is_union;
    }
#line 2247 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 781 "thrifty.yy" /* yacc.c:1646  */
    {
        lineno_stack.push(LineType::kStruct, yylineno);
    }
#line 2255 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 785 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Struct -> tok_struct tok_identifier { FieldList }");
      (yyvsp[-2].tstruct)->set_union((yyvsp[-6].iconst) == struct_is_union);
      (yyval.tstruct) = (yyvsp[-2].tstruct);
      (yyval.tstruct)->set_name((yyvsp[-4].id));
      (yyval.tstruct)->set_lineno(lineno_stack.pop(LineType::kStruct));
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.tstruct)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      }
      y_field_val = -1;
    }
#line 2272 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 800 "thrifty.yy" /* yacc.c:1646  */
    {
      lineno_stack.push(LineType::kXception, yylineno);
    }
#line 2280 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 804 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Xception -> tok_xception tok_identifier { FieldList }");
      (yyvsp[-2].tstruct)->set_name((yyvsp[-4].id));
      (yyvsp[-2].tstruct)->set_xception(true);
      (yyval.tstruct) = (yyvsp[-2].tstruct);
      (yyval.tstruct)->set_lineno(lineno_stack.pop(LineType::kXception));
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.tstruct)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      }

      const char* annotations[] = {"message", "code"};
      for (auto& annotation: annotations) {
        if (g_parse_mode == PROGRAM
            && (yyval.tstruct)->has_field_named(annotation)
            && (yyval.tstruct)->annotations_.find(annotation) != (yyval.tstruct)->annotations_.end()
            && strcmp(annotation, (yyval.tstruct)->annotations_.find(annotation)->second.c_str()) != 0) {
          pwarning(1, "Some generators (eg. PHP) will ignore annotation '%s' "
                      "as it is also used as field", annotation);
        }
      }

      // Check that value of "message" annotation is
      // - a valid member of struct
      // - of type STRING
      if (g_parse_mode == PROGRAM
          && (yyval.tstruct)->annotations_.find("message") != (yyval.tstruct)->annotations_.end()) {
        const std::string v = (yyval.tstruct)->annotations_.find("message")->second;

        if (!(yyval.tstruct)->has_field_named(v.c_str())) {
          failure("member specified as exception 'message' should be a valid"
                  " struct member, '%s' in '%s' is not", v.c_str(), (yyvsp[-4].id));
        }

        auto field = (yyval.tstruct)->get_field_named(v.c_str());
        if (!field->get_type()->is_string()) {
          failure("member specified as exception 'message' should be of type "
                  "STRING, '%s' in '%s' is not", v.c_str(), (yyvsp[-4].id));
        }
      }

      y_field_val = -1;
    }
#line 2328 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 850 "thrifty.yy" /* yacc.c:1646  */
    {
      lineno_stack.push(LineType::kService, yylineno);
    }
#line 2336 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 854 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Service -> tok_service tok_identifier { FunctionList }");
      (yyval.tservice) = (yyvsp[-3].tservice);
      (yyval.tservice)->set_name((yyvsp[-7].id));
      (yyval.tservice)->set_extends((yyvsp[-6].tservice));
      (yyval.tservice)->set_lineno(lineno_stack.pop(LineType::kService));
      if ((yyvsp[0].ttype)) {
        (yyval.tservice)->annotations_ = (yyvsp[0].ttype)->annotations_;
      }
    }
#line 2351 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 866 "thrifty.yy" /* yacc.c:1646  */
    {
       g_arglist = 1;
    }
#line 2359 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 871 "thrifty.yy" /* yacc.c:1646  */
    {
       g_arglist = 0;
    }
#line 2367 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 877 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Extends -> tok_extends tok_identifier");
      (yyval.tservice) = NULL;
      if (g_parse_mode == PROGRAM) {
        (yyval.tservice) = g_scope_cache->get_service((yyvsp[0].id));
        if (!(yyval.tservice)) {
          (yyval.tservice) = g_scope_cache->get_service(g_program->get_name() + "." + (yyvsp[0].id));
        }
        if ((yyval.tservice) == NULL) {
          yyerror("Service \"%s\" has not been defined.", (yyvsp[0].id));
          exit(1);
        }
      }
    }
#line 2386 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 892 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tservice) = NULL;
    }
#line 2394 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 898 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionList -> FunctionList Function");
      (yyval.tservice) = (yyvsp[-1].tservice);
      (yyvsp[-1].tservice)->add_function((yyvsp[0].tfunction));
    }
#line 2404 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 904 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionList -> ");
      (yyval.tservice) = new t_service(g_program);
    }
#line 2413 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 911 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyvsp[-4].tstruct)->set_name(std::string((yyvsp[-6].id)) + "_args");
      auto* rettype = (yyvsp[-7].ttype);
      auto* arglist = (yyvsp[-4].tstruct);
      auto* func = new t_function(rettype, (yyvsp[-6].id), arglist, (yyvsp[-2].tstructpair)->first, (yyvsp[-2].tstructpair)->second, (yyvsp[-1].ttype), (yyvsp[-8].tbool));
      (yyval.tfunction) = func;

      if ((yyvsp[-9].dtext) != NULL) {
        (yyval.tfunction)->set_doc((yyvsp[-9].dtext));
      }
      (yyval.tfunction)->set_lineno(yylineno);
      y_field_val = -1;
    }
#line 2431 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 928 "thrifty.yy" /* yacc.c:1646  */
    {
    pdebug("MaybeStreamAndParamList -> PubsubStreamType tok ParamList");
    t_struct* paramlist = (yyvsp[0].tstruct);
    t_field* stream_field = new t_field((yyvsp[-3].ttype), (yyvsp[-2].id), 0);
    paramlist->set_stream_field(stream_field);
    (yyval.tstruct) = paramlist;
  }
#line 2443 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 936 "thrifty.yy" /* yacc.c:1646  */
    {
    pdebug("MaybeStreamAndParamList -> PubsubStreamType tok");
    t_struct* paramlist = (yyvsp[0].tstruct);
    t_field* stream_field = new t_field((yyvsp[-2].ttype), (yyvsp[-1].id), 0);
    paramlist->set_stream_field(stream_field);
    (yyval.tstruct) = paramlist;
  }
#line 2455 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 944 "thrifty.yy" /* yacc.c:1646  */
    {
    (yyval.tstruct) = (yyvsp[0].tstruct);
  }
#line 2463 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 950 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ParamList -> ParamList , Param");
      (yyval.tstruct) = (yyvsp[-1].tstruct);
      if (!((yyval.tstruct)->append((yyvsp[0].tfield)))) {
        yyerror("Parameter identifier %d for \"%s\" has already been used", (yyvsp[0].tfield)->get_key(), (yyvsp[0].tfield)->get_name().c_str());
        exit(1);
      }
    }
#line 2476 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 959 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tstruct) = (yyvsp[0].tstruct);
    }
#line 2484 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 964 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("EmptyParamList -> nil");
      t_struct* paramlist = new t_struct(g_program);
      paramlist->set_paramlist(true);
      (yyval.tstruct) = paramlist;
    }
#line 2495 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 973 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Param -> Field");
      (yyval.tfield) = (yyvsp[0].tfield);
    }
#line 2504 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 980 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tbool) = true;
    }
#line 2512 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 984 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tbool) = false;
    }
#line 2520 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 990 "thrifty.yy" /* yacc.c:1646  */
    {
			(yyval.tstructpair) = new t_structpair((yyvsp[-1].tstruct), (yyvsp[0].tstruct));
		}
#line 2528 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 994 "thrifty.yy" /* yacc.c:1646  */
    {
			(yyval.tstructpair) = new t_structpair((yyvsp[0].tstruct), nullptr);
		}
#line 2536 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 998 "thrifty.yy" /* yacc.c:1646  */
    {
			(yyval.tstructpair) = new t_structpair(new t_struct(g_program), (yyvsp[0].tstruct));
		}
#line 2544 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 1001 "thrifty.yy" /* yacc.c:1646  */
    {
			(yyval.tstructpair) = new t_structpair(new t_struct(g_program), nullptr);
		}
#line 2552 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 1007 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("Throws -> tok_throws ( FieldList )");
      (yyval.tstruct) = (yyvsp[-1].tstruct);
    }
#line 2561 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 1013 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ClientThrows -> 'client throws' ( FieldList )");
      (yyval.tstruct) = (yyvsp[-1].tstruct);
    }
#line 2570 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 1020 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FieldList -> FieldList , Field");
      (yyval.tstruct) = (yyvsp[-1].tstruct);
      if (!((yyval.tstruct)->append((yyvsp[0].tfield)))) {
        yyerror("Field identifier %d for \"%s\" has already been used", (yyvsp[0].tfield)->get_key(), (yyvsp[0].tfield)->get_name().c_str());
        exit(1);
      }
    }
#line 2583 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 1029 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FieldList -> ");
      (yyval.tstruct) = new t_struct(g_program);
    }
#line 2592 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 1036 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("tok_int_constant : Field -> FieldType tok_identifier");
      if ((yyvsp[-6].tfieldid).auto_assigned) {
        pwarning(1, "No field key specified for %s, resulting protocol may have conflicts or not be backwards compatible!", (yyvsp[-3].id));
        if (g_strict >= 192) {
          yyerror("Implicit field keys are deprecated and not allowed with -strict");
          exit(1);
        }
      }

      (yyval.tfield) = new t_field((yyvsp[-4].ttype), (yyvsp[-3].id), (yyvsp[-6].tfieldid).value);
      (yyval.tfield)->set_req((yyvsp[-5].ereq));
      (yyval.tfield)->set_lineno(lineno_stack.pop(LineType::kField));
      if ((yyvsp[-2].tconstv) != NULL) {
        validate_field_value((yyval.tfield), (yyvsp[-2].tconstv));
        (yyval.tfield)->set_value((yyvsp[-2].tconstv));
      }
      if ((yyvsp[-7].dtext) != NULL) {
        (yyval.tfield)->set_doc((yyvsp[-7].dtext));
      }
      if ((yyvsp[-1].ttype) != NULL) {
        for (const auto& it : (yyvsp[-1].ttype)->annotations_) {
          if (it.first == "cpp.ref" || it.first == "cpp2.ref") {
            if ((yyvsp[-5].ereq) != t_field::T_OPTIONAL) {
              pwarning(1, "cpp.ref field must be optional if it is recursive");
            }
            break;
          }
        }
        (yyval.tfield)->annotations_ = (yyvsp[-1].ttype)->annotations_;
        delete (yyvsp[-1].ttype);
      }
    }
#line 2630 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 1072 "thrifty.yy" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].iconst) <= 0) {
        if (g_allow_neg_field_keys) {
          /*
           * g_allow_neg_field_keys exists to allow users to add explicitly
           * specified key values to old .thrift files without breaking
           * protocol compatibility.
           */
          if ((yyvsp[-1].iconst) != y_field_val) {
            /*
             * warn if the user-specified negative value isn't what
             * thrift would have auto-assigned.
             */
            pwarning(1, "Negative field key (%d) differs from what would be "
                     "auto-assigned by thrift (%d).", (yyvsp[-1].iconst), y_field_val);
          }
          /*
           * Leave $1 as-is, and update y_field_val to be one less than $1.
           * The FieldList parsing will catch any duplicate key values.
           */
          y_field_val = (yyvsp[-1].iconst) - 1;
          (yyval.tfieldid).value = (yyvsp[-1].iconst);
          (yyval.tfieldid).auto_assigned = false;
        } else {
          pwarning(1, "Nonpositive value (%d) not allowed as a field key.",
                   (yyvsp[-1].iconst));
          (yyval.tfieldid).value = y_field_val--;
          (yyval.tfieldid).auto_assigned = true;
        }
      } else {
        (yyval.tfieldid).value = (yyvsp[-1].iconst);
        (yyval.tfieldid).auto_assigned = false;
      }
      lineno_stack.push(LineType::kField, yylineno);
    }
#line 2670 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 1108 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tfieldid).value = y_field_val--;
      (yyval.tfieldid).auto_assigned = true;
      lineno_stack.push(LineType::kField, yylineno);
    }
#line 2680 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 1116 "thrifty.yy" /* yacc.c:1646  */
    {
      if (g_arglist) {
        if (g_parse_mode == PROGRAM) {
          pwarning(1, "required keyword is ignored in argument lists.");
        }
        (yyval.ereq) = t_field::T_OPT_IN_REQ_OUT;
      } else {
        (yyval.ereq) = t_field::T_REQUIRED;
      }
    }
#line 2695 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 1127 "thrifty.yy" /* yacc.c:1646  */
    {
      if (g_arglist) {
        if (g_parse_mode == PROGRAM) {
          pwarning(1, "optional keyword is ignored in argument lists.");
        }
        (yyval.ereq) = t_field::T_OPT_IN_REQ_OUT;
      } else {
        (yyval.ereq) = t_field::T_OPTIONAL;
      }
    }
#line 2710 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 1138 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.ereq) = t_field::T_OPT_IN_REQ_OUT;
    }
#line 2718 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 1144 "thrifty.yy" /* yacc.c:1646  */
    {
      if (g_parse_mode == PROGRAM) {
        (yyval.tconstv) = (yyvsp[0].tconstv);
      } else {
        (yyval.tconstv) = NULL;
      }
    }
#line 2730 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 1152 "thrifty.yy" /* yacc.c:1646  */
    {
      (yyval.tconstv) = NULL;
    }
#line 2738 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 1158 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionType -> PubsubStreamType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2747 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 1163 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionType -> FieldType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2756 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 1168 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionType -> tok_void");
      (yyval.ttype) = g_type_void;
    }
#line 2765 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 1175 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("PubsubStreamType -> tok_stream FieldType");
      (yyval.ttype) = new t_pubsub_stream((yyvsp[0].ttype));
    }
#line 2774 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 1182 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FieldType -> tok_identifier");
      if (g_parse_mode == INCLUDES) {
        // Ignore identifiers in include mode
        (yyval.ttype) = NULL;
      } else {
        // Lookup the identifier in the current scope
        (yyval.ttype) = g_scope_cache->get_type((yyvsp[-1].id));
        if (!(yyval.ttype)) {
          (yyval.ttype) = g_scope_cache->get_type(g_program->get_name() + "." + (yyvsp[-1].id));
        }
        if ((yyval.ttype) == NULL || (yyvsp[0].ttype) != NULL) {
          /*
           * Either this type isn't yet declared, or it's never
             declared.  Either way allow it and we'll figure it out
             during generation.
           */
          (yyval.ttype) = new t_typedef(g_program, (yyvsp[-1].id), g_scope_cache);
          if ((yyvsp[0].ttype) != NULL) {
            (yyval.ttype)->annotations_ = (yyvsp[0].ttype)->annotations_;
            delete (yyvsp[0].ttype);
          }
        }
      }
    }
#line 2804 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 1208 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FieldType -> BaseType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2813 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 1213 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FieldType -> ContainerType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2822 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 1219 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> SimpleBaseType TypeAnnotations");
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.ttype) = new t_base_type(*static_cast<t_base_type*>((yyvsp[-1].ttype)));
        (yyval.ttype)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      } else {
        (yyval.ttype) = (yyvsp[-1].ttype);
      }
    }
#line 2837 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 1232 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_string");
      (yyval.ttype) = g_type_string;
    }
#line 2846 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 1237 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_binary");
      (yyval.ttype) = g_type_binary;
    }
#line 2855 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 1242 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_slist");
      (yyval.ttype) = g_type_slist;
    }
#line 2864 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 1247 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_bool");
      (yyval.ttype) = g_type_bool;
    }
#line 2873 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 1252 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_byte");
      (yyval.ttype) = g_type_byte;
    }
#line 2882 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 1257 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_i16");
      (yyval.ttype) = g_type_i16;
    }
#line 2891 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 1262 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_i32");
      (yyval.ttype) = g_type_i32;
    }
#line 2900 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 1267 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_i64");
      (yyval.ttype) = g_type_i64;
    }
#line 2909 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 1272 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_double");
      (yyval.ttype) = g_type_double;
    }
#line 2918 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 1277 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("BaseType -> tok_float");
      (yyval.ttype) = g_type_float;
    }
#line 2927 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 1283 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ContainerType -> SimpleContainerType TypeAnnotations");
      (yyval.ttype) = (yyvsp[-1].ttype);
      if ((yyvsp[0].ttype) != NULL) {
        (yyval.ttype)->annotations_ = (yyvsp[0].ttype)->annotations_;
        delete (yyvsp[0].ttype);
      }
    }
#line 2940 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 119:
#line 1294 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> MapType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2949 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 1299 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> HashMapType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2958 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 1304 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> SetType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2967 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 1309 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> HashSetType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2976 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 1314 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> ListType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2985 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 1319 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SimpleContainerType -> StreamType");
      (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2994 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 1326 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("MapType -> tok_map<FieldType, FieldType>");
      (yyval.ttype) = new t_map((yyvsp[-3].ttype), (yyvsp[-1].ttype), false);
    }
#line 3003 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 1333 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("HashMapType -> tok_hash_map<FieldType, FieldType>");
      (yyval.ttype) = new t_map((yyvsp[-3].ttype), (yyvsp[-1].ttype), true);
    }
#line 3012 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 1340 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("SetType -> tok_set<FieldType>");
      (yyval.ttype) = new t_set((yyvsp[-1].ttype), false);
    }
#line 3021 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 1347 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("HashSetType -> tok_hash_set<FieldType>");
      (yyval.ttype) = new t_set((yyvsp[-1].ttype), true);
    }
#line 3030 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 1354 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("ListType -> tok_list<FieldType>");
      (yyval.ttype) = new t_list((yyvsp[-1].ttype));
    }
#line 3039 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 1361 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("StreamType -> tok_stream<FieldType>");
      (yyval.ttype) = new t_stream((yyvsp[-1].ttype));
    }
#line 3048 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 1368 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotations -> ( TypeAnnotationList )");
      (yyval.ttype) = (yyvsp[-1].ttype);
    }
#line 3057 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 1373 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotations -> nil");
      (yyval.ttype) = NULL;
    }
#line 3066 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 1380 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotationList -> TypeAnnotationList , TypeAnnotation");
      (yyval.ttype) = (yyvsp[-1].ttype);
      (yyval.ttype)->annotations_[(yyvsp[0].tannot)->key] = (yyvsp[0].tannot)->val;
      delete (yyvsp[0].tannot);
    }
#line 3077 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 1387 "thrifty.yy" /* yacc.c:1646  */
    {
      /* Just use a dummy structure to hold the annotations. */
      (yyval.ttype) = new t_struct(g_program);
    }
#line 3086 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 1394 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotation TypeAnnotationValue");
      (yyval.tannot) = new t_annotation;
      (yyval.tannot)->key = (yyvsp[-2].id);
      (yyval.tannot)->val = (yyvsp[-1].id);
    }
#line 3097 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 1403 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotationValue -> = IntOrLiteral");
      (yyval.id) = (yyvsp[0].id);
    }
#line 3106 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 1408 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("TypeAnnotationValue ->");
      (yyval.id) = strdup("1");
    }
#line 3115 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 1415 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("FunctionAnnotations -> TypeAnnotations");
      (yyval.ttype) = (yyvsp[0].ttype);
      if ((yyval.ttype) == nullptr) {
        break;
      }
      auto prio_iter = (yyval.ttype)->annotations_.find("priority");
      if (prio_iter == (yyval.ttype)->annotations_.end()) {
       break;
      }
      const std::string& prio = prio_iter->second;
      const std::string prio_list[] = {"HIGH_IMPORTANT", "HIGH", "IMPORTANT",
                                       "NORMAL", "BEST_EFFORT"};
      const auto end = prio_list + sizeof(prio_list)/sizeof(prio_list[0]);
      if (std::find(prio_list, end, prio) == end) {
        std::string s;
        for (const auto& prio : prio_list) {
          s += prio + "','";
        }
        s.erase(s.length() - 3);
        failure("Bad priority '%s'. Choose one of '%s'.",
                prio.c_str(), s.c_str());
      }
    }
#line 3144 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 1442 "thrifty.yy" /* yacc.c:1646  */
    {
      pdebug("IntOrLiteral -> tok_literal");
      (yyval.id) = (yyvsp[0].id);
    }
#line 3153 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 1448 "thrifty.yy" /* yacc.c:1646  */
    {
      char buf[21];  // max len of int64_t as string + null terminator
      pdebug("IntOrLiteral -> tok_bool_constant");
      sprintf(buf, "%" PRIi64, (yyvsp[0].iconst));
      (yyval.id) = strdup(buf);
    }
#line 3164 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 1456 "thrifty.yy" /* yacc.c:1646  */
    {
      char buf[21];  // max len of int64_t as string + null terminator
      pdebug("IntOrLiteral -> tok_int_constant");
      sprintf(buf, "%" PRIi64, (yyvsp[0].iconst));
      (yyval.id) = strdup(buf);
    }
#line 3175 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
    break;


#line 3179 "/home/hemant/fbthrift/thrift/compiler/thrifty.cc" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1463 "thrifty.yy" /* yacc.c:1906  */

