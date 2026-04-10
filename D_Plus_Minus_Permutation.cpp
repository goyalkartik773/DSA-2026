#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll sum_first_k(ll k) {
    return k * (k + 1) / 2;
}

ll sum_last_k(ll n, ll k) {
    return sum_first_k(n) - sum_first_k(n - k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

        ll L = lcm(x, y);

        // counts
        ll cnt_x = n / x - n / L;
        ll cnt_y = n / y - n / L;

        // maximize
        ll positive = sum_last_k(n, cnt_x);   
        ll negative = sum_first_k(cnt_y);     

        cout << (positive - negative) << "\n";
    }

    return 0;
}
