#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkRedundancy(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                bool isRedundant = true;
                while (!st.empty() && st.top() != '(') {
                    char ch = st.top();
                    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
                if (isRedundant) return true;
            } else {
                st.push(s[i]);
            }
        }
        return false;
    }
};
