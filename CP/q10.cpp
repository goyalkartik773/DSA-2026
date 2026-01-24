#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, h, l;
        cin >> n >> h >> l;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int af = 0, bs = 0, cmn = 0;

        for(int x : arr){
            if(x <= h && x <= l) cmn++;
            else if(x <= h) af++;
            else if(x <= l) bs++;
        }

        int ans = min({
            af + cmn,
            bs + cmn,
            (af + bs + cmn) / 2
        });

        cout << ans << "\n";
    }
}
