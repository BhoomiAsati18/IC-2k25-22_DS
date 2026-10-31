
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* findCycleStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Create a cycle: node 50 points back to node 30.
    head->next->next->next->next->next = head->next->next;

    Node* start = findCycleStart(head);

    if (start != nullptr)
        cout << "Cycle starts at node: " << start->data << '\n';
    else
        cout << "No cycle found\n";

    // Break the cycle before freeing the allocated nodes.
    Node* cycleStart = start;
    if (cycleStart != nullptr) {
        Node* last = cycleStart;
        while (last->next != cycleStart)
            last = last->next;
        last->next = nullptr;
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
