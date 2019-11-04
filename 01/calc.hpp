//
//  calc.hpp
//  hw1_calc
//
//  Created by KARABLINOV Artem on 30/10/2019.
//  Copyright © 2019 KARABLINOV Artem. All rights reserved.
//

#ifndef calc_hpp
#define calc_hpp

#include <string>
#include <ctype.h>
#include <stdexcept>
#include <memory>
#include <math.h>
#include <cassert>
#include <iostream>

double Calculate(const std::string &exp);
struct Expression;
double CalculateExp(Expression* pexp);
void DisposeExpression(Expression* pexp);

Expression* CreateExpression(const std::string &str);

enum class Operation{
    nop,
    sum,
    sub,
    mul,
    div,
};

//node struct
struct Expression{
    double value = 0;
    Operation op = Operation::nop;
    Expression* pLeft = nullptr;
    Expression* pRight = nullptr;
};
#endif /* calc_hpp */
