#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // har element ek range define karta hai means i count
        // use line sweep to find the max intersection interval 
        // can replace the array with that max intersection point
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int l = nums[i] - k;
            int r = nums[i] + k;
            mp[l]+=1;
            mp[r+1]-=1; // will include end point;
        }
        int ans = 0;
        int sum = 0;
        for(auto &ele:mp){
            sum += ele.second;
            ans = max(ans,sum);
        }
        return ans;
    }
};
int main(){
    
}