#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
      mp[nums[i]] += 1;
    }
    long long sum = 0;
    long long ans = 0;
    sum = accumulate(mp.begin(), mp.end(), 0LL, [](long long s, const auto &p) {
      return s + 1LL * p.first * p.second;
    });
    if (mp.size() == k) {
      ans = max(ans, sum);
    }
    for (int i = k; i < n; i++) {
      int insrt = nums[i];
      int remve = nums[i - k];
      mp[remve]--;
      if (mp[remve] == 0) {
        mp.erase(remve);
      }
      mp[insrt]++;
      sum -= remve;
      sum += insrt;
      cout << sum << " ";
      if (mp.size() == k) {
        ans = max(ans, sum);
      }
    }
    return ans;
  }
};
int main() {}