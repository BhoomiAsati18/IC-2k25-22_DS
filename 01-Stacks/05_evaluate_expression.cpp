
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

class Parser {
    string s;
    size_t pos = 0;

    void spaces() {
        while (pos < s.size() &&
               isspace(static_cast<unsigned char>(s[pos])))
            ++pos;
    }

    long long expression() {
        long long value = term();

        while (true) {
            spaces();
            if (pos == s.size() ||
                (s[pos] != '+' && s[pos] != '-'))
                break;

            char op = s[pos++];
            long long rhs = term();
            value = (op == '+') ? value + rhs : value - rhs;
        }
        return value;
    }

    long long term() {
        long long value = factor();

        while (true) {
            spaces();
            if (pos == s.size() ||
                (s[pos] != '*' && s[pos] != '/'))
                break;

            char op = s[pos++];
            long long rhs = factor();

            if (op == '*') value *= rhs;
            else {
                if (rhs == 0)
                    throw runtime_error("Division by zero");
                value /= rhs;
            }
        }
        return value;
    }

    long long factor() {
        spaces();

        if (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
            char sign = s[pos++];
            long long value = factor();
            return sign == '-' ? -value : value;
        }

        if (pos < s.size() && s[pos] == '(') {
            ++pos;
            long long value = expression();
            spaces();

            if (pos == s.size() || s[pos] != ')')
                throw runtime_error("Missing closing parenthesis");

            ++pos;
            return value;
        }

        if (pos == s.size() || !isdigit(
                static_cast<unsigned char>(s[pos])))
            throw runtime_error("Expected a number");

        long long value = 0;
        while (pos < s.size() && isdigit(
                static_cast<unsigned char>(s[pos]))) {
            value = value * 10 + (s[pos++] - '0');
        }
        return value;
    }

public:
    explicit Parser(string input) : s(input) {}

    long long evaluate() {
        long long result = expression();
        spaces();

        if (pos != s.size())
            throw runtime_error("Invalid expression");

        return result;
    }
};

int main() {
    string input;
    getline(cin, input);

    try {
        Parser parser(input);
        cout << "Result: " << parser.evaluate() << '\n';
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
