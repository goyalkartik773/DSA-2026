#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    // Build tree
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // Query sum in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0; // no overlap

        if (l <= start && end <= r)
            return tree[node]; // complete overlap

        int mid = (start + end) / 2;

        int left = query(2*node, start, mid, l, r);
        int right = query(2*node+1, mid+1, end, l, r);

        return left + right;
    }

    // Point update: arr[idx] = val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    int rangeQuery(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void pointUpdate(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    SegmentTree st(arr);

    cout << "Sum [1,4]: " << st.rangeQuery(1, 4) << endl;

    st.pointUpdate(2, 10); // arr[2] = 10

    cout << "After update, Sum [1,4]: " << st.rangeQuery(1, 4) << endl;

    return 0;
}
