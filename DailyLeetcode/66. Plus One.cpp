#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& digits, int idx) {
        if (idx >= digits.size())
            return;

        if (digits[digits.size() - idx - 1] == 9) {
            digits[digits.size() - idx - 1] = 0;
            idx += 1;
            solve(digits, idx);
        } else {
            digits[digits.size() - idx - 1] += 1;
            return;
        }
    }
    vector<int> plusOne(vector<int>& digits) {
        solve(digits, 0);
        if (digits[0] == 0) {
            int n = digits.size();
            vector<int> result(n + 1);
            result[0] = 1;
            for (int i = 0; i < n; i++) {
                result[i + 1] = digits[i];
            }
            return result;
        } else {
            return digits;
        }
    }
};