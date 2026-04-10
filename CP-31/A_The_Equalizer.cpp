#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long cs = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cs += x;
    }
    if (cs % 2 != 0 || (n * k) % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}