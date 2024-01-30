// Lexer.h

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <regex>
#include <vector>
#include <unordered_map>

enum TokenTypes {
    NUMBER,
    IDENTIFIER,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIATION,
    PARENTHESIS_LEFT,
    PARENTHESIS_RIGHT,
    END,
    NULL_TOKEN
};

struct Token {
    TokenTypes type;
    std::string value;
};

const std::vector<std::pair<std::regex, TokenTypes>> TokenSpec = {
    {std::regex(R"(^[a-zA-Z]+)"), IDENTIFIER},
    {std::regex(R"(^(?:\d+(?:\.\d*)?|\.\d+))"), NUMBER},
    {std::regex(R"(^\s+)"), NULL_TOKEN},
    {std::regex(R"(^\+)"), ADDITION},
    {std::regex(R"(^\-)"), SUBTRACTION},
    {std::regex(R"(^\*)"), MULTIPLICATION},
    {std::regex(R"(^\/)"), DIVISION},
    {std::regex(R"(^\^)"), EXPONENTIATION},
    {std::regex(R"(^\()"), PARENTHESIS_LEFT},
    {std::regex(R"(^\))"), PARENTHESIS_RIGHT}
};

class Lexer {
public:
    std::string input;
    int cursor;
    Lexer(std::string input);
    std::vector<Token> tokens;
    
    bool hasMoreTokens();
    std::string match(const std::regex& regex, const std::string& inputSlice);
    std::vector<Token> getAllTokens();
    std::string print_token(TokenTypes token);

    void print_all_tokens();
};

#endif // LEXER_H
