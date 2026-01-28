#include <iostream>
#include <vector>
using namespace std;
bool solve(vector<int>& arr, vector<int>& brr) {
    int n = arr.size();
    long long prefMax = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] > brr[i]) return false;
        if(arr[i] < brr[i]) {
            if(prefMax >= arr[i]) {
                return false;
            }
        }

        prefMax = max(prefMax, (long long)arr[i]);
    }
    return true;
}

int main() {
	// your code goes here
	// two arrays a and b is given
	// choose some integer x and find the smallest index in a jiska value just x sai bada hoo
	// ai = ai + 1;
	int t;
	cin>>t;
	while(t--){
        int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    vector<int> brr(n,0);
	   for(int i = 0; i < n; i++) cin >> arr[i];
for(int i = 0; i < n; i++) cin >> brr[i];

	    if(solve(arr,brr)) cout<<"yes\n";
	    else
	    cout<<"NO\n";
	}
}
