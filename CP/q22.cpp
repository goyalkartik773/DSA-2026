#include <bits/stdc++.h>
using namespace std;
long long get_lcm(long long x, long long y, long long m) {

    if (x == 0 || y == 0)
    return m + 1;
    long long g = __gcd(x, y);
    if (x / g > m / y)
    return m + 1;
    return (x / g) * y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
         long long a, b, c, m;
    cin >> a >> b >> c >> m;

    long long lcm_ab = get_lcm(a, b, m);
    long long lcm_bc = get_lcm(b, c, m);
    long long lcm_ac = get_lcm(a, c, m);
    long long lcm_abc = get_lcm(lcm_ab, c, m);

    long long total_a = m / a;
    long long total_b = m / b;
    long long total_c = m / c;

    long long total_ab = m / lcm_ab;
    long long total_bc = m / lcm_bc;
    long long total_ac = m / lcm_ac;

    long long total_abc = m / lcm_abc;

    long long only_a = total_a - total_ab - total_ac + total_abc;
    long long only_b = total_b - total_ab - total_bc + total_abc;
    long long only_c = total_c - total_ac - total_bc + total_abc;

    long long only_ab = total_ab - total_abc;
    long long only_bc = total_bc - total_abc;
    long long only_ac = total_ac - total_abc;

    long long water_a = (only_a * 6) + (only_ab * 3) + (only_ac * 3) + (total_abc * 2);
    long long water_b = (only_b * 6) + (only_ab * 3) + (only_bc * 3) + (total_abc * 2);
    long long water_c = (only_c * 6) + (only_ac * 3) + (only_bc * 3) + (total_abc * 2);

    cout << water_a << " " << water_b << " " << water_c << "\n";
    }
    return 0;
}
