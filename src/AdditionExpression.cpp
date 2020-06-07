#include <iostream>

using namespace std;

#include "AdditionExpression.h"
#include "SubtractionExpression.h"
#include "NumberExpression.h"

int AdditionExpression::evaluate() {
    return left->evaluate() + right->evaluate();
}

void AdditionExpression::print() {
    left->print();
    cout << "+";
    right->print();
}

#include "ExpressionBuilder.h"

Expression *AdditionExpression::undoAdditionSubtraction(class Expression **expr) {
    *expr = buildSubtractionExpression(*expr, right);
    return left;
}

Expression *AdditionExpression::undoMultiplicationDivision(class Expression **expr) {
    return this;
}

bool AdditionExpression::hasAdditionSubtraction() {
    return true;
}

bool AdditionExpression::hasMultiplicationDivision() {
    return left->hasMultiplicationDivision() || right->hasMultiplicationDivision();
}

bool AdditionExpression::isSingleVariable() {
    return false;
}
