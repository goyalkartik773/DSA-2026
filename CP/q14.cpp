#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(vector<vector<int>>& arr,vector<vector<string>>& brr,int k){
    int eng1 = 0;
    int eng2 = 0;
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(brr[i]=="1"){
                eng1 += arr[i][j];
            }
            else
                eng2 += arr[i][j];
        }
    }
    if(eng1==eng2) return true;



}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
       int n,m,k;
       cin>>n>>m>>k;
       vector<vector<int>> grid(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
       }
       vector<vector<string>> arr(n,vector<string>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
       }
       if(solve(grid,arr,k)) cout<<"YES\n";
       else
        cout<<"NO\n";
    }
    return 0;
}

