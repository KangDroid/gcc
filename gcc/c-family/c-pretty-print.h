/* Various declarations for the C and C++ pretty-printers.
   Copyright (C) 2002-2013 Free Software Foundation, Inc.
   Contributed by Gabriel Dos Reis <gdr@integrable-solutions.net>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_C_PRETTY_PRINTER
#define GCC_C_PRETTY_PRINTER

#include "tree.h"
#include "c-family/c-common.h"
#include "pretty-print.h"


enum pp_c_pretty_print_flags
  {
     pp_c_flag_abstract = 1 << 1,
     pp_c_flag_gnu_v3 = 1 << 2,
     pp_c_flag_last_bit = 3
  };


/* The data type used to bundle information necessary for pretty-printing
   a C or C++ entity.  */
struct c_pretty_printer;

/* The type of a C pretty-printer 'member' function.  */
typedef void (*c_pretty_print_fn) (c_pretty_printer *, tree);

/* The datatype that contains information necessary for pretty-printing
   a tree that represents a C construct.  Any pretty-printer for a
   language using C syntax can derive from this datatype and reuse
   facilities provided here.  A derived pretty-printer can override
   any function listed in the vtable below.  See cp/cxx-pretty-print.h
   and cp/cxx-pretty-print.c for an example of derivation.  */
struct c_pretty_printer : pretty_printer
{
  c_pretty_printer ();

  /* Points to the first element of an array of offset-list.
     Not used yet.  */
  int *offset_list;

  pp_flags flags;

  /* These must be overridden by each of the C and C++ front-end to
     reflect their understanding of syntactic productions when they differ.  */
  c_pretty_print_fn declaration;
  c_pretty_print_fn declaration_specifiers;
  c_pretty_print_fn declarator;
  c_pretty_print_fn abstract_declarator;
  c_pretty_print_fn direct_abstract_declarator;
  c_pretty_print_fn type_specifier_seq;
  c_pretty_print_fn direct_declarator;
  c_pretty_print_fn ptr_operator;
  c_pretty_print_fn parameter_list;
  c_pretty_print_fn type_id;
  c_pretty_print_fn simple_type_specifier;
  c_pretty_print_fn function_specifier;
  c_pretty_print_fn storage_class_specifier;
  c_pretty_print_fn initializer;

  c_pretty_print_fn statement;

  c_pretty_print_fn constant;
  c_pretty_print_fn id_expression;
  c_pretty_print_fn primary_expression;
  c_pretty_print_fn postfix_expression;
  c_pretty_print_fn unary_expression;
  c_pretty_print_fn multiplicative_expression;
  c_pretty_print_fn conditional_expression;
  c_pretty_print_fn assignment_expression;
  c_pretty_print_fn expression;
};

#define pp_c_tree_identifier(PPI, ID)              \
   pp_c_identifier (PPI, IDENTIFIER_POINTER (ID))

#define pp_declaration(PP, T)           (PP)->declaration (PP, T)
#define pp_declaration_specifiers(PP, D)         \
   (PP)->declaration_specifiers (PP, D)
#define pp_abstract_declarator(PP, D)   (PP)->abstract_declarator (PP, D)
#define pp_type_specifier_seq(PP, D)    (PP)->type_specifier_seq (PP, D)
#define pp_declarator(PP, D)            (PP)->declarator (PP, D)
#define pp_direct_declarator(PP, D)     (PP)->direct_declarator (PP, D)
#define pp_direct_abstract_declarator(PP, D)      \
   (PP)->direct_abstract_declarator (PP, D)
#define pp_ptr_operator(PP, D)          (PP)->ptr_operator (PP, D)
#define pp_parameter_list(PP, T)        (PP)->parameter_list (PP, T)
#define pp_type_id(PP, D)               (PP)->type_id (PP, D)
#define pp_simple_type_specifier(PP, T) (PP)->simple_type_specifier (PP, T)
#define pp_function_specifier(PP, D)    (PP)->function_specifier (PP, D)
#define pp_storage_class_specifier(PP, D)         \
  (PP)->storage_class_specifier (PP, D);

#define pp_statement(PP, S)             (PP)->statement (PP, S)

#define pp_constant(PP, E)              (PP)->constant (PP, E)
#define pp_id_expression(PP, E)         (PP)->id_expression (PP, E)
#define pp_primary_expression(PP, E)    (PP)->primary_expression (PP, E)
#define pp_postfix_expression(PP, E)    (PP)->postfix_expression (PP, E)
#define pp_unary_expression(PP, E)      (PP)->unary_expression (PP, E)
#define pp_initializer(PP, E)           (PP)->initializer (PP, E)
#define pp_multiplicative_expression(PP, E)      \
  (PP)->multiplicative_expression (PP, E)
#define pp_conditional_expression(PP, E) (PP)->conditional_expression (PP, E)
#define pp_assignment_expression(PP, E) (PP)->assignment_expression (PP, E)
#define pp_expression(PP, E)            (PP)->expression (PP, E)


void pp_c_whitespace (c_pretty_printer *);
void pp_c_left_paren (c_pretty_printer *);
void pp_c_right_paren (c_pretty_printer *);
void pp_c_left_brace (c_pretty_printer *);
void pp_c_right_brace (c_pretty_printer *);
void pp_c_left_bracket (c_pretty_printer *);
void pp_c_right_bracket (c_pretty_printer *);
void pp_c_dot (c_pretty_printer *);
void pp_c_ampersand (c_pretty_printer *);
void pp_c_star (c_pretty_printer *);
void pp_c_arrow (c_pretty_printer *);
void pp_c_semicolon (c_pretty_printer *);
void pp_c_complement (c_pretty_printer *);
void pp_c_exclamation (c_pretty_printer *);
void pp_c_space_for_pointer_operator (c_pretty_printer *, tree);

/* Declarations.  */
void pp_c_tree_decl_identifier (c_pretty_printer *, tree);
void pp_c_function_definition (c_pretty_printer *, tree);
void pp_c_attributes (c_pretty_printer *, tree);
void pp_c_attributes_display (c_pretty_printer *, tree);
void pp_c_cv_qualifiers (c_pretty_printer *pp, int qualifiers, bool func_type);
void pp_c_type_qualifier_list (c_pretty_printer *, tree);
void pp_c_parameter_type_list (c_pretty_printer *, tree);
void pp_c_declaration (c_pretty_printer *, tree);
void pp_c_declaration_specifiers (c_pretty_printer *, tree);
void pp_c_declarator (c_pretty_printer *, tree);
void pp_c_direct_declarator (c_pretty_printer *, tree);
void pp_c_specifier_qualifier_list (c_pretty_printer *, tree);
void pp_c_function_specifier (c_pretty_printer *, tree);
void pp_c_type_id (c_pretty_printer *, tree);
void pp_c_direct_abstract_declarator (c_pretty_printer *, tree);
void pp_c_type_specifier (c_pretty_printer *, tree);
void pp_c_storage_class_specifier (c_pretty_printer *, tree);
/* Statements.  */
void pp_c_statement (c_pretty_printer *, tree);
/* Expressions.  */
void pp_c_expression (c_pretty_printer *, tree);
void pp_c_logical_or_expression (c_pretty_printer *, tree);
void pp_c_expression_list (c_pretty_printer *, tree);
void pp_c_constructor_elts (c_pretty_printer *, vec<constructor_elt, va_gc> *);
void pp_c_call_argument_list (c_pretty_printer *, tree);
void pp_c_unary_expression (c_pretty_printer *, tree);
void pp_c_cast_expression (c_pretty_printer *, tree);
void pp_c_postfix_expression (c_pretty_printer *, tree);
void pp_c_primary_expression (c_pretty_printer *, tree);
void pp_c_init_declarator (c_pretty_printer *, tree);
void pp_c_constant (c_pretty_printer *, tree);
void pp_c_id_expression (c_pretty_printer *, tree);
void pp_c_ws_string (c_pretty_printer *, const char *);
void pp_c_identifier (c_pretty_printer *, const char *);
void pp_c_string_literal (c_pretty_printer *, tree);

void print_c_tree (FILE *file, tree t);

#endif /* GCC_C_PRETTY_PRINTER */
