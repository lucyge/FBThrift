/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 96 "thrifty.yy" /* yacc.c:1909  */

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

#line 132 "/home/hemant/fbthrift/thrift/compiler/thrifty.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HEMANT_FBTHRIFT_THRIFT_COMPILER_THRIFTY_HH_INCLUDED  */
