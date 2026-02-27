#include <bits/stdc++.h>

using namespace std;

vector<int> get_min_rotation(vector<int> v) {
    int n = v.size();
    if (n == 0) return {};
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int a = v[(i + k) % n];
        int b = v[(j + k) % n];
        if (a == b) k++;
        else {
            if (a > b) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    int start = min(i, j);
    vector<int> res(n);
    for (int idx = 0; idx < n; idx++) {
        res[idx] = v[(start + idx) % n];
    }
    return res;
}

void solve() {
    int n, x, y;
    if (!(cin >> n >> x >> y)) return;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> g1, g2;
    for (int i = 0; i < x; i++) g1.push_back(p[i]);
    for (int i = y; i < n; i++) g1.push_back(p[i]);
    for (int i = x; i < y; i++) g2.push_back(p[i]);

    vector<int> v1 = get_min_rotation(g1);
    vector<int> v2 = get_min_rotation(g2);

    int p1 = 0, p2 = 0;
    vector<int> ans;
    while (p1 < v1.size() || p2 < v2.size()) {
        if (p1 < v1.size() && p2 < v2.size()) {
            if (v1[p1] < v2[p2]) ans.push_back(v1[p1++]);
            else ans.push_back(v2[p2++]);
        } else if (p1 < v1.size()) {
            ans.push_back(v1[p1++]);
        } else {
            ans.push_back(v2[p2++]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
