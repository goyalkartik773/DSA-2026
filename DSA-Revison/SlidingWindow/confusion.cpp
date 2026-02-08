#include<iostream>
#include<vector>
using namespace std;
    int maxConsecutiveAnswers(string str, int k) {
        int countT = 0;
        int countF = 0;
        int i = 0;
        int j = 0;
        int n = str.length();
        int ans = INT_MIN;
        while(j < n){
            if(str[j]=='T') countT++;
            else countF++;
            // condition fails trim window
            while(min(countT,countF) > k){
                if(str[i]=='T') countT--;
                else
                countF--;
                i++;
            }
            ans = max(ans,countF + countT);
            j++;
        }
        return ans;
    }
