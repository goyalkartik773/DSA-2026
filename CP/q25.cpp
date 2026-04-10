#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input/output fast karne ke liye
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        long long n, c, k;
        cin >> n >> c >> k;

        vector<long long> a(n);
        // input le rahe hain sabhi monsters ki power
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++)
        {
            if(c < a[i])
            {
                break;
            }

            long long x = min(k, c - a[i]);
            c += a[i] + x;
            k -= x;
        }

        cout<<c<<endl;
    }

    return 0;
}
