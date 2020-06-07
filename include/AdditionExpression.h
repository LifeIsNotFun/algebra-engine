#ifndef ADDEXPR_H
#define ADDEXPR_H

#include "BinaryOperatorExpression.h"

class AdditionExpression : public BinaryOperatorExpression {
private:
public:
    AdditionExpression(Expression *left, Expression *right) : BinaryOperatorExpression(left, right) {}

    int evaluate() override;

    void print() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;
};

#endif
