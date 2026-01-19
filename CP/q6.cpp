#include <iostream>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (n == k) {
            cout << 0 << endl;
            continue;
        }

        int ans = -1;
        ll p = 2;
        int steps = 1;

        while (true) {
            ll x = n / p;
            ll y = n % p;

            if (k == x + 1 && y > 0) {
                ans = steps;
                break;
            }
            if (k == x && (p - y) > 0) {
                ans = steps;
                break;
            }

            if (x + 1 < k) break;

            p *= 2;
            steps++;
        }
        cout << ans << endl;
    }
    return 0;
}
