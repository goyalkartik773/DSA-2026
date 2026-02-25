#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
using namespace std;

int main() {
    // main idea to solve this problem is 
    // minimum element ko jada bar layega window main
    // 1 and n  ---> 1 time
    // 2 and n-1 --> 2 time
    // rest     ---> 3 time
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << 1 << " " << 2 << " " << 3;
            //continue;
        }
        else {
            vector < int > arr(n, 0);
            // sabse bade element ek hi baar ayega abb
            arr[0] = n ;
            arr[n - 1] = n-1;
            // second smallest 2 hi baar ayega abb
            arr[1] = n - 3;
            arr[n - 2] = n - 2;
            // remaiining element three times ayega 
            int x = 1;
            for (int i = 2; i <= n - 3; i++) {
                arr[i] = x;
                x += 1;
            }
            // upper 3 pairs mai value dali hai we can change the combination not position matlab 1 and last mai n ,n-1 koi bhi dal sakte hai similarly 2nd frequency position koi bhi second smallest daal sakte hai
            for (auto & ele: arr)
                cout << ele << " ";
        }
        cout << endl;
    }

}