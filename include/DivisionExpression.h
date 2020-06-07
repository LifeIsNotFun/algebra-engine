#ifndef DIVEXPR_H
#define DIVEXPR_H

#include "BinaryOperatorExpression.h"

class DivisionExpression : public BinaryOperatorExpression {
private:
public:
    DivisionExpression(Expression *left, Expression *right) : BinaryOperatorExpression(left, right) {}

    int evaluate() override;

    void print() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;
};

#endif
