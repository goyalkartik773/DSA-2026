#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();
        if (n == k) return "0";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        // Remove extra digits from the end if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        // Remove leading zeros
        int idx = 0;
        while (idx < result.size() && result[idx] == '0') idx++;
        result = result.substr(idx);
        if (result.empty()) return "0";
        return result;
    }
};