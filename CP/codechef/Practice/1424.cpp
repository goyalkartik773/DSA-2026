#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue 
#define v vector<int> 
#define g greater<int>

int main(){
    int t;
    cin >> t;

    while(t--){
        ll l, r;
        cin >> l >> r;
        if(l <= r/2) cout<<-1<<endl;
        else
        cout<<r<<endl;
    }
} 