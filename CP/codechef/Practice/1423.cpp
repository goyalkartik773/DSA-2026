#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue 
#define vi vector<int> 
#define g greater<int>

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n,x;
        cin >> n >> x;

        vector<ll> ans;

        for(ll i=1;i<=n/2;i++){
            ans.push_back(x-i);
            ans.push_back(x+i);
        }

        if(n%2!=0) 
        ans.push_back(x);

        for(auto v:ans) cout<<v<<" ";
        cout<<endl;
    }
}