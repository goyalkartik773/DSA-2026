#include<iostream>
#include<string>
#include<numeric>
using namespace std;
// key concepts to learn
// agar cyclic shift wagera ho to string ko concatenate karlena chaiya
// then to simulate the strings we can use sliding window instead of doing it physically
class Solution {
public:
    int minFlips(string s) {
        // will now use sliding window
        int n1 = s.length();
        string str = s + s;
        int n = str.length();
        int i = 0;
        int j = 0;
        int pat1 = 0; // 01010101
        int pat2 = 0; // 101010101
        int ans = INT_MAX;
        while (j < n) {
            if (j % 2 == 0 && str[j]!='0') {
            pat1++;
            } 
            else if(j % 2 != 0 && str[j]!='1') {
            pat1++;
            }
            else
            pat2++;
            if (j - i + 1 > n1) {
            if (i % 2 == 0 && str[i]!='0') {
            pat1--;
            } 
            else if(i % 2 != 0 && str[i]!='1') {
            pat1--;
            }
            else
            pat2--;
            i++;
            }
            if (j - i + 1 == n1)
            ans = min(ans, min(pat1, pat2));
            j++;
        }
        return ans;
    }
};
int main(){

}