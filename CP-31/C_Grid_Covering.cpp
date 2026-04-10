#include <algorithm>
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, m, a, b;
    cin>>n>>m>>a>>b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && (gcd(n, m) == 1 || gcd(n, m) == 2))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
}
