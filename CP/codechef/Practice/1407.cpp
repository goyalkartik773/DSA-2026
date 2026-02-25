#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	// your code goes here
	// permutation p has length 2n
	// kisi bhi element ko uske adjacent element sai swap kar sakta hu
	// p permutation good only when max of first half is < min ele of second half
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(2*n,0);
	    for(int i=0;i<2*n;i++){
	        cin>>arr[i];
	    }
	    // good permutation if firsthalf max < secondhalf min
	    // matlab second half ke sare ke sare element bade hone chaiye first half sai
	    int one = 0;
	    int ans = 0;
	    for(int i=0;i<2*n;i++){
	        if(arr[i] > n){
	            // iss element ko end tak pahuchna hai
	            one++;
	        }
	        else
	        ans += one;
	    }
	    cout<<ans<<endl;
	}

}
