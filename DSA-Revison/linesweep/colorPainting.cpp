#define ll long long
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<ll,ll> mp;
        for(auto &ele:segments){
            ll l = ele[0];
            ll r = ele[1];
            ll c = ele[2];
            mp[l]+=c;
            mp[r]-=c;
        }
        vector<pair<ll,ll>> arr(mp.begin(),mp.end());
        vector<vector<ll>> ans;
        ll sum = 0;
        for(int i=0;i<arr.size()-1;i++){
            sum += arr[i].second;
            if(sum==0) continue;
            ans.push_back({arr[i].first,arr[i+1].first,sum});
        }
        return ans;
    }
};
int main(){
    
}