#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
    void dfs(int node,unordered_map<int,vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;
        for(auto &child:graph[node]){
            if(visited[child]) continue;
            dfs(child,graph,visited);
        }
    }
    void bfs(int node,unordered_map<int,vector<int>>& graph,vector<bool>& visited){
         queue<int> q;
         q.push(node);
         visited[node] = true;
         while(q.size()!=0){
            int curr = q.front();
            q.pop();
            for(auto &child:graph[curr]){
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
         }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // just need to find the no of connected components
        unordered_map<int,vector<int>> graph;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    graph[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count += 1; // ek or province mil gaya
                bfs(i,graph,visited);
            }
        }
        return count;
    }
