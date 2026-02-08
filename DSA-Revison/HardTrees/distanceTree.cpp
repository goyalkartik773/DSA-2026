#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> st;
void bfs(int node, unordered_map<int, vector<int>> &graph, int k, int n) {
  vector<bool> visited(n + 1, false);
  queue<int> q;
  q.push(node);
  visited[node] = true;
  int lvl = 0;
  while (q.size() != 0) {
    if (lvl == k) {
      while (q.size() != 0) {
        int x = q.front();
        q.pop();
        st.insert({max(node, x), min(node, x)});
      }
      break;
    }
    queue<int> temp = q;
    q = queue<int>();
    // pura ek level ko visit kar liya
    while (temp.size() != 0) {
      int curr = temp.front();
      temp.pop();
      for (auto &child : graph[curr]) {
        if (!visited[child]) {
          q.push(child);
          visited[child] = true;
        }
      }
    }
    lvl += 1;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, vector<int>> tree;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    bfs(i, tree, k, n);
  }
  cout << st.size() <<endl;
}
