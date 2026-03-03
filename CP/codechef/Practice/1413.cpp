#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#define ll long long
#define pq priority_queue
#define vi vector<long long>
#define gi greater<long long>
using namespace std;
int main() {
	// your code goes here
	// binary string 
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string str;
	    cin>>str;
	    // 1 0 
	    // if agar alternate subsequence odd hai to zlatan wins
	    // if even includeing zero then ramos wins
	    int Zeros = 0;
	    int Ones = 0;
	    for(auto &ch:str){
	        if(ch=='0') Zeros +=1;
	        else
	        Ones += 1;
	    }
	    int x = min(Zeros,Ones);
	    if(x%2==0) cout<<"ramos\n";
	    else
	    cout<<"zlatan\n";
	    
	}
}