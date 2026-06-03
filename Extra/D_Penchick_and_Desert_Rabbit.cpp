#include<iostream>
#include<vector>
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
        vector<int> prefixMax(n,0);
        prefixMax[0] = arr[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],arr[i]);
        }
        vector<int> suffixMin(n,0);
        suffixMin[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],arr[i]);
        }
        vector<int> result(n,0);
        result[n-1] = prefixMax[n-1];
        for(int i=n-2;i>=0;i--){
            if(prefixMax[i] <= suffixMin[i+1]){
                // backward jump is not possible so answer humesha left side sai hoga wo max hi lega
                result[i] = prefixMax[i];
            }
            else
            result[i] = result[i+1];
        }
        for(auto &ele:result){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
