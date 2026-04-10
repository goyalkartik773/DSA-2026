// #ORG C050 #DB 55H,65H
#include <bits/stdc++.h>
using namespace std;

// Function to calculate sum of digits of a number
int sum_of_digits(int n) {
    int s = 0;
    while(n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    string s;
    cin >> s;

    // Agar length 1 hai toh single digit hi answer hoga
    if (s.length() == 1) {
        cout << s << "\n";
        return;
    }

    vector<int> freq(10, 0);
    int total_sum = 0;
    for (char c : s) {
        freq[c - '0']++;
        total_sum += (c - '0');
    }

    // x1 ke liye guess karo, joki at max total_sum tak jaa sakta hai
    for (int cand = 1; cand <= total_sum; cand++) {
        vector<int> tail_freq(10, 0);
        vector<int> tail_nums;
        int curr = cand;

        // Sequence of sums generate karo
        while (true) {
            tail_nums.push_back(curr);
            int temp = curr;
            while (temp > 0) {
                tail_freq[temp % 10]++;
                temp /= 10;
            }
            if (curr <= 9) break;
            curr = sum_of_digits(curr);
        }

        // Check karo ki candidate sequence given digits se ban sakta hai kya
        bool possible = true;
        for (int i = 0; i < 10; i++) {
            if (tail_freq[i] > freq[i]) {
                possible = false;
                break;
            }
        }

        if (!possible) continue;

        // Bachi hui digits ka sum calculate karo
        int rem_sum = 0;
        vector<int> rem_freq(10, 0);
        for (int i = 0; i < 10; i++) {
            rem_freq[i] = freq[i] - tail_freq[i];
            rem_sum += rem_freq[i] * i;
        }

        // Agar bachi hui digits ka sum candidate ke equal hai toh answer mil gaya
        if (rem_sum == cand) {
            string ans = "";

            // First digit non-zero rakho leading zero avoid karne ke liye
            for (int i = 1; i <= 9; i++) {
                if (rem_freq[i] > 0) {
                    ans += (char)('0' + i);
                    rem_freq[i]--;
                    break;
                }
            }

            // Ab bachi hui digits (including zeros) append kardo
            for (int i = 0; i <= 9; i++) {
                while (rem_freq[i] > 0) {
                    ans += (char)('0' + i);
                    rem_freq[i]--;
                }
            }

            // Last me generated tail append kardo
            for (int num : tail_nums) {
                ans += to_string(num);
            }

            cout << ans << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
