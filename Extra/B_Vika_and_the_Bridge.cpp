#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];
        
        cout<<0(c)<<" ";

        vector<vector<int>> pos(k + 1);

        for(int i = 0; i < n; i++) {
            pos[c[i]].push_back(i + 1);
        }

        int ans = n;

        for(int color = 1; color <= k; color++) {
            vector<int> v;
            v.push_back(0);

            for(int x : pos[color]) v.push_back(x);

            v.push_back(n + 1);

            int max1 = 0, max2 = 0;

            for(int i = 1; i < v.size(); i++) {
                int gap = v[i] - v[i - 1] - 1;

                if(gap > max1) {
                    max2 = max1;
                    max1 = gap;
                } else if(gap > max2) {
                    max2 = gap;
                }
            }

            int cur = max(max2, max1 / 2);
            ans = min(ans, cur);
        }

        cout << ans << "\n";
    }

    return 0;
}