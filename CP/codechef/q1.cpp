#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int solve(vector<int>& arr,int k){
    // agar sare element arr ke unique hai to each operation deletes one unique element
    int ref = arr[0];
    unordered_map<int,int> freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }
    vector<pair<int,int>> brr(freq.begin(),freq.end());
    sort(brr.begin(),brr.end(),[](const pair<int,int> &a,const pair<int,int> &b){
       return a.second < b.second;
    });
    
    int ans = freq.size();
    for(int i=0;i<brr.size();i++){
        int count = brr[i].second;
        if(count <= k && ref!=brr[i].first){
            ans -= 1;
            k -= count;
        }
        //else break;
    }
    return max(1,ans);
}
int main() {
	// your code goes here
	// atmost k times can be the operations performed
	// [i,j] arr[j] = arr[i]
	// 1 3 2 2
	// 1 2 2 --> 1 1 1 k = 2
	// 1 2 2 2 4 --> 1 1 2 2 4
	// 1 2 3 1 --> 
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> arr(n,-1);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<solve(arr,k)<<endl;
	}

}
