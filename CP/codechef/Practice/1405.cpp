#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
    // your code goes here
    //  find out if it has enough rooms to accommodate all potential guests.
    // kuch guests ka reservation bhi hai
    // each reservation has arrival time and departure time
    // maximum number of guests that will be at the hotel simultaneously
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector < int > dep(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> dep[i];
        }
        
        vector<int> crr(1001,0);
        for(int i=0;i<n;i++){
            for(int k=arr[i];k<dep[i];k++){
                crr[k]+=1;
            }
        }
        cout<< *max_element(crr.begin(),crr.end()) <<endl;

    }


}