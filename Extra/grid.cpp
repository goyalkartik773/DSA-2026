#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int result = INT_MAX;
vector<vector<int>> dist = {{0,1},{1,0},{0,-1},{-1,0}};
void minSum(int row,int col,vector<vector<int>>& grid,int sum,vector<vector<bool>>& visited){
    if(row==grid.size()-1 && col == grid[0].size()-1){
        sum += grid[row][col];
        result = min(sum,result);
        return ;
    }
    auto isSafe = [&](int a,int b)->bool{
        if(a>=0 && a<grid.size() && b>=0 && b<grid[0].size())
        return true;
        else
        return false;
    };
    visited[row][col] = true;
    sum += grid[row][col];
    for(auto &d:dist){
        int nr = row + d[0];
        int nc = col + d[1];
        if(isSafe(nr,nc) && !visited[nr][nc]){
        minSum(nr,nc,grid,sum,visited);   
        }
    }
    visited[row][col] = false;
}
int main(){
    vector<vector<int>> grid = {{1,5,8},{6,2,7},{9,3,4}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    minSum(0,0,grid,0,visited);
    cout<<result;

}