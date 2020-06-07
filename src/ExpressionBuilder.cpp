#include "ExpressionBuilder.h"

#include <iostream>

using std::cout;
using std::endl;

#include <vector>

using std::vector;

vector<Expression *> toDelete;

Expression *buildAdditionExpression(Expression *left, Expression *right) {
    Expression *expression = new AdditionExpression(left, right);
    if (expression->isConstant()) {
        toDelete.push_back(expression);

        expression = new NumberExpression(expression->evaluate());
        toDelete.push_back(expression);
    } else {
        /* 0 + x = x */
        if (left->isConstant() && (left->evaluate() == 0)) {
            toDelete.push_back(expression);

            expression = right->isConstant() ? new NumberExpression(right->evaluate()) : right;
            toDelete.push_back(expression);
        }

        /* x + 0 = x */
        if (right->isConstant() && (right->evaluate() == 0)) {
            toDelete.push_back(expression);

            expression = left->isConstant() ? new NumberExpression(left->evaluate()) : left;
            toDelete.push_back(expression);
        }
    }

    return expression;
}

Expression *buildSubtractionExpression(Expression *left, Expression *right) {
    Expression *expression = new SubtractionExpression(left, right);
    if (expression->isConstant()) {
        toDelete.push_back(expression);

        expression = new NumberExpression(expression->evaluate());
        toDelete.push_back(expression);
    } else {
        /* 0 - x = -x */
        if (left->isConstant() && (left->evaluate() == 0)) {
            toDelete.push_back(expression);

            expression = right->isConstant() ? new NumberExpression(-1 * right->evaluate()) : right;
            toDelete.push_back(expression);
        }

        /* x - 0 = x */
        if (right->isConstant() && (right->evaluate() == 0)) {
            toDelete.push_back(expression);

            expression = left->isConstant() ? new NumberExpression(left->evaluate()) : left;
            toDelete.push_back(expression);
        }
    }

    return expression;
}

Expression *buildMultiplicationExpression(Expression *left, Expression *right) {
    Expression *expression = new MultiplicationExpression(left, right);
    if (expression->isConstant()) {
        toDelete.push_back(expression);

        expression = new NumberExpression(expression->evaluate());
        toDelete.push_back(expression);
    } else {
        /* 0 * x = 0 */
        if (left->isConstant() && (left->evaluate() == 0)) {
            toDelete.push_back(expression);
            expression = new NumberExpression(0);
        }

        /* x * 0 = 0 */
        if (right->isConstant() && (right->evaluate() == 0)) {
            toDelete.push_back(expression);
            expression = new NumberExpression(0);
        }

        toDelete.push_back(expression);
    }

    return expression;
}

Expression *buildDivisionExpression(Expression *left, Expression *right) {
    Expression *expression = new DivisionExpression(left, right);
    if (expression->isConstant()) {
        toDelete.push_back(expression);

        /* If a constant expression has a division by zero, a floating point exception will be triggered */
        expression = new NumberExpression(expression->evaluate());
        toDelete.push_back(expression);
    } else {
        /* 0 / x = 0 */
        if (left->isConstant() && (left->evaluate() == 0)) {
            toDelete.push_back(expression);
            expression = new NumberExpression(0);
        }

        /* x / 0 = 0 */
        if (right->isConstant() && (right->evaluate() == 0)) {
            toDelete.push_back(expression);
            expression = new NumberExpression(0);
        }

        toDelete.push_back(expression);
    }

    return expression;
}

Expression *buildPowerExpression(Expression *left, Expression *right) {
    Expression *expression = new PowerExpression(left, right);
    if (expression->isConstant()) {
        toDelete.push_back(expression);
        expression = new NumberExpression(expression->evaluate());
    } else {
        /* x ^ 0 = 1 */
        if (right->isConstant() && (right->evaluate() == 0)) {
            toDelete.push_back(expression);
            expression = new NumberExpression(1);
        }

        toDelete.push_back(expression);
    }

    return expression;
}

Expression *buildParenthesisExpression(Expression *expression) {
    Expression *intermediate = new ParenthesisExpression(expression);
    if (intermediate->isConstant()) {
        toDelete.push_back(intermediate);
        intermediate = new NumberExpression(intermediate->evaluate());
    }

    toDelete.push_back(intermediate);

    return intermediate;
}

void undoAdditionSubtraction(Expression **left, Expression **right) {
    while ((*left)->hasAdditionSubtraction()) {
        Expression *expression = (*left)->undoAdditionSubtraction(right);
        if (expression != *left) {
            toDelete.push_back(*left);
            *left = expression;
        }
    }
}

void undoMultiplicationDivision(Expression **left, Expression **right) {
    while ((*left)->hasMultiplicationDivision()) {
        Expression *expression = (*left)->undoMultiplicationDivision(right);
        if (expression != *left) {
            toDelete.push_back(*left);
            *left = expression;
        }
    }
}

#include <algorithm>

void cleanExpressionBuilder() {
    for (Expression *expression : toDelete) {
        if (expression != nullptr) {
            delete expression;

            for (;;) {
                auto iterator = find(toDelete.begin(), toDelete.end(), expression);
                if (iterator == toDelete.end()) {
                    break;
                }

                toDelete[distance(toDelete.begin(), iterator)] = nullptr;
            }
        }
    }
}

void substitute(Expression **expression, map<char, Expression *> variableMap) {
    if ((*expression)->isSingleVariable()) {
        auto *variableExpression = dynamic_cast<VariableExpression *>(*expression);
        auto iterator = variableMap.find(variableExpression->getVariable());
        if (iterator != variableMap.end()) {
            *expression = iterator->second;
        }
    } else {
        (*expression)->substitute(variableMap);
    }
}
