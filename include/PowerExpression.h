#ifndef POWEXPR_H
#define POWEXPR_H

#include "BinaryOperatorExpression.h"

class PowerExpression : public BinaryOperatorExpression {
private:
public:
    PowerExpression(Expression *left, Expression *right) : BinaryOperatorExpression(left, right) {}

    int evaluate() override;

    void print() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;
};

#endif
