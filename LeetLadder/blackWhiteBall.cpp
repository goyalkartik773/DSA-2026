#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        // observation
        // har one ke right mai kitne zeros hai utne swap min lagega usko right tak pahuchane mai
        vector<int> suffix(n,0);
        if(s[n-1]=='0') suffix[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0') suffix[i] = 1 + suffix[i+1];
            else
            suffix[i] = suffix[i+1];
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans += suffix[i];
        }
        return ans;
    }
};
int main(){
       
}