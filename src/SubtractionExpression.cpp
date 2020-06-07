#include <iostream>

using namespace std;

#include "SubtractionExpression.h"
#include "AdditionExpression.h"
#include "NumberExpression.h"

int SubtractionExpression::evaluate() {
    return left->evaluate() - right->evaluate();
}

void SubtractionExpression::print() {
    left->print();
    cout << "-";
    right->print();
}

#include "ExpressionBuilder.h"

Expression *SubtractionExpression::undoAdditionSubtraction(class Expression **expr) {
    *expr = buildAdditionExpression(*expr, right);
    return left;
}

Expression *SubtractionExpression::undoMultiplicationDivision(class Expression **expr) {
    return this;
}

bool SubtractionExpression::hasAdditionSubtraction() {
    return true;
}

bool SubtractionExpression::hasMultiplicationDivision() {
    return left->hasMultiplicationDivision() || right->hasMultiplicationDivision();
}

bool SubtractionExpression::isSingleVariable() {
    return false;
}
