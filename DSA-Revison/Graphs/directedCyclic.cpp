#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int, vector<int>> graph;
bool check(int u, vector<bool> &visited, vector<bool> &inRecursion) {
  if (visited[u] == true && inRecursion[u])
    return true;
  visited[u] = true;
  inRecursion[u] = true;
  for (auto &ele : graph[u]) {
    if (check(ele, visited, inRecursion))
      return true;
  }
  inRecursion[u] = false;
  return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
  // code here
  unordered_map<int, vector<int>> mp(V);
  for (auto &ele : edges) {
    int u = ele[0];
    int v = ele[1];
    mp[u].push_back(v);
  }
  graph = mp;
  // start with any node agar kisi node per jane ke do tarike hai to uss graph
  // mai cycle hoga hii
  vector<bool> visited(V, false);
  vector<bool> inRecursion(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      if (check(i, visited, inRecursion))
        return true;
    }
  }
  return false;
}