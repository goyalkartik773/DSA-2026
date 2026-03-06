#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <numeric>
using namespace std;
#define ll long long
#define fastio       ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue
#define v vector<int>
#define g greater<int>
int main() {
  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll &x : arr)
      cin >> x;

    if (n == 1) {
      cout << arr[0] << endl;
      continue;
    }

    ll total = accumulate(arr.begin(), arr.end(), 0LL);

    ll pref = 0;
    ll ans = LLONG_MAX;

    for (int i = 0; i < n - 1; i++) {
      pref += arr[i];
      ll suff = total - pref;
      ans = min(ans, max(pref, suff));
    }

    cout << ans << endl;
  }
}