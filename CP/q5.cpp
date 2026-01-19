#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            long long s, k, m;
            cin >> s >> k >> m;

            long long n = m / k;
            long long start;

            if (s <= k) {
                start = s;
            }
            else {
                if (n % 2 == 0) {
                    start = s;
                } else{
                    start = k;
                }
            }

            long long elp = m % k;
            long long ans = start - elp;

            if (ans < 0) {
                cout << 0 << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}
