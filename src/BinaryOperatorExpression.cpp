#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression *left, Expression *right) : left(left), right(right) {}

BinaryOperatorExpression::~BinaryOperatorExpression() = default;

bool BinaryOperatorExpression::isConstant() {
    return left->isConstant() && right->isConstant();
}

#include "ExpressionBuilder.h"

void BinaryOperatorExpression::substitute(map<char, Expression *> variableMap) {
    ::substitute(&left, variableMap);
    ::substitute(&right, variableMap);
}