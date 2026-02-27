#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1000005;
int spf[MAXA];

void precompute() {
    for (int i = 1; i < MAXA; i++) spf[i] = i;
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int bad = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            bad = i;
            break;
        }
    }

    if (bad == -1) {
        cout << "Bob" << "\n";
        return;
    }

    // Alice wins if she can make a move on a[bad] such that
    // it stays non-decreasing OR if a[bad] is composite and
    // its factors can keep the array unsorted.
    if (spf[a[bad]] > a[bad + 1]) {
        cout << "Alice" << "\n";
    } else {
        // Special check: If spf is small, can Alice still win?
        // Actually for this specific problem, the spf check
        // on the first bad index is the standard greedy win.
        cout << "Bob" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
