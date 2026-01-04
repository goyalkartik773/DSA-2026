#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int checkAndGive(int ele) {
        int lmt = sqrt(ele);
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= lmt; i++) {
            if (ele % i == 0) {
                if(i!=ele/i){
                count += 2;
                sum += i;
                sum += ele / i;
                }
                else{
                    count += 1;
                    sum += i;
                }
            }
        }
        if (count == 4)
            return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (auto ele : nums) {
            result += checkAndGive(ele);
        }
        return result;
    }
};