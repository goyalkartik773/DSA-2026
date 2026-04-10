#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    int max_beautiful = 0;

    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            int count_color0 = 0;
            int count_color1 = 0;
            bool is_bipartite = true;

            queue<int> q;
            color[i] = 0;
            q.push(i);

            while(q.size()!=0) {
                int curr = q.front();
                q.pop();

                if(color[curr] == 0) count_color0++;
                else count_color1++;

                for(int neighbor : adj[curr]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    }
                    else if(color[neighbor] == color[curr]) {
                        is_bipartite = false;
                    }
                }
            }

            if(is_bipartite) {
                max_beautiful += max(count_color0, count_color1);
            }
        }
    }
    cout << max_beautiful << "\n";
    }
    return 0;
}
