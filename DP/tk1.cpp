#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1e9+7;
int main(){
    long long n;
    cin>>n;
    vector<long long> dp(n+1,0);
    for(long long i=1;i<=min(n,6LL);i++){
        long long sum = 0;
        for(long long k=1;k<=i;k++){
            sum += dp[i-k];
        }
        dp[i] = 1 + sum;
    }
    for(long long i=7;i<=n;i++){
        long long sum = 0;
        for(long long k=1;k<=6;k++){
            sum = (sum + dp[i-k])%mod;
        }
        dp[i] = sum%mod;
    }
    cout<<dp[n]<<endl;
}