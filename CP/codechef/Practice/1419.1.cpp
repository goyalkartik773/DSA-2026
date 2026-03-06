#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<math.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue 
#define v vector<int> 
#define g greater<int> 
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    vector<ll> arr(n,0);
	    for(int i=0;i<n;i++) cin>>arr[i];
	    // approach x1,x2,x3 .. contributinn n-1 times 
	    ll aSum = accumulate(arr.begin(),arr.end(),0LL);
	    //cout<<aSum;
	    ll xSum = aSum / (n-1);
	    //cout<<xSum;
	    for(int i=0;i<n;i++){
	        cout<<xSum-arr[i]<<" ";
	    }
	    cout<<endl;
	}

}
