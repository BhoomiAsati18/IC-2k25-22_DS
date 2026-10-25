
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int &x : h) cin >> x;

    stack<int> st;
    long long best = 0;

    for (int i = 0; i <= n; ++i) {
        int cur = (i == n ? 0 : h[i]);

        while (!st.empty() && h[st.top()] > cur) {
            int height = h[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            best = max(best, 1LL * height * width);
        }

        st.push(i);
    }

    cout << "Maximum rectangle area: " << best << '\n';
    return 0;
}
