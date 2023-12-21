// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "smiles_grammar.hh"


// Unqualified %code blocks.
#line 29 "smiles_grammar.yy"

#include <charconv>
#include <utility>

#include "smiles_scanner.h"
#include "smiles_parser.h"

#undef yylex
#define yylex token_scanner.lex

namespace {
[[nodiscard]] size_t stoi(std::string_view s) {
    size_t result;
    std::from_chars(s.data(), s.data() + s.size(), result);
    return result;
}
}


#line 66 "smiles_grammar.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "smiles_grammar.yy"
namespace smiles_parser {
#line 159 "smiles_grammar.cc"

  /// Build a parser object.
  SmilesTokenParser::SmilesTokenParser (SmilesTokenScanner& token_scanner_yyarg, SmilesASTBuilder& ast_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      token_scanner (token_scanner_yyarg),
      ast (ast_yyarg)
  {}

  SmilesTokenParser::~SmilesTokenParser ()
  {}

  SmilesTokenParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  SmilesTokenParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.copy< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  SmilesTokenParser::symbol_kind_type
  SmilesTokenParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  SmilesTokenParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  SmilesTokenParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.move< std::string_view > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  SmilesTokenParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  SmilesTokenParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  SmilesTokenParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  SmilesTokenParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  SmilesTokenParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  SmilesTokenParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  SmilesTokenParser::symbol_kind_type
  SmilesTokenParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  SmilesTokenParser::symbol_kind_type
  SmilesTokenParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  SmilesTokenParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  SmilesTokenParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  SmilesTokenParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  SmilesTokenParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  SmilesTokenParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  SmilesTokenParser::symbol_kind_type
  SmilesTokenParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  SmilesTokenParser::stack_symbol_type::stack_symbol_type ()
  {}

  SmilesTokenParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.YY_MOVE_OR_COPY< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  SmilesTokenParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.move< std::string_view > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  SmilesTokenParser::stack_symbol_type&
  SmilesTokenParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.copy< std::string_view > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  SmilesTokenParser::stack_symbol_type&
  SmilesTokenParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        value.move< std::string_view > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  SmilesTokenParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  SmilesTokenParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  SmilesTokenParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  SmilesTokenParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  SmilesTokenParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SmilesTokenParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SmilesTokenParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SmilesTokenParser::debug_level_type
  SmilesTokenParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SmilesTokenParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  SmilesTokenParser::state_type
  SmilesTokenParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  SmilesTokenParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  SmilesTokenParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SmilesTokenParser::operator() ()
  {
    return parse ();
  }

  int
  SmilesTokenParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 27 "smiles_grammar.yy"
{ yyla.location.begin.column = 0; }

#line 627 "smiles_grammar.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_atom_charge: // atom_charge
      case symbol_kind::S_plus_signs: // plus_signs
      case symbol_kind::S_minus_signs: // minus_signs
      case symbol_kind::S_explicit_h: // explicit_h
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ATOM_SYMBOL: // ATOM_SYMBOL
      case symbol_kind::S_NESTED_ATOM: // NESTED_ATOM
      case symbol_kind::S_H_TOKEN: // H_TOKEN
      case symbol_kind::S_ORGANIC_ATOM: // ORGANIC_ATOM
      case symbol_kind::S_BIOVIA_ATOM: // BIOVIA_ATOM
      case symbol_kind::S_CHIRAL_TAG: // CHIRAL_TAG
      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_bond_token: // bond_token
        yylhs.value.emplace< std::string_view > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 10: // sep: '.'
#line 69 "smiles_grammar.yy"
         { ast.add_sep_info(); }
#line 782 "smiles_grammar.cc"
    break;

  case 11: // branch_open: '('
#line 70 "smiles_grammar.yy"
                  { ast.add_branch_info("("); }
#line 788 "smiles_grammar.cc"
    break;

  case 12: // branch_close: ')'
#line 71 "smiles_grammar.yy"
                   { ast.add_branch_info(")"); }
#line 794 "smiles_grammar.cc"
    break;

  case 13: // bond: bond_token
#line 73 "smiles_grammar.yy"
                 { ast.add_bond(yystack_[0].value.as < std::string_view > ()); }
#line 800 "smiles_grammar.cc"
    break;

  case 14: // bond_token: '-'
#line 74 "smiles_grammar.yy"
                { yylhs.value.as < std::string_view > () = "-"; }
#line 806 "smiles_grammar.cc"
    break;

  case 15: // bond_token: '='
#line 75 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = "="; }
#line 812 "smiles_grammar.cc"
    break;

  case 16: // bond_token: '#'
#line 76 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = "#"; }
#line 818 "smiles_grammar.cc"
    break;

  case 17: // bond_token: ':'
#line 77 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = ":"; }
#line 824 "smiles_grammar.cc"
    break;

  case 18: // bond_token: '$'
#line 78 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = "$"; }
#line 830 "smiles_grammar.cc"
    break;

  case 19: // bond_token: '~'
#line 79 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = "~"; }
#line 836 "smiles_grammar.cc"
    break;

  case 20: // bond_token: '-' '>'
#line 80 "smiles_grammar.yy"
              { yylhs.value.as < std::string_view > () = "->"; }
#line 842 "smiles_grammar.cc"
    break;

  case 21: // bond_token: '<' '-'
#line 81 "smiles_grammar.yy"
              { yylhs.value.as < std::string_view > () = "<-"; }
#line 848 "smiles_grammar.cc"
    break;

  case 22: // bond_token: '\\'
#line 82 "smiles_grammar.yy"
           { yylhs.value.as < std::string_view > () = "\\"; }
#line 854 "smiles_grammar.cc"
    break;

  case 23: // bond_token: '\\' '\\'
#line 83 "smiles_grammar.yy"
                { yylhs.value.as < std::string_view > () = "\\\\"; }
#line 860 "smiles_grammar.cc"
    break;

  case 24: // bond_token: '/'
#line 84 "smiles_grammar.yy"
          { yylhs.value.as < std::string_view > () = "/"; }
#line 866 "smiles_grammar.cc"
    break;

  case 25: // atom: ATOM_SYMBOL
#line 87 "smiles_grammar.yy"
                  { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 872 "smiles_grammar.cc"
    break;

  case 26: // atom: ORGANIC_ATOM
#line 88 "smiles_grammar.yy"
                   { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 878 "smiles_grammar.cc"
    break;

  case 27: // atom: '[' complex_atom ':' atom_map_number ']'
#line 89 "smiles_grammar.yy"
                                               { ast.set_no_implicit_hs(); }
#line 884 "smiles_grammar.cc"
    break;

  case 28: // atom: '[' complex_atom ']'
#line 90 "smiles_grammar.yy"
                           { ast.set_no_implicit_hs(); }
#line 890 "smiles_grammar.cc"
    break;

  case 29: // atom_map_number: NUMBER
#line 92 "smiles_grammar.yy"
                        { ast.add_atom_map_number(stoi(yystack_[0].value.as < std::string_view > ())); }
#line 896 "smiles_grammar.cc"
    break;

  case 32: // charged_atom: uncharged_atom atom_charge
#line 96 "smiles_grammar.yy"
                                         { ast.add_atom_charge(yystack_[0].value.as < int > ()); }
#line 902 "smiles_grammar.cc"
    break;

  case 33: // atom_charge: plus_signs
#line 98 "smiles_grammar.yy"
             { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 908 "smiles_grammar.cc"
    break;

  case 34: // atom_charge: '+' NUMBER
#line 98 "smiles_grammar.yy"
                                     { yylhs.value.as < int > () = stoi(yystack_[0].value.as < std::string_view > ()); }
#line 914 "smiles_grammar.cc"
    break;

  case 35: // atom_charge: minus_signs
#line 99 "smiles_grammar.yy"
             { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 920 "smiles_grammar.cc"
    break;

  case 36: // atom_charge: '-' NUMBER
#line 99 "smiles_grammar.yy"
                                      { yylhs.value.as < int > () = -1 * stoi(yystack_[0].value.as < std::string_view > ()); }
#line 926 "smiles_grammar.cc"
    break;

  case 37: // plus_signs: '+'
#line 100 "smiles_grammar.yy"
                { yylhs.value.as < int > () = 1; }
#line 932 "smiles_grammar.cc"
    break;

  case 38: // plus_signs: plus_signs '+'
#line 100 "smiles_grammar.yy"
                                             { yylhs.value.as < int > () = yystack_[1].value.as < int > () + 1; }
#line 938 "smiles_grammar.cc"
    break;

  case 39: // minus_signs: '-'
#line 101 "smiles_grammar.yy"
                 { yylhs.value.as < int > () = -1; }
#line 944 "smiles_grammar.cc"
    break;

  case 40: // minus_signs: minus_signs '-'
#line 101 "smiles_grammar.yy"
                                                { yylhs.value.as < int > () = yystack_[1].value.as < int > () - 1; }
#line 950 "smiles_grammar.cc"
    break;

  case 43: // atom_with_hs: singular_atom explicit_h
#line 105 "smiles_grammar.yy"
                                       { ast.add_explicit_h(yystack_[0].value.as < int > ()); }
#line 956 "smiles_grammar.cc"
    break;

  case 44: // explicit_h: H_TOKEN
#line 106 "smiles_grammar.yy"
                    { yylhs.value.as < int > () = 1; }
#line 962 "smiles_grammar.cc"
    break;

  case 45: // explicit_h: H_TOKEN NUMBER
#line 106 "smiles_grammar.yy"
                                                 { yylhs.value.as < int > () = stoi(yystack_[0].value.as < std::string_view > ()); }
#line 968 "smiles_grammar.cc"
    break;

  case 49: // hydrogen_atom: H_TOKEN
#line 110 "smiles_grammar.yy"
                       { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 974 "smiles_grammar.cc"
    break;

  case 50: // hydrogen_atom: NUMBER H_TOKEN
#line 111 "smiles_grammar.yy"
                              { ast.add_atom(yystack_[0].value.as < std::string_view > ());
                                ast.add_isotope_num(stoi(yystack_[1].value.as < std::string_view > ())); }
#line 981 "smiles_grammar.cc"
    break;

  case 51: // chiral_atom: achiral_atom '@'
#line 114 "smiles_grammar.yy"
                              { ast.add_chirality_tag("@"); }
#line 987 "smiles_grammar.cc"
    break;

  case 52: // chiral_atom: achiral_atom '@' '@'
#line 115 "smiles_grammar.yy"
                                  { ast.add_chirality_tag("@@"); }
#line 993 "smiles_grammar.cc"
    break;

  case 53: // chiral_atom: achiral_atom CHIRAL_TAG
#line 116 "smiles_grammar.yy"
                                     { ast.add_chirality_class(yystack_[0].value.as < std::string_view > ()); }
#line 999 "smiles_grammar.cc"
    break;

  case 54: // chiral_atom: achiral_atom CHIRAL_TAG NUMBER
#line 117 "smiles_grammar.yy"
                                            { ast.add_chirality_class(yystack_[1].value.as < std::string_view > (), yystack_[0].value.as < std::string_view > ()); }
#line 1005 "smiles_grammar.cc"
    break;

  case 57: // non_hydrogen_isotope: NUMBER non_hydrogen_atom
#line 121 "smiles_grammar.yy"
                                               { ast.add_isotope_num(stoi(yystack_[1].value.as < std::string_view > ())); }
#line 1011 "smiles_grammar.cc"
    break;

  case 58: // non_hydrogen_atom: ATOM_SYMBOL
#line 123 "smiles_grammar.yy"
                               { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 1017 "smiles_grammar.cc"
    break;

  case 59: // non_hydrogen_atom: ORGANIC_ATOM
#line 124 "smiles_grammar.yy"
                                { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 1023 "smiles_grammar.cc"
    break;

  case 60: // non_hydrogen_atom: NESTED_ATOM
#line 125 "smiles_grammar.yy"
                               { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 1029 "smiles_grammar.cc"
    break;

  case 61: // non_hydrogen_atom: '#' NUMBER
#line 126 "smiles_grammar.yy"
                              { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 1035 "smiles_grammar.cc"
    break;

  case 62: // non_hydrogen_atom: BIOVIA_ATOM
#line 127 "smiles_grammar.yy"
                               { ast.add_atom(yystack_[0].value.as < std::string_view > ()); }
#line 1041 "smiles_grammar.cc"
    break;

  case 63: // ring_number: NUMBER
#line 129 "smiles_grammar.yy"
                    { ast.add_ring_info(yystack_[0].value.as < std::string_view > (), false); }
#line 1047 "smiles_grammar.cc"
    break;

  case 64: // ring_number: '%' NUMBER
#line 130 "smiles_grammar.yy"
                        { ast.add_ring_info(yystack_[0].value.as < std::string_view > (), true); }
#line 1053 "smiles_grammar.cc"
    break;

  case 65: // ring_number: '%' '(' NUMBER ')'
#line 131 "smiles_grammar.yy"
                                { ast.add_ring_info(yystack_[1].value.as < std::string_view > (), true); }
#line 1059 "smiles_grammar.cc"
    break;


#line 1063 "smiles_grammar.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  SmilesTokenParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  SmilesTokenParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char SmilesTokenParser::yypact_ninf_ = -36;

  const signed char SmilesTokenParser::yytable_ninf_ = -1;

  const signed char
  SmilesTokenParser::yypact_[] =
  {
       2,   -36,   -36,    76,     1,   -36,   -36,   -36,   -36,   -36,
     -36,    83,    -3,    45,   -36,    71,   -36,     4,   -36,   -36,
      -6,   -36,   -36,   -36,   -36,   -36,   -36,     7,   -36,   -36,
     -36,   -36,   -36,     0,     6,   -36,    21,     2,    50,    51,
     -36,   -36,   -36,   -36,   -36,   -36,    27,   -36,    38,    43,
     -36,    33,    49,    67,   -36,    68,    66,   -36,   -36,   -36,
     -36,    84,   -36,    28,     2,   -36,   -36,   -36,    70,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,    85,   -36,   -36,    28,
     -36,   -36,   -36
  };

  const signed char
  SmilesTokenParser::yydefact_[] =
  {
       0,    25,    26,     0,     0,     2,    58,    60,    49,    59,
      62,     0,     0,     0,    31,    30,    42,    41,    46,    48,
      47,    56,    55,     1,    63,    10,    11,    14,    15,    16,
      17,    18,    19,     0,    22,    24,     0,     0,     0,     0,
      13,     3,     6,    50,    57,    61,     0,    28,    39,    37,
      32,    33,    35,    44,    43,    53,    51,    20,    21,    23,
      64,     0,     4,     0,     0,     5,     7,    29,     0,    36,
      34,    38,    40,    45,    54,    52,     0,    12,     8,     0,
      27,    65,     9
  };

  const signed char
  SmilesTokenParser::yypgoto_[] =
  {
     -36,   -35,   -36,   -36,    16,    61,   -36,    -4,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,    89,    62
  };

  const signed char
  SmilesTokenParser::yydefgoto_[] =
  {
       0,     4,    37,    38,    78,    39,    40,     5,    68,    13,
      14,    50,    51,    52,    15,    16,    54,    17,    18,    19,
      20,    21,    22,    42
  };

  const signed char
  SmilesTokenParser::yytable_[] =
  {
      41,    23,    55,    63,     1,     1,    45,     2,     2,    53,
      24,    25,    26,    58,    27,    28,    29,    30,    31,    32,
      56,    33,    34,    35,     3,     3,    57,    59,    36,    79,
      60,     1,    61,    62,     2,    65,    67,    24,    25,    26,
      77,    27,    28,    29,    30,    31,    32,    69,    33,    34,
      35,     3,    70,     1,     1,    36,     2,     2,    71,    41,
      24,    46,    72,    27,    28,    29,    30,    31,    32,    47,
      33,    34,    35,     3,     3,    41,    73,    74,    36,     6,
       7,     8,     9,    10,    48,    11,     6,     7,    43,     9,
      10,    12,    75,    76,    80,    82,    49,    81,    12,    64,
      44,    66
  };

  const signed char
  SmilesTokenParser::yycheck_[] =
  {
       4,     0,     8,    38,     3,     3,     9,     6,     6,     5,
       9,    10,    11,    13,    13,    14,    15,    16,    17,    18,
      26,    20,    21,    22,    23,    23,    19,    21,    27,    64,
       9,     3,    11,    37,     6,    39,     9,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     9,    20,    21,
      22,    23,     9,     3,     3,    27,     6,     6,    25,    63,
       9,    16,    13,    13,    14,    15,    16,    17,    18,    24,
      20,    21,    22,    23,    23,    79,     9,     9,    27,     3,
       4,     5,     6,     7,    13,     9,     3,     4,     5,     6,
       7,    15,    26,     9,    24,    79,    25,    12,    15,    38,
      11,    39
  };

  const signed char
  SmilesTokenParser::yystos_[] =
  {
       0,     3,     6,    23,    29,    35,     3,     4,     5,     6,
       7,     9,    15,    37,    38,    42,    43,    45,    46,    47,
      48,    49,    50,     0,     9,    10,    11,    13,    14,    15,
      16,    17,    18,    20,    21,    22,    27,    30,    31,    33,
      34,    35,    51,     5,    50,     9,    16,    24,    13,    25,
      39,    40,    41,     5,    44,     8,    26,    19,    13,    21,
       9,    11,    35,    29,    33,    35,    51,     9,    36,     9,
       9,    25,    13,     9,     9,    26,     9,    12,    32,    29,
      24,    12,    32
  };

  const signed char
  SmilesTokenParser::yyr1_[] =
  {
       0,    28,    29,    29,    29,    29,    29,    29,    29,    29,
      30,    31,    32,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    35,    35,    35,    35,    36,
      37,    37,    38,    39,    39,    39,    39,    40,    40,    41,
      41,    42,    42,    43,    44,    44,    45,    45,    45,    46,
      46,    47,    47,    47,    47,    48,    48,    49,    50,    50,
      50,    50,    50,    51,    51,    51
  };

  const signed char
  SmilesTokenParser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     3,     2,     3,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     1,     1,     1,     5,     3,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       2,     2,     3,     2,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     1,     2,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const SmilesTokenParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ATOM_SYMBOL",
  "NESTED_ATOM", "H_TOKEN", "ORGANIC_ATOM", "BIOVIA_ATOM", "CHIRAL_TAG",
  "NUMBER", "'.'", "'('", "')'", "'-'", "'='", "'#'", "':'", "'$'", "'~'",
  "'>'", "'<'", "'\\\\'", "'/'", "'['", "']'", "'+'", "'@'", "'%'",
  "$accept", "mol", "sep", "branch_open", "branch_close", "bond",
  "bond_token", "atom", "atom_map_number", "complex_atom", "charged_atom",
  "atom_charge", "plus_signs", "minus_signs", "uncharged_atom",
  "atom_with_hs", "explicit_h", "singular_atom", "hydrogen_atom",
  "chiral_atom", "achiral_atom", "non_hydrogen_isotope",
  "non_hydrogen_atom", "ring_number", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  SmilesTokenParser::yyrline_[] =
  {
       0,    59,    59,    60,    61,    62,    63,    64,    65,    66,
      69,    70,    71,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    87,    88,    89,    90,    92,
      94,    94,    96,    98,    98,    99,    99,   100,   100,   101,
     101,   103,   103,   105,   106,   106,   108,   108,   108,   110,
     111,   114,   115,   116,   117,   119,   119,   121,   123,   124,
     125,   126,   127,   129,   130,   131
  };

  void
  SmilesTokenParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  SmilesTokenParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  SmilesTokenParser::symbol_kind_type
  SmilesTokenParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    15,    17,    27,     2,     2,
      11,    12,     2,    25,     2,    13,    10,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
      20,    14,    19,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,    21,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    18,     2,     2,     2,
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
       5,     6,     7,     8,     9
    };
    // Last valid token kind.
    const int code_max = 264;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "smiles_grammar.yy"
} // smiles_parser
#line 1485 "smiles_grammar.cc"

#line 132 "smiles_grammar.yy"


void smiles_parser::SmilesTokenParser::error(const location& loc, const std::string& msg) {
    auto bad_position = loc.begin.column -1;
    std::cerr << "'"<< token_scanner.d_input << "' failed because of " << msg <<
" at position: " << bad_position << std::endl;
    std::cerr << token_scanner.d_input << std::endl;
    std::cerr << std::string(bad_position, '-') << '^' << std::endl;
}
