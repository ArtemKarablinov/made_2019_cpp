//
//  calc.cpp
//  hw1_calc
//
//  Created by KARABLINOV Artem on 30/10/2019.
//  Copyright © 2019 KARABLINOV Artem. All rights reserved.
//

#define NDEBUG
#include "calc.hpp"
#include <string>

Expression* ParseAtom(std::string &str);
Expression* ParseMulDiv(std::string &str);
Expression* ParseAddSub(std::string &str);

//final fuction
double Calculate(const std::string &exp)
{
    Expression *pExpr = CreateExpression(exp);
    const double result = CalculateExp(pExpr);
    DisposeExpression(pExpr);
    return result;
}

void SkipSpaces(std::string &expression)
{
    size_t numSize = 0;
    while (numSize < expression.size()
           && (expression[numSize] == ' '))
    {
        ++numSize;
    }
    expression = expression.substr(numSize);
}


bool ParseDouble(std::string &expression, double &result)
{
    std::string remainingStr = expression;
    SkipSpaces(remainingStr);

    size_t numSize = 0;
    if (remainingStr.size() > 0 && isdigit(remainingStr[0]))
    {
        while (numSize < remainingStr.size()
               && isdigit(remainingStr[numSize]))
        {
            ++numSize;
        }
        result = std::stod(remainingStr.substr(0, numSize));
        expression = remainingStr.substr(numSize);
        return true;
    }

    return false;
}

bool ParseOperator(std::string &expression, Operation &op)
{
    std::string remainingStr = expression;
    SkipSpaces(remainingStr);
    if (remainingStr.empty())
    {
        op = Operation::nop;
        return false;
    }

    switch (remainingStr[0])
    {
    case '+':
            op = Operation::sum;
            break;
    case '-':
            op = Operation::sub;
            break;
    case '*':
            op = Operation::mul;
            break;
    case '/':
            op = Operation::div;
            break;
    default:
            op = Operation::nop;
            break;
    }

    const bool succeed = (op != Operation::nop);
    if (succeed)
    {
        expression = remainingStr.substr(1);
    }
    return succeed;
}

//parse expressions like a-b, a+b
Expression *ParseAddSub(std::string &str)
{
    Expression *left = ParseMulDiv(str);
    while (true)
    {
        Operation op = Operation::nop;

        std::string remainingStr = str;
        
        if (!ParseOperator(remainingStr, op))
        {
            return left;
        }
        switch (op)
        {
        case Operation::sum:
        case Operation::sub:
                break;
        default:
                return left;
        }
        str = remainingStr;

        Expression *right = nullptr;
        try
        {
            right = ParseMulDiv(str);
        }
        catch (...)
        {
            DisposeExpression(left);
            throw;
        }

        try
        {
            Expression *expr = new Expression;
            expr->pLeft = left;
            expr->pRight = right;
            expr->op = op;
            left = expr;
        }
        catch (...)
        {
            DisposeExpression(left);
            DisposeExpression(right);
            throw;
        }
    }

    return left;
}

//parse expressions like a*b, a/b
Expression *ParseMulDiv(std::string &str)
{
    Expression *left = ParseAtom(str);
    while (true)
    {
        Operation op = Operation::nop;
        std::string remainingStr = str;
        if (!ParseOperator(remainingStr, op))
        {
            return left;
        }
        switch (op)
        {
        case Operation::mul:
        case Operation::div:
            break;
        default:
            return left;
        }
        str = remainingStr;

        Expression *right = nullptr;
        try
        {
            right = ParseAtom(str);
        }
        catch (...)
        {
            DisposeExpression(left);
            throw;
        }

        try
        {
            Expression *expr = new Expression;
            expr->pLeft = left;
            expr->pRight = right;
            expr->op = op;
            left = expr;
        }
        catch (...)
        {
            DisposeExpression(left);
            DisposeExpression(right);
            throw;
        }
    }

    return left;
}

Expression *ParseAtom(std::string &str)
{
    Expression *expr = new Expression;
    if (!ParseDouble(str, expr->value))
    {
        DisposeExpression(expr);
        throw std::invalid_argument("Expected number at: " + str);
    }
    return expr;
}

Expression *CreateExpression(const std::string &expression)
{
    
    std::string remainingStr = expression;
    Expression *pExpr = ParseAddSub(remainingStr);

    SkipSpaces(remainingStr); // just to ensure
    if (!remainingStr.empty())
    {
        const auto message = "Unexpected symbol at: " + remainingStr;
        throw std::runtime_error(message);
    }

    return pExpr;
}


double CalculateExp(Expression *pexp){
    if (pexp -> op == Operation:: nop){
        return pexp -> value;
    };
    CalculateExp(pexp->pLeft);
    CalculateExp(pexp->pRight);
    
    switch (pexp -> op) {
        case Operation:: sum:
            pexp->value = pexp->pLeft->value + pexp->pRight->value;
            break;
        case Operation:: sub:
            pexp->value = pexp->pLeft->value - pexp->pRight->value;
            break;
        case Operation:: mul:
            pexp->value = pexp->pLeft->value * pexp->pRight->value;
            break;
        case Operation:: div:
            pexp->value = pexp->pLeft->value / pexp->pRight->value;
            break;
        case Operation::nop:
            assert(false);
            break;
    
    }
    return pexp->value;
};


void DisposeExpression(Expression *pExpression)
{
    if (pExpression)
    {
        if (pExpression->pLeft)
        {
            DisposeExpression(pExpression->pLeft);
            pExpression->pLeft = nullptr;
        }
        if (pExpression->pRight)
        {
            DisposeExpression(pExpression->pRight);
            pExpression->pRight = nullptr;
        }
        delete pExpression;
    }
}


