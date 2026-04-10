#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<bool> flag(n,false);
        int ball = 0;
        int i = 0;
        flag[0] = true;
        while(i<n){
            if(str[ball]=='R') ball++;
            else
                ball--;
            flag[ball] = true;
            i++;
        }
        int res = 0;
        for(auto ele:flag){
            if(ele) res +=1;
        }
        cout<<res<<endl;
    }
}
