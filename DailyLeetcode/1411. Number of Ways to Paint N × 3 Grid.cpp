#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<string> columnStates;
    vector<vector<int>> dp;
    int MOD = 1e9+7;
    void generateColumnState(string curr,char prev,int m){
        if(curr.length()==m){
            columnStates.push_back(curr);
            return;
        }
        for(char ch:{'R','G','B'}){
            if(prev==ch)
            continue;
            curr += ch; // do 
            generateColumnState(curr,ch,m); // explore   agar call mai variable change karta to no backtrack req har call mai new obj create hota
            curr.pop_back(); // undo
        }
    }
    bool check(string a,string b){
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i])
            return true;
        }
        return false;
    }
    int solve(int currIdx,string curr,int idx,int n){
        if(idx==n){
            // result += 1;
            return 1;
        }
        if(dp[currIdx][idx]!=-1){
            return dp[currIdx][idx];
        }
        long long ways = 0;
        for(int i=0;i<columnStates.size();i++){
            if(check(curr,columnStates[i]))
            continue;
            ways = (ways + solve(i,columnStates[i], idx + 1, n)) % MOD;
        }
        return dp[currIdx][idx] = ways;
    }
    int numOfWays(int n) {
        dp.assign(columnStates.size(), vector<int>(n+1, -1));
        string curr = "";
        char prev = '#';
        int m = 3;
        generateColumnState(curr,prev,m);
        dp.assign(columnStates.size(), vector<int>(n+1, -1));
        int result  = 0;
        for(int i=0;i<columnStates.size();i++){
            result = (result + solve(i,columnStates[i], 1, n)) % MOD;
        }
        return result;
    }
};