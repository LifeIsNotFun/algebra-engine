#include <iostream>

using namespace std;

#include "DivisionExpression.h"
#include "MultiplicationExpression.h"
#include "NumberExpression.h"

int DivisionExpression::evaluate() {
    return left->evaluate() / right->evaluate();
}

void DivisionExpression::print() {
    left->print();
    cout << "/";
    right->print();
}

Expression *DivisionExpression::undoAdditionSubtraction(class Expression **expr) {
    return this;
}

#include "ExpressionBuilder.h"

Expression *DivisionExpression::undoMultiplicationDivision(class Expression **expr) {
    *expr = buildMultiplicationExpression(*expr, right);
    return left;
}

bool DivisionExpression::hasAdditionSubtraction() {
    return left->hasAdditionSubtraction() || right->hasAdditionSubtraction();
}

bool DivisionExpression::hasMultiplicationDivision() {
    return true;
}

bool DivisionExpression::isSingleVariable() {
    return false;
}
