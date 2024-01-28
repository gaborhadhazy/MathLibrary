#include <iostream>
#include <regex>
#include <vector>

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
    Lexer(std::string input) : cursor(0), input(input) {}

    bool hasMoreTokens() {
        return cursor < input.length();
    }

    std::string match(const std::regex& regex, const std::string& inputSlice) {
        std::smatch matched;

        if (std::regex_search(inputSlice, matched, regex)) {
            std::string tokenValue = matched[0].str();
            cursor += tokenValue.length();
            return tokenValue;
        }

        return "";
    }

    std::vector<Token> getAllTokens() {
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

    std::string print_token(TokenTypes token) {
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


};
