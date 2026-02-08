#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
vector<int> ans;
void dfs(int u, vector<bool> &visited, vector<vector<int>> &adj) {
  visited[u] = true;
  ans.push_back(u);
  for (auto &neighbours : adj[u]) {
    if (visited[neighbours])
      continue;
    dfs(neighbours, visited, adj);
  }
}
vector<int> dfs(vector<vector<int>> &adj) {
  // Code here
  vector<bool> visited(adj.size(), false);
  dfs(0, visited, adj);
  return ans;
}

vector<int> bfs(vector<vector<int>> &adj) {
  // code here
  vector<int> ans;
  int n = adj.size();
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while (q.size() != 0) {
    int node = q.front();
    ans.push_back(node);
    q.pop();
    for (auto &neighbours : adj[node]) {
      if (!visited[neighbours]) {
        q.push(neighbours);
        visited[neighbours] = true;
      }
    }
  }
  return ans;
}
