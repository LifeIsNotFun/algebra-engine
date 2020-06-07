#ifndef NUMEXPR_H
#define NUMEXPR_H

#include "Expression.h"

class NumberExpression : public Expression {
private:
    int number;
public:
    explicit NumberExpression(int);

    ~NumberExpression() override;

    int evaluate() override;

    void print() override;

    bool isConstant() override;

    Expression *undoAdditionSubtraction(class Expression **expr) override;

    Expression *undoMultiplicationDivision(class Expression **expr) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;

    void substitute(map<char, Expression *>) override;
};

#endif
