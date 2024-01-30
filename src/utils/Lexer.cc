// Lexer.cpp

#include "../../Include/utils/Lexer.h"

Lexer::Lexer(std::string input) : cursor(0), input(input) {}

bool Lexer::hasMoreTokens() {
    return cursor < input.length();
}

std::string Lexer::match(const std::regex& regex, const std::string& inputSlice) {
    std::smatch matched;

    if (std::regex_search(inputSlice, matched, regex)) {
        std::string tokenValue = matched[0].str();
        cursor += tokenValue.length();
        return tokenValue;
    }

    return "";
}

std::vector<Token> Lexer::getAllTokens() {
    std::vector<Token> tokens;

    while (hasMoreTokens()) {
        bool tokenFound = false;
        for (const auto& spec : TokenSpec) {
            std::string input_steps = input.substr(cursor);
            std::string tokenValue = match(spec.first, input_steps);

            if (!tokenValue.empty()) {
                tokens.push_back({spec.second, tokenValue});
                tokenFound = true;
                break;
            }
        }

        if (!tokenFound) {
            throw std::runtime_error("There were no matches for the token: " + std::string(1, input[cursor]));
        }
    }

    return tokens;
}

std::string Lexer::print_token(TokenTypes token) {
    static const std::unordered_map<TokenTypes, std::string> tokenToString = {
        {NUMBER, "NUMBER"},
        {IDENTIFIER, "IDENTIFIER"},
        {ADDITION, "ADDITION"},
        {SUBTRACTION, "SUBTRACTION"},
        {MULTIPLICATION, "MULTIPLICATION"},
        {DIVISION, "DIVISION"},
        {EXPONENTIATION, "EXPONENTIATION"},
        {PARENTHESIS_LEFT, "PARENTHESIS_LEFT"},
        {PARENTHESIS_RIGHT, "PARENTHESIS_RIGHT"},
        {END, "END"},
        {NULL_TOKEN, "NULL_TOKEN"}
    };

    auto it = tokenToString.find(token);
    return (it != tokenToString.end()) ? it->second : "UNKNOWN";
}
