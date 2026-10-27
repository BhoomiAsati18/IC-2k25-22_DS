
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << '\n';

    dq.pop_front();
    dq.pop_back();

    cout << "After deletion: ";
    for (int x : dq)
        cout << x << " ";
    cout << '\n';

    cout << "Front: " << dq.front() << '\n';
    cout << "Rear: " << dq.back() << '\n';

    return 0;
}
