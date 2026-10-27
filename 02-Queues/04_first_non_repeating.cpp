
#include <iostream>
#include <queue>
#include <string>
#include <array>
using namespace std;

int main() {
    string stream;
    cout << "Enter character stream: ";
    cin >> stream;

    array<int, 256> frequency{};
    queue<char> q;

    cout << "Results: ";

    for (unsigned char ch : stream) {
        frequency[ch]++;
        q.push(static_cast<char>(ch));

        while (!q.empty() &&
               frequency[static_cast<unsigned char>(q.front())] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "# ";
        else
            cout << q.front() << " ";
    }

    cout << '\n';
    return 0;
}
