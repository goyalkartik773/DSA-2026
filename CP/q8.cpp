
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        long long mn = a[0];
        long long g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, a[i] - mn);
        }

        cout << g << "\n";
    }
    return 0;
}
