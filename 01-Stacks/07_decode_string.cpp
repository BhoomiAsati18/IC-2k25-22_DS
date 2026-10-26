
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string decodeString(const string& s) {
    stack<int> counts;
    stack<string> previousStrings;

    string current;
    int number = 0;

    for (char ch : s) {
        if (isdigit(static_cast<unsigned char>(ch))) {
            number = number * 10 + (ch - '0');
        }
        else if (ch == '[') {
            counts.push(number);
            previousStrings.push(current);

            number = 0;
            current.clear();
        }
        else if (ch == ']') {
            if (counts.empty() || previousStrings.empty()) {
                throw runtime_error("Invalid expression");
            }

            int repeat = counts.top();
            counts.pop();

            string previous = previousStrings.top();
            previousStrings.pop();

            string repeated;
            for (int i = 0; i < repeat; ++i) {
                repeated += current;
            }

            current = previous + repeated;
        }
        else {
            if (!isalpha(static_cast<unsigned char>(ch))) {
                throw runtime_error("Invalid character");
            }
            current += ch;
        }
    }

    if (!counts.empty() || !previousStrings.empty()) {
        throw runtime_error("Unmatched opening bracket");
    }

    return current;
}

int main() {
    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    try {
        cout << "Decoded string: " << decodeString(s) << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
