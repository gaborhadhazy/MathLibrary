#include <iostream>
#include "./Include/Math.h"
#include "./Include/utils/Lexer.h"

using namespace Math;

int main() {
    std::string input = "sin(123)";
    LinearEquation e1(input);
    e1.solve();

    return 0;
}
