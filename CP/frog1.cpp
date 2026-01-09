#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int solve(vector<int> &arr, int idx,int n) {
  if (idx >= n) {
    return INT_MAX;
  }
  if(dp[idx]!=-1){
    return dp[idx];
  }
  int left = 0, right = 0;
  if (idx + 1 < n) {
    left = abs(arr[idx + 1] - arr[idx]) + solve(arr, idx + 1,n);
  }
  if (idx + 2 < n) {
    right = abs(arr[idx + 2] - arr[idx]) + solve(arr, idx + 2,n);
  }
  return dp[idx] =  min(left, right);
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  dp.assign(n+1,-1);
  cout << solve(arr, 0,n);
}