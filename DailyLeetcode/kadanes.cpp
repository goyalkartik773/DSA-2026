#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long maxSum = arr[0];
    long long currSum = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > currSum + arr[i]){
            currSum = arr[i];
        }
        else
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
    }
    cout<<maxSum;
}