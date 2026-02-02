#include <iostream>
#include <vector>
using namespace std;
int solve(int n, int k, int prod, int size) {
  if (size == n && prod == k) {
    return 1;
  }
  if (size >= n) {
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    prod *= i;
    ans += solve(n, k, prod, size + 1);
    prod /= i;
  }
  return ans;
}
int main() {
  cout << solve(2, 6, 1, 0);

  return 0;
}