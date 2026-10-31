
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) const {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (Node* node : lists) {
        if (node != nullptr)
            minHeap.push(node);
    }

    Node dummy(0);
    Node* tail = &dummy;

    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();

        if (smallest->next != nullptr)
            minHeap.push(smallest->next);

        tail->next = smallest;
        tail = smallest;
    }

    tail->next = nullptr;
    return dummy.next;
}

Node* buildList(const vector<int>& values) {
    Node dummy(0);
    Node* tail = &dummy;

    for (int value : values) {
        tail->next = new Node(value);
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
    vector<Node*> lists = {
        buildList({1, 4, 7}),
        buildList({2, 5, 8}),
        buildList({3, 6, 9})
    };

    cout << "Merged list: ";
    Node* merged = mergeKLists(lists);
    printList(merged);

    deleteList(merged);
    return 0;
}
