#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue 
#define v vector<int> 
#define g greater<int> 
int main() {
	// your code goes here
	// simple approach agar tomu ko jitna hai to woo max values ko odd index pai rakhega takki uski bari mai wo collect kar sake
	fastio
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    v arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    p<int> pq1; // maxheap stores the max values that motu have
	    p<int,v,g> pq2; // min values that tomu has 
	    for(int i=0;i<n;i++){
	        if(i%2==0){
	            pq1.push(arr[i]);
	        }
	        else {
	            pq2.push(arr[i]);
	        }
	    }
	    while(k!=0){
	        if(pq1.top() > pq2.top()){
	            // har swap mai motu ka max value tomu ko dedunga
	            int x = pq1.top();
	            pq1.pop();
	            int y = pq2.top();
	            pq2.pop();
	            pq1.push(y);
	            pq2.push(x);
	            k--;
	        }
	        else {
	            break; // tomu already have greater element wo bina swap ke jitega
	        }
	    }
	    int scoreT = 0;
	    int scoreM = 0;
	    while(pq1.size()){
	        scoreM += pq1.top();
	        pq1.pop();
	    }
	    while(pq2.size()){
	        scoreT += pq2.top();
	        pq2.pop();
	    }
	    if(scoreT > scoreM) cout<<"YES\n";
	    else
	    cout<<"NO\n";
	}
}
