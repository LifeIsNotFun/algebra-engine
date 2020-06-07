#ifndef BINOPEXPR_H
#define BINOPEXPR_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression {
public:
    Expression *left, *right;

    BinaryOperatorExpression(Expression *, Expression *);

    ~BinaryOperatorExpression() override;

    bool isConstant() override;

    void substitute(map<char, Expression *>) override;
};

#endif
