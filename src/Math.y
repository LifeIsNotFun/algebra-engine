%{
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "ExpressionBuilder.h"

int yylex();
void yyerror(char const *);

void evaluateExpression(Expression *);
void arrangeEquation(Expression *, Expression *);
%}

%union {
	int number;
	char variable;
	class Expression *expression;
	class Equation *equation;
}

%token <number> NUMBER
%token <variable> VARIABLE

%token ADD SUBTRACT MULTIPLY DIVIDE POWER
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token EQUALS

%type <expression> expression
%type <equation> equation

%left ADD SUBTRACT
%left MULTIPLY DIVIDE
%right POWER

%token EVALUATE
%token ARRANGE
%token SOLVE
%token SEMICOLON

%start input

%%

input: line
	| input line
	;

line: EVALUATE expression SEMICOLON { cout << $2->evaluate() << endl; }
	| ARRANGE equation SEMICOLON { $2->arrange(); }
	;

equation: expression EQUALS expression { $$ = new Equation($1, $3); }
	;

expression: NUMBER { $$ = new NumberExpression($1); }
  	| VARIABLE { $$ = new VariableExpression($1); }
  	| expression ADD expression { $$ = buildAdditionExpression($1, $3); }
 	| expression SUBTRACT expression { $$ = buildSubtractionExpression($1, $3); }
  	| expression MULTIPLY expression { $$ = buildMultiplicationExpression($1, $3); }
  	| expression DIVIDE expression { $$ = buildDivisionExpression($1, $3); }
  	| expression POWER expression { $$ = buildPowerExpression($1, $3); }
  	| LEFT_PARENTHESIS expression RIGHT_PARENTHESIS { $$ = buildParenthesisExpression($2); }
  	;

%%

void yyerror(char const *str) {
  cout << str << endl;
}
