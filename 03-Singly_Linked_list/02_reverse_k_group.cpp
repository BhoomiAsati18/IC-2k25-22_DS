
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k <= 1)
        return head;

    Node* current = head;
    int count = 0;

    // Check whether a complete group of k nodes exists.
    Node* check = head;
    while (count < k && check != nullptr) {
        check = check->next;
        count++;
    }

    if (count < k)
        return head;

    Node* previous = nullptr;
    current = head;

    for (int i = 0; i < k; i++) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head->next = reverseKGroup(current, k);
    return previous;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;

    for (int i = 2; i <= 7; i++) {
        tail->next = new Node(i);
        tail = tail->next;
    }

    int k = 3;
    cout << "Original list: ";
    printList(head);

    if (k <= 0) {
        cout << "k must be positive\n";
        deleteList(head);
        return 0;
    }

    head = reverseKGroup(head, k);

    cout << "After reversing groups of " << k << ": ";
    printList(head);

    deleteList(head);
    return 0;
}
