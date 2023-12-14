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
#line 25 "smiles_grammar.yy"

#include "smiles_scanner.h"
#include "smiles_parser.h"

#undef yylex
#define yylex token_scanner.lex



#line 56 "smiles_grammar.cc"


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
#line 149 "smiles_grammar.cc"

  /// Build a parser object.
  SmilesTokenParser::SmilesTokenParser (SmilesTokenScanner& token_scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      token_scanner (token_scanner_yyarg)
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
#line 23 "smiles_grammar.yy"
{ yyla.location.begin.column = 0; }

#line 508 "smiles_grammar.cc"


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

#line 643 "smiles_grammar.cc"

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









  const signed char SmilesTokenParser::yypact_ninf_ = -8;

  const signed char SmilesTokenParser::yytable_ninf_ = -1;

  const signed char
  SmilesTokenParser::yypact_[] =
  {
      73,    -8,    -8,    95,    13,    73,    72,    -8,     4,    -8,
      -8,    -8,    -8,    11,     9,     5,    -7,     1,    -8,     2,
      -8,    -8,    -8,    -8,    73,    72,    -8,   103,    -2,    -8,
      -8,    -8,    -8,    -8,    21,    34,    -8,    48,    -1,    -8,
      -8,    -8,    -8,    -8,    30,    22,    -8,    32,     0,    35,
      49,    80,    87,    51,    73,    26,    73,    -8,    -8,    -8,
      -8,    93,    -8,    -8,    -8,    74,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    52,    94,    -8,    -8,
      77,    -8
  };

  const signed char
  SmilesTokenParser::yydefact_[] =
  {
       0,    24,    25,     0,     0,     2,     4,     6,     0,    53,
      55,    42,    54,     0,     0,     0,    28,    39,    45,    44,
      51,    50,    57,     1,     0,     5,    59,     0,    13,    14,
      15,    16,    17,    18,     0,    21,    23,     0,     0,     7,
       9,    43,    52,    56,     0,     0,    27,    32,    29,    30,
      33,    40,    48,    46,     3,     0,     0,    19,    20,    22,
      60,     0,     8,    10,    58,     0,    34,    37,    31,    35,
      36,    38,    41,    49,    47,    11,     0,     0,    26,    12,
       0,    61
  };

  const signed char
  SmilesTokenParser::yypgoto_[] =
  {
      -8,    -8,    82,    -4,    83,    -6,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    99,    -8,    75
  };

  const signed char
  SmilesTokenParser::yydefgoto_[] =
  {
       0,     4,     5,     6,    38,     7,    15,    49,    50,    16,
      17,    18,    19,    20,    21,    22,    40
  };

  const signed char
  SmilesTokenParser::yytable_[] =
  {
      39,    25,    26,    68,     1,    47,    52,     2,    51,     9,
      10,    41,    12,    23,    43,    44,    57,    48,    13,    39,
      45,     3,    24,    55,    69,    65,    37,    53,    46,    26,
      14,     1,    62,    58,     2,    66,    27,    75,    28,    29,
      30,    31,    32,    33,    67,    34,    35,    36,     3,    39,
      25,    60,    76,    37,    59,    26,    64,     1,    61,    70,
       2,    71,    27,    79,    28,    29,    30,    31,    32,    33,
      39,    34,    35,    36,     3,    26,    74,     1,     1,    37,
       2,     2,    27,    72,    28,    29,    30,    31,    32,    33,
      73,    34,    35,    36,     3,     3,    77,    78,     8,    37,
       9,    10,    11,    12,    81,    80,    54,    42,     1,    13,
      56,     2,     0,    63,     0,    28,    29,    30,    31,    32,
      33,    14,    34,    35,    36,     3
  };

  const signed char
  SmilesTokenParser::yycheck_[] =
  {
       6,     5,     3,     3,     5,    12,     4,     8,     7,     5,
       6,     7,     8,     0,     3,     6,    18,    24,    14,    25,
      15,    22,     9,    27,    24,     3,    27,    25,    23,     3,
      26,     5,    38,    12,     8,     3,    10,    11,    12,    13,
      14,    15,    16,    17,    12,    19,    20,    21,    22,    55,
      54,     3,    56,    27,    20,     3,    26,     5,    10,    24,
       8,    12,    10,    11,    12,    13,    14,    15,    16,    17,
      76,    19,    20,    21,    22,     3,    25,     5,     5,    27,
       8,     8,    10,     3,    12,    13,    14,    15,    16,    17,
       3,    19,    20,    21,    22,    22,     3,    23,     3,    27,
       5,     6,     7,     8,    27,    11,    24,     8,     5,    14,
      27,     8,    -1,    38,    -1,    12,    13,    14,    15,    16,
      17,    26,    19,    20,    21,    22
  };

  const signed char
  SmilesTokenParser::yystos_[] =
  {
       0,     5,     8,    22,    29,    30,    31,    33,     3,     5,
       6,     7,     8,    14,    26,    34,    37,    38,    39,    40,
      41,    42,    43,     0,     9,    31,     3,    10,    12,    13,
      14,    15,    16,    17,    19,    20,    21,    27,    32,    33,
      44,     7,    42,     3,     6,    15,    23,    12,    24,    35,
      36,     7,     4,    25,    30,    31,    32,    18,    12,    20,
       3,    10,    33,    44,    26,     3,     3,    12,     3,    24,
      24,    12,     3,     3,    25,    11,    31,     3,    23,    11,
      11,    27
  };

  const signed char
  SmilesTokenParser::yyr1_[] =
  {
       0,    28,    29,    29,    30,    30,    31,    31,    31,    31,
      31,    31,    31,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    33,    33,    33,    33,    34,    34,
      34,    34,    34,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    38,    38,    38,    38,    39,    39,    39,    39,
      40,    40,    41,    42,    42,    42,    42,    42,    43,    44,
      44,    44
  };

  const signed char
  SmilesTokenParser::yyr2_[] =
  {
       0,     2,     1,     3,     1,     2,     1,     2,     3,     2,
       3,     4,     5,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     5,     3,     1,     2,
       2,     3,     2,     2,     3,     2,     2,     2,     2,     1,
       2,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       1,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     5
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const SmilesTokenParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "CHIRAL_TAG",
  "SIMPLE_ATOM", "NESTED_ATOM", "H_TOKEN", "ORGANIC_ATOM", "'.'", "'('",
  "')'", "'-'", "'='", "'#'", "':'", "'$'", "'~'", "'>'", "'<'", "'\\\\'",
  "'/'", "'['", "']'", "'+'", "'@'", "'\\''", "'%'", "$accept", "mols",
  "mol", "seq", "bond", "atom", "charge_element", "plus_signs",
  "minus_signs", "h_element", "oxid_agent", "chiral_element", "element",
  "isotope", "non_isotope", "biovia_atom", "ring_number", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  SmilesTokenParser::yyrline_[] =
  {
       0,    47,    47,    48,    53,    54,    57,    58,    59,    60,
      61,    62,    63,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    81,    82,    83,    84,    88,    89,
      90,    91,    92,    93,    94,    97,    98,   100,   101,   106,
     107,   108,   111,   112,   113,   114,   117,   118,   119,   120,
     124,   125,   127,   129,   130,   131,   132,   133,   136,   139,
     140,   141
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
       2,     2,     2,     2,     2,    14,    16,    27,     2,    26,
      10,    11,     2,    24,     2,    12,     9,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    15,     2,
      19,    13,    18,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,    20,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    17,     2,     2,     2,
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
       5,     6,     7,     8
    };
    // Last valid token kind.
    const int code_max = 263;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "smiles_grammar.yy"
} // smiles_parser
#line 1064 "smiles_grammar.cc"

#line 144 "smiles_grammar.yy"


void smiles_parser::SmilesTokenParser::error(const location&, const std::string& msg) {
    std::cerr << "'"<< token_scanner.d_input << "' failed because of " << msg << std::endl;
}
