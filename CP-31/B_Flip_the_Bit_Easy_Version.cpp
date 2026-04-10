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

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> arr[i];

    int p;
    cin >> p;
    int x = arr[p];

    int lft = 0;
    int prev = 0;
    for (int i = 1; i < p; i++) {
      int c = (arr[i] != x);
      if (c != prev) {
        lft++;
        prev = c;
      }
    }

    int rgt = 0;
    prev = 0;
    for (int i = n; i > p; i--) {
      int c = (arr[i] != x);
      if (c != prev) {
        rgt++;
        prev = c;
      }
    }

    int ans = max(lft, rgt);
    ans += (ans & 1);

    cout<<ans<<endl;
  }

  return 0;
}