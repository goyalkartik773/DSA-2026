#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
    int n;
    cin>>n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++) {
        int gc = 0;
        int sc = 0;

        // iterating karke dekh rha ki max Count kya milta
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                gc++;
            } else if (a[j] < a[i]) {
                sc++;
            }
        }

        cout<<max(gc,sc)<<" ";
    }
    cout<<endl;
    }

    return 0;
}
