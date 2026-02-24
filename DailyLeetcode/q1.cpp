#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std;

long long solve(int N, vector<long long> A) {
    sort(A.begin(), A.end());
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int len = 2; len <= N; len++) {
        for (int l = 0; l + len - 1 < N; l++) {
            int r = l + len - 1;

            long long cost = A[r] - A[l];
            long long option1 = dp[l + 1][r] + cost; // add left
            long long option2 = dp[l][r - 1] + cost; // add right

            dp[l][r] = min(option1, option2);
        }
    }

    return dp[0][N - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        cout << solve(N, A) << "\n";
    }

    return 0;
}