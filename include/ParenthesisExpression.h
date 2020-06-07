#ifndef PARENEXPR_H
#define PARENEXPR_H

#include "Expression.h"

class ParenthesisExpression : public Expression {
private:
    class Expression *expression;

public:
    explicit ParenthesisExpression(class Expression *);

    ~ParenthesisExpression() override;

    int evaluate() override;

    void print() override;

    bool isConstant() override;

    class Expression *undoAdditionSubtraction(class Expression **exprsesion) override;

    class Expression *undoMultiplicationDivision(class Expression **expression) override;

    bool hasAdditionSubtraction() override;

    bool hasMultiplicationDivision() override;

    bool isSingleVariable() override;

    void substitute(map<char, Expression *>) override;
};

#endif
