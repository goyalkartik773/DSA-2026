#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
    void dfs(int node,unordered_map<int,vector<int>> &graph,vector<bool>& visited,stack<int>& st){
        visited[node] = true;
        for(auto &child:graph[node]){
            if(visited[child]) continue;
            dfs(child,graph,visited,st);
        }
        // jab backtrack karega node sai to iss node ko stack mai push kardega
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        unordered_map<int,vector<int>> graph;
        for(auto &ele:edges){
            int u = ele[0];
            int v = ele[1];
            graph[u].push_back(v);
        }
        stack<int> st;
        vector<int> ans;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
            dfs(i,graph,visited,st);
        }
        while(st.size()!=0){
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        return ans;
    }
int main(){

}