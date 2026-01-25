#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr,int k,int target){
        // greedily check kar liya 
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(sum+arr[i] > target){
                // do split if have splits
                sum = 0;
                if(k!=0) 
                k--;
                else
                return false;
            }
            sum += arr[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
    //  split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
    //  very common binary search on answer problem
    // will define the solution space first
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(nums,k-1,mid)){
            // agar k splits per max ans <= mid hai to mid ek possible solution to hai hi
            ans = mid;
            // minimize karna hai to high ko mid sai piche lane ka try karo
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
    }
};