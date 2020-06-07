#include <cmath>
#include <iostream>

using namespace std;

#include "PowerExpression.h"

int PowerExpression::evaluate() {
    return pow(left->evaluate(), right->evaluate());
}

void PowerExpression::print() {
    left->print();
    cout << "^";
    right->print();
}

Expression *PowerExpression::undoAdditionSubtraction(class Expression **expr) {
    return this;
}

Expression *PowerExpression::undoMultiplicationDivision(class Expression **expr) {
    return this;
}

bool PowerExpression::hasAdditionSubtraction() {
    return left->hasAdditionSubtraction() || right->hasAdditionSubtraction();
}

bool PowerExpression::hasMultiplicationDivision() {
    return left->hasMultiplicationDivision() || right->hasMultiplicationDivision();
}

bool PowerExpression::isSingleVariable() {
    return false;
}
