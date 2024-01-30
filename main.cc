#include <iostream>
#include "./Include/Math.h"
#include "./Include/utils/Lexer.h"

int main() {
    std::string input = "sin(123)";
    Lexer tokenizer(input);

    std::vector<Token> allTokens = tokenizer.getAllTokens();

    for (const Token& token : allTokens) {
        std::cout << "[";
        std::cout << tokenizer.print_token(token.type) << ", '" << token.value << "'";
        std::cout << "]" << '\n';
    }

    return 0;
}
