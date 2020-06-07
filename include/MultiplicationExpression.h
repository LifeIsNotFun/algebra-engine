#ifndef MULEXPR_H
#define MULEXPR_H

#include "BinaryOperatorExpression.h"

class MultiplicationExpression : public BinaryOperatorExpression {
private:
public:
    MultiplicationExpression(Expression *left, Expression *right) : BinaryOperatorExpression(left, right) {}

    int evaluate() override;

    void print() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;
};

#endif
