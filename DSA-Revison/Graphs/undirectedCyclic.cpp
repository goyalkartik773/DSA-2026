#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
    unordered_map<int,vector<int>> graph;
    bool check(int v,int parent,vector<bool>& visited){
        if(visited[v]==true){
            return true;
        }
        visited[v] = true;
        for(auto &ele:graph[v]){
            if(ele == parent) continue;
            if(check(ele,v,visited)) return true;
        }
    return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp(V);
        for(auto &ele:edges){
            int u = ele[0];
            int v = ele[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        graph = mp;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
            if(check(i,-1,visited))
            return true;
            }
        }
        return false;
    }
int main(){
    // detect cycle in a undirected graph
    // agar koi bhi node ko ek dfs cycle mai do baar visit kiya to matlab graph mai cycle hai
    // components ho sakte hai graph mai to koi node agar graph mai dfs visited samay visit nahi hua to uss node sai ek or dfs mar do
    
}