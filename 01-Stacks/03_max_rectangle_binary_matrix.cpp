
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long largestHistogram(const vector<int>& h) {
    stack<int> st;
    long long best = 0;
    int n = h.size();

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
    return best;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<int> heights(cols, 0);
    long long answer = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int bit;
            cin >> bit;
            heights[j] = bit ? heights[j] + 1 : 0;
        }
        answer = max(answer, largestHistogram(heights));
    }

    cout << "Maximum rectangle area: " << answer << '\n';
    return 0;
}
