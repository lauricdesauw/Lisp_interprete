%{
#include <cstdio>
#include <iostream>
#include <cassert>

#include "library.hh"
#include "lisp.tab.hh"

using namespace std;

%}

%option noyywrap

BLANK [ \t\n]
LINE [^\n]*\n
ALPHA [a-zA-Z]
OPERATION [-+*/.=_?><]
NUM [0-9]
TRUE "#t"
FALSE "#f"
NIL "nil"
SYMBOL ({OPERATION}|({ALPHA}({ALPHA}|{NUM})*)|{TRUE}|{FALSE})
NUMBER (-?{NUM}+)
LPAR \(
RPAR \)
STRING (\"[^\"]*\")
COMMENT (;{LINE})

%%

{BLANK}		{}
{COMMENT}	{}

{LPAR}		{return Token_lpar;}
{RPAR}		{return Token_rpar;}

{NIL}		{return Token_nil;}

{NUMBER}	{yylval.number_value = atoi(yytext);
		return Token_number;}

{SYMBOL}	{yylval.string_value = strdup(yytext);
		return Token_symbol;}

{STRING}	{yylval.string_value = strdup(yytext);
		return Token_string;}

<<EOF>>		{return Token_EOF;}

.		{clog << "Unexpected character: " <<
			(int)(yytext[0]) << endl;}
%%
