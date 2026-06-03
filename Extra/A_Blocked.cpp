#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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
        unordered_map<int,int> mp;
        bool flag = false;
        for(auto &ele:arr){
            mp[ele]++;
            if(mp[ele] > 1){
                cout<<-1<<endl;
                flag = true;
                break;
            }
        }
        if(flag) continue;
        else{
            sort(arr.begin(),arr.end());
            for(int i=n-1;i>=0;i--)
            cout<<arr[i]<<" ";
            cout<<endl;
        }

    }
}