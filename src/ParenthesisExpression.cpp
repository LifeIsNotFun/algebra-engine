#include <iostream>

using namespace std;

#include "ParenthesisExpression.h"

ParenthesisExpression::ParenthesisExpression(class Expression *expr) : expression(expr) {}

ParenthesisExpression::~ParenthesisExpression() { delete expression; }

int ParenthesisExpression::evaluate() {
    return expression->evaluate();
}

void ParenthesisExpression::print() {
    cout << "(";
    expression->print();
    cout << ")";
}

bool ParenthesisExpression::isConstant() {
    return expression->isConstant();
}

Expression *ParenthesisExpression::undoAdditionSubtraction(class Expression **expression) {
    return ParenthesisExpression::expression->undoAdditionSubtraction(expression);
}

Expression *ParenthesisExpression::undoMultiplicationDivision(class Expression **expression) {
    return ParenthesisExpression::expression->undoMultiplicationDivision(expression);
}

bool ParenthesisExpression::hasAdditionSubtraction() {
    return expression->hasAdditionSubtraction();
}

bool ParenthesisExpression::hasMultiplicationDivision() {
    return expression->hasMultiplicationDivision();
}

bool ParenthesisExpression::isSingleVariable() {
    return expression->isSingleVariable();
}

void ParenthesisExpression::substitute(map<char, Expression *> variableMap) {
    expression->substitute(variableMap);
}
