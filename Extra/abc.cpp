#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int MAXN = 200002;

long long fact[MAXN], inv_fact[MAXN];

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;
    inv_fact[MAXN-1] = power(fact[MAXN-1], MOD-2, MOD);
    for (int i = MAXN-2; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n || n < 0) return 0;
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

int main() {
    
    precompute();
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        long long ans = 0;
        for (int v = 1; v <= k; v++) {
            long long val = nCr(n - v, n - k);
            long long diff = (power(v, k, MOD) - power(v-1, k, MOD) + MOD) % MOD;
            ans = (ans + val % MOD * diff % MOD) % MOD;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}