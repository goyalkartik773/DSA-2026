// ...existing code...
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> result(n,-1);
        stack<int> st;
        // next , prev greater element puch to use stack
        for(int i=n-1;i>=0;i--){
            while(st.size()!=0 && mp[arr[i]] >= mp[st.top()]){
                st.pop();
            }
            if(st.size()!=0)
            result[i] = st.top();
            
            st.push(arr[i]);
        }
        return result;
    }
};
