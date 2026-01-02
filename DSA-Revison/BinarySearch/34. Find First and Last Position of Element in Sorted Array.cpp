#include <vector>
using namespace std;

class Solution {
public:
    int firstPosition(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int result  = -1;
        while(low <= high){
            int mid  = low + (high-low)/2;
            if(nums[mid]==target){
                result = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return result;
    }
    int lastPosition(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                result = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fp = firstPosition(nums,target);
        int lp = lastPosition(nums,target);
        return {fp,lp};
    }
};