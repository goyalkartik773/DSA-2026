#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i];

        // convert to 0-index
        vector<int> B;
        for(int i = x; i < y; i++)
            B.push_back(p[i]);

        vector<int> outer;
        for(int i = 0; i < x; i++)
            outer.push_back(p[i]);
        for(int i = y; i < n; i++)
            outer.push_back(p[i]);

        sort(outer.begin(), outer.end());

        vector<int> result;

        int firstB = B[0];

        // elements smaller than first element of B
        int i = 0;
        while(i < outer.size() && outer[i] < firstB){
            result.push_back(outer[i]);
            i++;
        }

        // insert B
        for(int v : B)
            result.push_back(v);

        // remaining outer
        while(i < outer.size()){
            result.push_back(outer[i]);
            i++;
        }

        for(int v : result)
            cout << v << " ";
        cout << "\n";
    }
}
