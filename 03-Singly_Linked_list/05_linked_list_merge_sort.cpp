
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* mergeSorted(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;

    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != nullptr) ? a : b;
    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    return mergeSorted(left, right);
}

Node* buildList(const int arr[], int n) {
    Node dummy(0);
    Node* tail = &dummy;

    for (int i = 0; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return dummy.next;
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
    int arr[] = {4, 2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = buildList(arr, n);

    cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    deleteList(head);
    return 0;
}
