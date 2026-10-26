
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);

    int longest = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            st.pop();

            if (st.empty()) {
                st.push(i);
            }
            else {
                longest = max(longest, i - st.top());
            }
        }
        else {
            throw invalid_argument(
                "Input must contain only '(' and ')'");
        }
    }

    return longest;
}

int main() {
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    try {
        cout << "Longest valid length: "
             << longestValidParentheses(s) << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
