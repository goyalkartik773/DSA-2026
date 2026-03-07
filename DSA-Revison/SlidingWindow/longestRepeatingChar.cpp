#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string str, int k) {
        int cCh,eCh,i,j,ans;
        int result = INT_MIN;
        int n = str.length();
        // can optimise more with first checking the string characters and then try only on them
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            // try to make complete string of ch
            cCh = 0;
            eCh = 0;
            i = 0;
            j = 0;
            ans = 0;
            while (j < n) {
                if (str[j] == ch)
                cCh++;
                else
                eCh++;
                while (eCh > k && i < n) {
                    // shrinking the window
                    if (str[i] == ch)
                    cCh--;
                    else
                    eCh--;
                    i++;
                }
                j++;
                ans = max(ans,eCh + cCh);
            }
            result = max(result,ans);
        }
        return result;
    }
};
int main(){
    
}