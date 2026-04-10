#include <bits/stdc++.h>
using namespace std;

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int operations = 0;
        int current_max = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;


            if (x >= current_max)
            {
                operations++;     // Operation count badha do
                current_max = x;  // Naya maximum update kar do
            }
        }
        cout << operations << "\n";
    }

    return 0;
}
