#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;
    long long maximizeSquareArea(int m, int n, vector<int>& a, vector<int>& b) {
        // return maximum square formed by deleting fences if need
        // square is whose width and height are same
        // try to remove each fence and ask is usski width ke barbar height mil sakti hai kya
        vector<int> arr = a;
        vector<int> brr = b;
        unordered_set<long long> st1;
        arr.push_back(1);
        arr.push_back(m);
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                st1.insert(abs(arr[j]-arr[i]));
            }
        }
        unordered_set<long long> st2;
        brr.push_back(1);
        brr.push_back(n);
        for(int i=0;i<brr.size();i++){
            for(int j=i+1;j<brr.size();j++){
                st2.insert(abs(brr[j]-brr[i]));
            }
        }
        long long result = -1;
        for(auto ele:st1){
            if(st2.find(ele)!=st2.end()){
                long long area = (ele * ele) % MOD;
                result = max(result,area);
            }
        }
        return result;
    }
};