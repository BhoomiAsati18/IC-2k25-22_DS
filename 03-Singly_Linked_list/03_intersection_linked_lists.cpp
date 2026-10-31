
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* getIntersection(Node* headA, Node* headB) {
    Node* a = headA;
    Node* b = headB;

    while (a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a; // Shared node or nullptr
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    // Shared tail: 30 -> 40 -> nullptr
    Node* shared = new Node(30);
    shared->next = new Node(40);

    // List A: 10 -> 20 -> 30 -> 40
    Node* headA = new Node(10);
    headA->next = new Node(20);
    headA->next->next = shared;

    // List B: 5 -> 30 -> 40
    Node* headB = new Node(5);
    headB->next = shared;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Node* intersection = getIntersection(headA, headB);

    if (intersection != nullptr)
        cout << "Intersection node value: "
             << intersection->data << '\n';
    else
        cout << "No intersection\n";

    // Free the shared tail only once.
    delete headA->next;
    delete headA;
    delete headB;
    delete shared->next;
    delete shared;

    return 0;
}
