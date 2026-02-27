#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1) cout<<1<<endl;
        else{
        int ele = *max_element(arr.begin(),arr.end());
        int ans = 0;
        for(auto &el:arr){
            if(el == ele) ans+=1;
        }
        cout<<ans<<endl;
        }
    }
}
