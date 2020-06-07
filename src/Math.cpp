#include <iostream>

using std::cout;
using std::endl;

#include "ExpressionBuilder.h"

extern FILE *yyin;

int yyparse();

void evaluateExpression(class Expression *expr) {
    expr->print();
    cout << endl;
}

int main(int argc, char const *argv[]) {
    yyin = fopen("math.txt", "r");

    yyparse();

    fclose(yyin);

    cleanExpressionBuilder();

    return 0;
}
