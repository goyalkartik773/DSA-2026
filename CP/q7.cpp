#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll C[64][64];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<62; i++) {
        C[i][0] = 1;
        for(int j=1; j<=i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        int len = 0;
        while((1LL << len) < n)
        len++;

        ll ans = 0;
        if(len + 1 > k) ans++;

        for(int i=0; i<len; i++) {
            int need = max(0LL, k - i);
            for(int j=need; j<=i; j++)
                ans += C[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}
