#include<iostream>
#include<vector>
using namespace std;
int lazySorting(vector<int>& arr){
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > ans.back()){
            // direct push kardo isse to ans mai
            ans.push_back(arr[i]);
        }
        else{
            // find the just chota element than arr[i] or usse replace kardega // lowerbound <= x
            int idx = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }
    return ans.size();
}
int main(){
    vector<int> arr = {5,8,3,7,9,1};
    cout<<lazySorting(arr);
}