//
//  main.cpp
//  hw1_calc
//
//  Created by KARABLINOV Artem on 30/10/2019.
//  Copyright © 2019 KARABLINOV Artem. All rights reserved.
//

#include "calc.hpp"


int PrintExpressionResult(const std::string &expression)
{
    try
    {
        const double result = Calculate(expression);
        std::cout << "'" << expression << "' = " << result << std::endl;

    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error in '" << expression << "': " << ex.what() << std::endl;
        return 2;
    }
    return 2;
}

int main(int argc, char **argv)
{
    if (argc==2){
        PrintExpressionResult(argv[1]);
    };

    return 0;
}


