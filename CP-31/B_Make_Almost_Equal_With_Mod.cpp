#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<=60;i++){
            long long k = 1LL << i;
            set<long long> distinctVals;
            for(int i=0;i<n;i++){
                distinctVals.insert(arr[i]%k);
            }
            if(distinctVals.size()==2){
                cout<<k<<endl;
                break;
            }
        }
    }
}