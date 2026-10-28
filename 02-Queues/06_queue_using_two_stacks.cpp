
#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class Queue {
private:
    stack<int> incoming, outgoing;

    void transfer() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        incoming.push(x);
    }

    void dequeue() {
        transfer();
        if (outgoing.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Removed: " << outgoing.top() << '\n';
        outgoing.pop();
    }

    void front() {
        transfer();
        if (outgoing.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front: " << outgoing.top() << '\n';
    }

    bool isEmpty() const {
        return incoming.empty() && outgoing.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();
    q.dequeue();
    q.enqueue(40);
    q.front();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
