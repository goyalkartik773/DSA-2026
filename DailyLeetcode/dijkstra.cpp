#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dijkstra(vector<vector<pair<int,int>>>& graph){
    int n = graph.size(); // no of nodes in the graph
    vector<int> dist(n,INT_MAX);
    // src --> consider node 0
    dist[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap
    pq.push({0,0});
    while(pq.size()!=0){
        int node =  pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto &neighbour:graph[node]){
            int wt = neighbour.second;
            int newNode = neighbour.first;
            if(dist[newNode] > dist[node] + wt){
                dist[newNode] = dist[node] + wt;
                pq.push({wt,newNode});
            }
        }
    }
    return dist[n-1]; // consider last node as destination node
}
int main(){

}