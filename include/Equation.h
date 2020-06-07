#ifndef EQUATION_H
#define EQUATION_H

#include "ExpressionBuilder.h"

#include <map>
using std::map;

class Equation {
public:
    Expression *left, *right;

    Equation(Expression *left, Expression *right);

    ~Equation();

    void swap();

    void print();

    void arrange();

    bool hasSolvedVariable() const;

    Expression *getSolvedVariable() const;
    Expression *getSolvedVariableExpression() const;

    void substitute(const map<char, Expression *>&);
};

#endif
