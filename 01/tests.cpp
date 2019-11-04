//
//  tests.cpp
//  hw1_calc
//
//  Created by KARABLINOV Artem on 04/11/2019.
//  Copyright © 2019 KARABLINOV Artem. All rights reserved.
//

#include "tests.hpp"

void test(const std::string &expr, const int result){
    int res = Calculate(expr);
    if (res == result){
        std:: cout<<"Ok! Tests done."<< std:: endl;
    }
    else{
        std:: cout<<"Test not passed"<< std:: endl;
    }
};

void tests(){
    test("2+2", 4);
    test("0+ 0", 0);
    test("3/3 +23 ", 24);
};

int main(){
    
    tests();
    return 0;
}
