#include <iostream>

using namespace std;

#include "VariableExpression.h"

VariableExpression::VariableExpression(char variable) : variable(variable) {}

VariableExpression::~VariableExpression() {}

int VariableExpression::evaluate() {
    return 0;
}

void VariableExpression::print() {
    cout << variable;
}

bool VariableExpression::isConstant() {
    return false;
}

Expression *VariableExpression::undoAdditionSubtraction(class Expression **expr) {
    return this;
}

Expression *VariableExpression::undoMultiplicationDivision(class Expression **expr) {
    return this;
}

bool VariableExpression::hasAdditionSubtraction() {
    return false;
}

bool VariableExpression::hasMultiplicationDivision() {
    return false;
}

bool VariableExpression::isSingleVariable() {
    return true;
}

char VariableExpression::getVariable() const {
    return variable;
}

void VariableExpression::substitute(map<char, Expression *>) {
}
