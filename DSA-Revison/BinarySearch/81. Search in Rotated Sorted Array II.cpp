#include <vector>
using namespace std;

class Solution {
public:
    bool bs(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        // step-1 finding pivot index
        int left = 0;
        int right = nums.size() - 1;
        // skip duplicate elements
        while(left < right && nums[left] == nums[left+1]){
            left++;
        }
        while(left < right && nums[right] == nums[right-1]){
            right--;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // step -2 dividing array in two different sorted array
        // step -3 applying bs in both diff. sorted part individually
        if (bs(nums, 0, right - 1, target) ||
            bs(nums, right, nums.size() - 1, target))
            return true;

        return false;
    }
};