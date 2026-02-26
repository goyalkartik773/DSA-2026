#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long


int main() {
	// your code goes here
	// hijack bank for d days
	// rate is p dollars per day of printing currency
	// after every interval they increase the production by Q dollars
	ll t;
	cin>>t;
	while(t--){
	    ll td,d,p,q;
	    cin>>td>>d>>p>>q;
	    
	    // first i try to simulate the problem
	    
	   // ll ans = 0;
	   // ll intervalDays = d;
	   // // first print intiall dolars
	   // while(intervalDays--){
	   //     ans += p;
	   // }
	   // td -= d;
	   // ll multiple = 2;
	   // ll x = 0;
	   // ll alt = q;
	   // while(td!=0){
	   //     if(x%d==0 && x!=0){
	   //         // after d days productions increases by Q
	   //         q = alt * multiple;
	   //         multiple += 1;
	   //     }
	   //     ans += p + q;
	   //     x += 1;
	   //     td -= 1;
	   // }
	   // cout<<ans<<endl;
	   
	    // second i saw ap so i make simple ap formula
	    
	    
	    ll intervals = td / d;
	    ll remaindays = td % d;
	    ll ans1 = (intervals * (2*p*d + (intervals-1)*q*d)) / 2;
	    ll ans2 = p*remaindays + intervals*remaindays*q;
	    cout<<ans1+ans2<<endl;
	}

}
