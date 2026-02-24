// is onboarding n drivers
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int solve(vector<int> &arr) {
  unordered_map<int, int> mp;
  for (auto &ele : arr) {
    mp[ele]++;
  }
  vector<pair<int, int>> brr(mp.begin(), mp.end());
  sort(brr.begin(), brr.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  });
  vector<int> crr;
  for (int i = 0; i < brr.size(); i++) {
    int val = brr[i].first;
    int freq = brr[i].second;
    while (freq--) {
      crr.push_back(val);
    }
  }
  int n = arr.size();
  vector<pair<int, int>> prefix(n);
  prefix[0] = {crr[0], crr[0]};
  for (int i = 1; i < crr.size(); i++) {
    int val = crr[i];
    int newMin = min(val, prefix[i - 1].second);
    int newMax = max(val, prefix[i - 1].first);
    prefix[i] = {newMax, newMin};
  }
  int minImbalance = 0;
  for (int i = 1; i < crr.size(); i++) {
    int minCost = prefix[i].first - prefix[i].second;
    minImbalance += minCost;
  }
  return minImbalance;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solve(arr) << endl;
  }
}