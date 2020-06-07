#include "Equation.h"

#include <iostream>

using std::cout;
using std::endl;

Equation::Equation(Expression *left, Expression *right) : left(left), right(right) {}

void Equation::arrange() {
    undoAdditionSubtraction(&left, &right);
    undoMultiplicationDivision(&left, &right);

    print();
}

bool Equation::hasSolvedVariable() const {
    return left->isSingleVariable() || right->isSingleVariable();
}

Expression *Equation::getSolvedVariable() const {
    if (left->isSingleVariable()) {
        return left;
    } else if (right->isSingleVariable()) {
        return right;
    }

    return nullptr;
}

Expression *Equation::getSolvedVariableExpression() const {
    assert(getSolvedVariable() != nullptr);

    if (left->isSingleVariable()) {
        return right;
    } else if (right->isSingleVariable()) {
        return left;
    }

    return nullptr;
}

void Equation::substitute(const map<char, Expression *> &variableMap) {
    ::substitute(&left, variableMap);
    ::substitute(&right, variableMap);
}

void Equation::print() {
    left->print();
    cout << "=";
    right->print();
    cout << endl;
}

void Equation::swap() {
    Expression *intermediate;
    intermediate = left;
    left = right;
    right = intermediate;
}

Equation::~Equation() = default;
