#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int f(int idx,int diff,vector<int>& arr){
        if(idx < 0) return 0;
        int ans  = 0;
        if(dp[idx][diff+500]!=-1) return dp[idx][diff+500];
        for(int k=idx-1;k>=0;k--){
            int newD = arr[idx] - arr[k];
            if(newD == diff){
                ans = max(ans,1+f(k,diff,arr));
            }
        }
        return dp[idx][diff+500] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int ans = 0;
        dp.assign(1001,vector<int>(1001,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j]-nums[i];
                ans = max(ans,2 + f(i,diff,nums));
            }
        }
        return ans;
    }
};
int main(){
    
}