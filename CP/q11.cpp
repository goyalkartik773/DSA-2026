#include <bits/stdc++.h>

using namespace std;

long long solve(int n, long long x) {
    long long startIdx = 0;
    long long maxProfit = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        startIdx += a * (b - 1);
        long long currProfit = (a * b) - c;

        if (currProfit > maxProfit) {
            maxProfit = currProfit;
        }
    }

    if (maxProfit <= 0) {
        return -1;
    }

    if (startIdx >= x) {
        return 0;
    }


    long long sub = x - startIdx;
    long long ans = (sub + maxProfit - 1) / maxProfit;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        cout << solve(n, x) << "\n";
    }
    return 0;
}
