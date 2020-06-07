#ifndef SUBEXPR_H
#define SUBEXPR_H

#include "BinaryOperatorExpression.h"

class SubtractionExpression : public BinaryOperatorExpression {
private:
public:
    SubtractionExpression(Expression *left, Expression *right) : BinaryOperatorExpression(left, right) {}

    int evaluate() override;

    void print() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;
};

#endif
