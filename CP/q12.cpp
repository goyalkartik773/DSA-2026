#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        vector<bool> used(n + 1, false);

        p[n] = 1;
        used[1] = true;

        for (int i = 2; i <= n - 1; i++) {
            int val = i ^ 1;
            p[i] = val;
            used[val] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                p[1] = i;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
