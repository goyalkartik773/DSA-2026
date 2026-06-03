#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                links[i] = NULL;
        }
    };

    Node* root;

    // Helper for delete
    bool isEmpty(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != NULL)
                return false;
        }
        return true;
    }

    Node* deleteHelper(Node* node, string& word, int depth) {
        if (!node) return NULL;

        // reached end of word
        if (depth == word.size()) {
            node->isEnd = false;

            if (isEmpty(node)) {
                delete node;
                return NULL;
            }
            return node;
        }

        int idx = word[depth] - 'a';
        node->links[idx] = deleteHelper(node->links[idx], word, depth + 1);

        if (isEmpty(node) && !node->isEnd) {
            delete node;
            return NULL;
        }

        return node;
    }

public:
    Trie() {
        root = new Node();
    }

    // Insert word
    void insert(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->links[idx])
                curr->links[idx] = new Node();

            curr = curr->links[idx];
        }

        curr->isEnd = true;
    }

    // Search exact word
    bool search(string word) {
        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->links[idx])
                return false;

            curr = curr->links[idx];
        }

        return curr->isEnd;
    }

    // Prefix check
    bool startsWith(string prefix) {
        Node* curr = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!curr->links[idx])
                return false;

            curr = curr->links[idx];
        }

        return true;
    }

    // Delete word
    void remove(string word) {
        root = deleteHelper(root, word, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    cout << "Search cat: " << trie.search("cat") << endl;
    cout << "Search cab: " << trie.search("cab") << endl;

    cout << "Prefix ca: " << trie.startsWith("ca") << endl;

    trie.remove("cat");

    cout << "After deleting cat, search cat: " << trie.search("cat") << endl;
    cout << "Search car: " << trie.search("car") << endl;

    return 0;
}
