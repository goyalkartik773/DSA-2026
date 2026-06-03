#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 4;

struct Node {
    vector<int> arr;
    Node* next;

    Node() {
        next = NULL;
    }
};

class UnrolledLinkedList {
private:
    Node* head;

    void split(Node* curr) {
        Node* newNode = new Node();

        int mid = curr->arr.size() / 2;

        for (int i = mid; i < curr->arr.size(); i++) {
            newNode->arr.push_back(curr->arr[i]);
        }

        curr->arr.resize(mid);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Merge with next if underflow
    void merge(Node* curr) {
        if (!curr || !curr->next) return;

        Node* nextNode = curr->next;

        // merge only if total size fits
        if (curr->arr.size() + nextNode->arr.size() <= MAX_SIZE) {
            for (int x : nextNode->arr) {
                curr->arr.push_back(x);
            }

            curr->next = nextNode->next;
            delete nextNode;
        }
    }

public:
    UnrolledLinkedList() {
        head = NULL;
    }

    // Traverse
    void traverse() {
        Node* curr = head;
        while (curr) {
            for (int x : curr->arr)
                cout << x << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Insert at end
    void insertEnd(int val) {
        if (!head) {
            head = new Node();
            head->arr.push_back(val);
            return;
        }

        Node* curr = head;
        while (curr->next)
            curr = curr->next;

        curr->arr.push_back(val);

        if (curr->arr.size() > MAX_SIZE)
            split(curr);
    }

    // Insert at position (0-based index)
    void insertAtPos(int pos, int val) {
        if (!head) {
            head = new Node();
            head->arr.push_back(val);
            return;
        }

        Node* curr = head;
        int count = 0;

        while (curr) {
            if (count + curr->arr.size() >= pos) {
                curr->arr.insert(curr->arr.begin() + (pos - count), val);

                if (curr->arr.size() > MAX_SIZE)
                    split(curr);

                return;
            }
            count += curr->arr.size();
            curr = curr->next;
        }

        // if pos beyond size → insert at end
        insertEnd(val);
    }

    // Delete a value
    void deleteVal(int val) {
        Node* curr = head;
        Node* prev = NULL;

        while (curr) {
            auto it = find(curr->arr.begin(), curr->arr.end(), val);

            if (it != curr->arr.end()) {
                curr->arr.erase(it);

                // remove node if empty
                if (curr->arr.empty()) {
                    if (prev == NULL)
                        head = curr->next;
                    else
                        prev->next = curr->next;

                    delete curr;
                    return;
                }

                // try merge
                merge(curr);
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    // Search value
    bool search(int val) {
        Node* curr = head;

        while (curr) {
            for (int x : curr->arr)
                if (x == val)
                    return true;

            curr = curr->next;
        }
        return false;
    }
};

int main() {
    UnrolledLinkedList ull;

    // Insert
    ull.insertEnd(10);
    ull.insertEnd(20);
    ull.insertEnd(30);
    ull.insertEnd(40);
    ull.insertEnd(50);
    ull.insertEnd(60);
    ull.insertEnd(70);

    cout << "Initial list: ";
    ull.traverse();

    // Insert at position
    ull.insertAtPos(3, 25);
    cout << "After inserting 25 at pos 3: ";
    ull.traverse();

    // Delete
    ull.deleteVal(40);
    cout << "After deleting 40: ";
    ull.traverse();

    // Search
    cout << "Search 50: " << (ull.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
