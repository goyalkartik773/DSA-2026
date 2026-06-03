#include <bits/stdc++.h>
using namespace std;

class SkipList {
private:
    struct Node {
        int val;
        vector<Node*> forward;

        Node(int v, int level) {
            val = v;
            forward.resize(level + 1, nullptr);
        }
    };

    int MAX_LEVEL;
    float P; // probability
    int level;
    Node* header;

    // random level generator
    int randomLevel() {
        int lvl = 0;
        while ((float)rand() / RAND_MAX < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    SkipList(int maxLevel = 16, float prob = 0.5) {
        MAX_LEVEL = maxLevel;
        P = prob;
        level = 0;
        header = new Node(-1, MAX_LEVEL);
    }

    // Search
    bool search(int key) {
        Node* curr = header;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < key) {
                curr = curr->forward[i];
            }
        }

        curr = curr->forward[0];

        return (curr && curr->val == key);
    }

    // Insert
    void insert(int key) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* curr = header;

        // Step 1: find position
        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < key)
                curr = curr->forward[i];
            update[i] = curr;
        }

        curr = curr->forward[0];

        // Step 2: insert only if not present
        if (!curr || curr->val != key) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++)
                    update[i] = header;
                level = rlevel;
            }

            Node* newNode = new Node(key, rlevel);

            for (int i = 0; i <= rlevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    // Delete
    void deleteKey(int key) {
        vector<Node*> update(MAX_LEVEL + 1);
        Node* curr = header;

        for (int i = level; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < key)
                curr = curr->forward[i];
            update[i] = curr;
        }

        curr = curr->forward[0];

        if (curr && curr->val == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != curr)
                    break;

                update[i]->forward[i] = curr->forward[i];
            }

            delete curr;

            // reduce level if needed
            while (level > 0 && header->forward[level] == nullptr)
                level--;
        }
    }

    // Display (level 0)
    void display() {
        Node* curr = header->forward[0];
        while (curr) {
            cout << curr->val << " ";
            curr = curr->forward[0];
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));

    SkipList sl;

    // Insert
    sl.insert(10);
    sl.insert(20);
    sl.insert(30);
    sl.insert(40);
    sl.insert(50);
    sl.insert(60);

    cout << "Skip List: ";
    sl.display();

    // Search
    cout << "Search 30: " << (sl.search(30) ? "Found" : "Not Found") << endl;

    // Delete
    sl.deleteKey(30);
    cout << "After deleting 30: ";
    sl.display();

    return 0;
}
