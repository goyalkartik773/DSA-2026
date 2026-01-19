#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
       // a[i] % x (always less than x)
        sort(arr.begin(),arr.end());
        long long g = 0;
        for(int i=1;i<n;i++){
            g = __gcd(g, arr[i] - arr[0]);

        }
        cout<<g<<endl;
    }
}
