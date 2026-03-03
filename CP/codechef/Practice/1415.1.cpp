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
	int t;
	cin>>t;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    vector<int> arr(3,-1);
	    arr[0] = x;
	    arr[1] = y;
	    arr[2] = z;
	    sort(arr.begin(),arr.end(),greater<int>());
	    x = arr[0];
	    y = arr[1];
	    z = arr[2];
	    //cout<<x<<y<<z<<endl;
	    int total = 0;
	    if(x>1 && y>1)
	    {
	        total += 1;
	        x-=1;
	        y-=1;
	    }
	    if(x>1 && z>1){
	        total += 1;
	        x-=1;
	        z-=1;
	    }
	    if(y>1 && z>1){
	        total += 1;
	        y-=1;
	        z-=1;
	    }
	    total += min(1,x);
	    total += min(1,y);
	    total += min(1,z);
	    cout<<total<<endl;
	}

}
