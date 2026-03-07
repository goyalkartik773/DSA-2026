#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // as question is asking for consequtive ones so hum isme sliding window concept laga sakte hai
        int i = 0;
        int j = 0;
        int cZeros = 0;
        int cOnes = 0;
        int ans = 0;
        int n = nums.size();
        while(j<n){
            while(cZeros > k){
                ans = max(ans,cOnes+cZeros-1);
                if(nums[i]==0) cZeros -= 1;
                else
                cOnes -= 1;
                i++;
            }
            if(nums[j]==0) cZeros += 1;
            else
            cOnes += 1;
            j++;
        }
        while(cZeros > k){
                ans = max(ans,cOnes+cZeros-1);
                if(nums[i]==0) cZeros -= 1;
                else
                cOnes -= 1;
                i++;
        }
        ans = max(ans,cOnes+cZeros);
        return ans;
    }
};
int main(){
    
}