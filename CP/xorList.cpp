#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* both;

    Node(int val) {
        data = val;
        both = NULL;
    }
};
Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

class XORLinkedList {
private:
    Node* head;
    Node* tail;

public:
    XORLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at head
    void insertHead(int val) {
        Node* newNode = new Node(val);

        newNode->both = head; // XOR(NULL, head)

        if (head != NULL) {
            Node* next = XOR(NULL, head->both);
            head->both = XOR(newNode, next);
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    // Insert at tail
    void insertTail(int val) {
        Node* newNode = new Node(val);

        newNode->both = tail; // XOR(tail, NULL)

        if (tail != NULL) {
            Node* prev = XOR(tail->both, NULL);
            tail->both = XOR(prev, newNode);
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    // Delete from head
    void deleteHead() {
        if (head == NULL) return;

        Node* temp = head;

        Node* next = XOR(NULL, head->both);

        if (next != NULL) {
            Node* nextNext = XOR(head, next->both);
            next->both = XOR(NULL, nextNext);
        } else {
            tail = NULL;
        }

        head = next;
        delete temp;
    }
    void deleteTail() {
        if (tail == NULL) return;

        Node* temp = tail;

        Node* prev = XOR(tail->both, NULL);

        if (prev != NULL) {
            Node* prevPrev = XOR(prev->both, tail);
            prev->both = XOR(prevPrev, NULL);
        } else {
            head = NULL;
        }

        tail = prev;
        delete temp;
    }

    // Traverse forward
    void traverse() {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            cout << curr->data << " ";

            Node* next = XOR(prev, curr->both);

            prev = curr;
            curr = next;
        }
        cout << endl;
    }
};

int main() {
    XORLinkedList list;

    list.insertHead(10);
    list.insertHead(5);
    list.insertTail(20);
    list.insertTail(30);

    cout << "List: ";
    list.traverse();

    list.deleteHead();
    cout << "After deleting head: ";
    list.traverse();

    list.deleteTail();
    cout << "After deleting tail: ";
    list.traverse();

    return 0;
}
