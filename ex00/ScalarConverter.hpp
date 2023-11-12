#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

class ScalarConverter{
    public:
        static void convert(std::string literal);
    protected:
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter & instance);
        ScalarConverter operator=(const ScalarConverter & instance);
        virtual ~ScalarConverter(void);

};
