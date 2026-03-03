#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define p priority_queue 
#define v vector<int> 
#define g greater<int> 


// if you want to find the max absolute difference between the array such that j > i then we can consider the first element as min element agar chota or element milega to usse mn element consider karega

int main() {
    fastio
    // n practice match already played
    // show stats of 2 of his practice match
    // no of goals scored in 2nd game is greater than 1st game
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        int diff = 0;
        int mn = arr[0];
        for(int i=1;i<n;i++){
            if(mn < arr[i]){
                diff = max(diff,arr[i]-mn);
            }
            else{
                // or chota minimum element milgaya
                mn = arr[i];
            }
        }
        if(diff==0) cout<<"UNFIT\n";
        else
        cout<<diff<<endl;
    }
}