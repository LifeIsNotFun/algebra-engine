#ifndef EXPRBUILDER_H
#define EXPRBUILDER_H

#include "Expression.h"
#include "AdditionExpression.h"
#include "SubtractionExpression.h"
#include "MultiplicationExpression.h"
#include "DivisionExpression.h"
#include "PowerExpression.h"
#include "ParenthesisExpression.h"
#include "NumberExpression.h"
#include "VariableExpression.h"
#include "Equation.h"

Expression *buildAdditionExpression(Expression *, Expression *);
Expression *buildSubtractionExpression(Expression *, Expression *);
Expression *buildMultiplicationExpression(Expression *, Expression *);
Expression *buildDivisionExpression(Expression *, Expression *);
Expression *buildPowerExpression(Expression *, Expression *);
Expression *buildParenthesisExpression(Expression *);

void undoAdditionSubtraction(Expression **, Expression **);
void undoMultiplicationDivision(Expression **, Expression **);

void substitute(Expression **expression, map<char, Expression *> variableMap);

void cleanExpressionBuilder();

#endif
