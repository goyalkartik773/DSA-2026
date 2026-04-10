#include <bits/stdc++.h>
using namespace std;

// query puchhne aur flush karne ka function
int ask(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush(); // output buffer clear karna zaroori hai

    int res;
    cin >> res;

    // agar limit cross ho gayi ya galat query ho gayi toh exit kar do
    if(res == -1) {
        exit(0);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    // shuru ke n-1 pairs banayenge aur query karenge
    for(int i = 1; i <= 2 * n - 2; i += 2) {
        int res = ask(i, i + 1);

        // agar match mil gaya, toh pakka dono 0 hain
        // (kyunki non-zero unique hote hain)
        if(res == 1) {
            cout << "! " << i << "\n";
            cout.flush();
            return;
        }
    }

    // agar yahan tak code aaya, toh last ke do elements bache hain
    int x = 2 * n - 1;
    int y = 2 * n;

    // bache hue element 'x' ko pehle pair (1 aur 2) ke sath check karenge
    if(ask(x, 1) == 1) {
        cout << "! " << x << "\n";
        cout.flush();
        return;
    }

    if(ask(x, 2) == 1) {
        cout << "! " << x << "\n";
        cout.flush();
        return;
    }

    // agar x na toh 1 se match hua aur na hi 2 se,
    // toh mathematically 'y' ko 0 hona hi padega
    cout << "! " << y << "\n";
    cout.flush();
}

int main() {
    // Interactive problems mein fast I/O kai baar buffer issues karta hai,
    // isliye usko hatana safe rehta hai.
    int t;
    if(cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
