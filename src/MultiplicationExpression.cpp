#include <iostream>

using namespace std;

#include "MultiplicationExpression.h"
#include "DivisionExpression.h"
#include "NumberExpression.h"

int MultiplicationExpression::evaluate() {
    return left->evaluate() * right->evaluate();
}

void MultiplicationExpression::print() {
    left->print();
    cout << "*";
    right->print();
}

Expression *MultiplicationExpression::undoAdditionSubtraction(class Expression **expr) {
    return this;
}

#include "ExpressionBuilder.h"

Expression *MultiplicationExpression::undoMultiplicationDivision(class Expression **expr) {
    /* Prefer dividing by constant rather than variable expressions */
    Expression *dividend = left->isConstant() ? left : right;
    *expr = buildDivisionExpression(*expr, dividend);
    return left->isConstant() ? right : left;
}

bool MultiplicationExpression::hasAdditionSubtraction() {
    return left->hasAdditionSubtraction() || right->hasAdditionSubtraction();
}

bool MultiplicationExpression::hasMultiplicationDivision() {
    return true;
}

bool MultiplicationExpression::isSingleVariable() {
    return false;
}
