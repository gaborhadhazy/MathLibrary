#include <iostream>
#include "../Include/Math.h"


Math::LinearEquation::LinearEquation(std::string equation): lexer(equation) {
    equation_string = equation;
    std::vector<Token> allTokens = lexer.getAllTokens();
    tokens = allTokens;
}

TLinearEquation Math::LinearEquation::solve() {
    lexer.print_all_tokens();
    return equation;
}