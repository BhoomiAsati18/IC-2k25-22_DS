
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<int> st;
    vector<bool> remove(s.size(), false);

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                remove[i] = true;
            }
        }
    }

    while (!st.empty()) {
        remove[st.top()] = true;
        st.pop();
    }

    for (int i = 0; i < (int)s.size(); ++i)
        if (!remove[i]) cout << s[i];

    cout << '\n';
    return 0;
}
