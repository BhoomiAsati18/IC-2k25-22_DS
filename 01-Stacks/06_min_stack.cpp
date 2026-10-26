
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> minimums;

public:
    void push(int x) {
        values.push(x);

        if (minimums.empty() || x <= minimums.top()) {
            minimums.push(x);
        }
    }

    void pop() {
        if (values.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        if (values.top() == minimums.top()) {
            minimums.pop();
        }

        values.pop();
    }

    int top() {
        if (values.empty()) {
            throw runtime_error("Stack is empty");
        }
        return values.top();
    }

    int getMin() {
        if (minimums.empty()) {
            throw runtime_error("Stack is empty");
        }
        return minimums.top();
    }
};

int main() {
    MinStack s;

    s.push(5);
    s.push(2);
    s.push(8);

    cout << "Minimum: " << s.getMin() << '\n';

    s.pop();
    cout << "Top: " << s.top() << '\n';
    cout << "Minimum: " << s.getMin() << '\n';

    s.pop();
    cout << "Minimum: " << s.getMin() << '\n';

    return 0;
}
