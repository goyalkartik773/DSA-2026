#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> aS(n, 0);
    for (int i = 0; i < n; i++)
      cin >> aS[i];
    vector<int> aM(n, 0);
    for (int i = 0; i < n; i++)
      cin >> aM[i];
    vector<int> aB(n, 0);
    for (int i = 0; i < n; i++)
      cin >> aB[i];
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
      arr.push_back({aS[i], i});
    }
    vector<pair<int, int>> brr;
    for (int i = 0; i < n; i++) {
      brr.push_back({aM[i], i});
    }
    vector<pair<int, int>> crr;
    for (int i = 0; i < n; i++) {
      crr.push_back({aB[i], i});
    }
    sort(arr.begin(), arr.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
    sort(brr.begin(), brr.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
    sort(crr.begin(), crr.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

    int result = INT_MIN;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3 ; j++) {
        for (int k = 0; k < 3; k++) {
          int idx1 = arr[i].second;
          int idx2 = brr[j].second;
          int idx3 = crr[k].second;

          if (idx1 != idx2 && idx2 != idx3 && idx1 != idx3) {
            result = max(result, arr[i].first + brr[j].first + crr[k].first);
          }
        }
      }
    }
    cout << result << endl;
  }
}