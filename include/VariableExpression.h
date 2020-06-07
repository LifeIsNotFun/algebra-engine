#ifndef VAREXPR_H
#define VAREXPR_H

#include "Expression.h"

class VariableExpression : public Expression {
private:
    char variable;
public:

    char getVariable() const;

    explicit VariableExpression(char);

    ~VariableExpression() override;

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
