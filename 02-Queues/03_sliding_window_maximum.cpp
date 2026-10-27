
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& a, int k) {
    vector<int> result;
    deque<int> dq; // Stores indices

    for (int i = 0; i < (int)a.size(); i++) {
        // Remove indices outside the current window.
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from the rear.
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(a[dq.front()]);
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    if (n <= 0 || k <= 0 || k > n) {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> a(n);
    cout << "Enter array elements: ";
    for (int &x : a)
        cin >> x;

    vector<int> ans = slidingWindowMaximum(a, k);

    cout << "Window maximums: ";
    for (int x : ans)
        cout << x << " ";
    cout << '\n';

    return 0;
}
