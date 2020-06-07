#ifndef EXPR_H
#define EXPR_H

#include <map>
using std::map;

class Expression {
private:
public:
    virtual ~Expression() = 0;

    virtual int evaluate() = 0;

    virtual void print() = 0;

    virtual bool isConstant() = 0;

    virtual Expression *undoAdditionSubtraction(class Expression **expr) = 0;

    virtual Expression *undoMultiplicationDivision(class Expression **expr) = 0;

    virtual bool hasAdditionSubtraction() = 0;

    virtual bool hasMultiplicationDivision() = 0;

    virtual bool isSingleVariable() = 0;

    virtual void substitute(map<char, Expression *>) = 0;
};

#endif
