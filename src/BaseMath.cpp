// Math.cpp
#include <iostream>
#include "../Include/Math.h"
#include <cstdarg>
#include <cmath>


unsigned int Math::BaseMath::LCM(int num, ...) {
    va_list list_of_numbers;
    va_start(list_of_numbers, num);
    unsigned int lcm = 1; // It can only be positive

    for(int i = 0; i < num; i++) {
        unsigned int current_number = va_arg(list_of_numbers, unsigned int);
        lcm = calculateLCM(lcm, current_number);
    }

    return lcm;
}

unsigned int Math::BaseMath::GCD(int num, ...) {
    va_list list_of_numbers;
    va_start(list_of_numbers, num);

    unsigned int gcd = 0;

    for(int i = 0; i < num; i++) {
        unsigned int current_number = va_arg(list_of_numbers, unsigned int);
        gcd = calculateGCD(gcd, current_number);
        std::cout << "gcd: " << gcd << '\n';
    }

    return gcd;
}

unsigned int Math::BaseMath::calculateLCM(unsigned int a, unsigned int b) {
    std::cout << "calculateGCD: " << (a * b) / calculateGCD(a,b) << '\n';
    return (a * b) / calculateGCD(a,b);
}

unsigned int Math::BaseMath::calculateGCD(unsigned int a, unsigned int b) {
    // Implementation of Euclidean Algorithm
    while (b!=0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
