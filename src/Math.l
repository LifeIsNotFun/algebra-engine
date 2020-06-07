%{
  #include <iostream>
  using namespace std;

  #include "math.tab.h"
%}

%option noyywrap

%%

[0-9]+ { yylval.number = atoi(yytext); return NUMBER; }
[a-z] { yylval.variable = *yytext; return VARIABLE; }

"+" { return ADD; }
"-" { return SUBTRACT; }
"*" { return MULTIPLY; }
"/" { return DIVIDE; }
"^" { return POWER; }
"=" { return EQUALS; }
";" { return SEMICOLON; }

"(" { return LEFT_PARENTHESIS; }
")" { return RIGHT_PARENTHESIS; }

"EVALUATE" { return EVALUATE; }
"ARRANGE" { return ARRANGE; }

[ \n\t] { }
. { }

%%
