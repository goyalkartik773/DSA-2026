#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> dp;
void dfs(int u, int parent, unordered_map<int, vector<int>> &graph) {
  int sub = 0;
  for (auto &childs : graph[u]) {
    if (childs == parent)
      continue;
    dfs(childs, u, graph);
    sub += 1 + dp[childs - 1];
  }
  dp[u - 1] = sub;
}
int main() {
  int n;
  cin >> n;
  // 1 is general of the company
  vector<int> arr(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < arr.size(); i++) {
    int u = i + 2;
    int v = arr[i];
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dp.assign(n, 0);
  dfs(1, -1, graph);
  for (auto &ele : dp) {
    cout << ele << " ";
  }
}