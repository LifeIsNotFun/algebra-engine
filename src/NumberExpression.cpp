#include <iostream>

using namespace std;

#include "NumberExpression.h"

NumberExpression::NumberExpression(int number) : number(number) {}

NumberExpression::~NumberExpression() = default;

int NumberExpression::evaluate() {
    return number;
}

void NumberExpression::print() {
    cout << number;
}

bool NumberExpression::isConstant() {
    return true;
}

Expression *NumberExpression::undoAdditionSubtraction(class Expression **expr) {
    return this;
}

Expression *NumberExpression::undoMultiplicationDivision(class Expression **expr) {
    return this;
}

bool NumberExpression::hasAdditionSubtraction() {
    return false;
}

bool NumberExpression::hasMultiplicationDivision() {
    return false;
}

bool NumberExpression::isSingleVariable() {
    return false;
}

void NumberExpression::substitute(map<char, Expression *>) {
}
