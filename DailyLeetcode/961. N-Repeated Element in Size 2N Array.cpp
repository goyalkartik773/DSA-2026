#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // array have only one element that has frequency more than 2
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele] += 1;
            if (mp[ele] >= 2) {
                return ele;
            }
        }
        return -1;
    }
};