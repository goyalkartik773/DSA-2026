#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#define ll long long
#define pq priority_queue
#define vi vector<long long>
#define gi greater<long long>
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    vi arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    pq<ll,vi,gi> pq1; // minHeap
	    pq<ll> pq2; // maxHeap
	    for(int i=0;i<n;i++){
	        if(i%2==0){
	            pq1.push(abs(arr[i]));
	        }else{
	             pq2.push(abs(arr[i]));
	        }
	    } 
	    if(pq1.top() < pq2.top()){
	        ll x = pq1.top();
	        pq1.pop();
	        ll y = pq2.top();
	        pq2.pop();
	        pq1.push(y);
	        pq2.push(x);
	    }
	    ll sum1 = 0;
	    while(pq1.size()){
	        sum1 += pq1.top();
	        pq1.pop();
	    }
	    ll sum2 = 0;
	    while(pq2.size()){
	        sum2 += pq2.top();
	        pq2.pop();
	    }
	    cout<<sum1-sum2<<endl;
	}
}
