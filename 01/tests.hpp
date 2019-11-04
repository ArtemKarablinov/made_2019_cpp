//
//  tests.hpp
//  hw1_calc
//
//  Created by KARABLINOV Artem on 04/11/2019.
//  Copyright © 2019 KARABLINOV Artem. All rights reserved.
//

#ifndef tests_hpp
#define tests_hpp
#include <string>
#include <cassert>
#include <iostream>

void test(const std::string &expr, const int result, bool error);
double Calculate(const std::string &exp);
#endif /* tests_hpp */
