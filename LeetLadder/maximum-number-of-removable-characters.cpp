#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkSubsequence(string& s,string& p,int mid,vector<int>& removable){
        // mid tak sare char jo removable mai thaa unn sabko remove kar diya s sai
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = p.size();
        vector<int> flag(n,false);
        for(int i=0;i<mid;i++){
            flag[removable[i]] = true;
        }
        while(i<n && j<m){
            if(flag[i]) i++;
            else if(s[i]==p[j]) i++,j++;
            else i++;
        }
        if(j==m) return true;
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
       //  two strings s and p where p is a subsequence of s
       //  adistinct 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed)
       // k=1 removable[0] per jo index hai usse s string sai remove kar dunga

       // brute force --> ek ek karke character remove karu and check ki valid hai yaha nahi
       int ans = 0;
    //    int n = s.length();
    //    vector<bool> flag(n,false);
    //    for(auto ele:removable){
    //      //  s.erase(ele,1); will change the order of indices in the string
    //        flag[ele] = true;
    //        if(checkSubstring(s,p,flag)) ans++;
    //        else 
    //        break;
    //    }

       // use bs agar k character ko remove karke valid hai to k-2,k-1 bhi valid hai monotonicity hai 
       // now t.c O(n^2) reduced to O(nlogn)
       int low = 0;
       int high = removable.size();
       while(low <= high){
        int mid = low + (high-low)/2;
        if(checkSubsequence(s,p,mid,removable)){
            ans = mid;
            low = mid + 1;
        }
        else
        high = mid-1;
       } 
       return ans;
    }
};