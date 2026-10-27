
#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
private:
    vector<int> arr;
    int frontIndex, rearIndex, count, capacity;

public:
    CircularQueue(int size)
        : arr(size), frontIndex(0), rearIndex(-1),
          count(0), capacity(size) {}

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        cout << value << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Removed: " << arr[frontIndex] << '\n';
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    void front() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front: " << arr[frontIndex] << '\n';
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << '\n';
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    q.front();

    return 0;
}
