#include <iostream>
// Math.h
#ifndef UNTITLED6_MATH_H
#define UNTITLED6_MATH_H

struct EquationSide {
    double coefficients;
    double constants;
};

struct TLinearEquation {
    EquationSide left;
    EquationSide right;
};

namespace Math {
    class BaseMath {
    public:
        unsigned int LCM(int num, ...);
        unsigned int GCD(int num, ...);
        unsigned int calculateLCM(unsigned int a, unsigned int b);
        unsigned int calculateGCD(unsigned int a, unsigned int b);
        unsigned int calculateGCF(unsigned int a, unsigned int b);
    };

    class LinearEquation {
        public:
        std::string equation_string;
        TLinearEquation equation;
        LinearEquation(std::string equation) {
            equation_string = equation;

        };
        TLinearEquation solve();
    };
}

#endif // UNTITLED6_MATH_H
