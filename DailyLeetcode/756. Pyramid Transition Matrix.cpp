#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
    unordered_map<string,bool> t;
    bool solve(string curr, int idx, string above,unordered_map<string, vector<char>>& mp) {

        // so many repeating subproblems are there would do optimisation using memoization
        string key = curr + "_" + to_string(idx) + "_" + above;
        if(t.find(key)!=t.end())
        return t[key];
        // base case
        if (curr.length() == 1) {
            return t[key] = true;
        }

        if (idx + 1 == curr.length()) {
            // mtlb apne iss curr string ke sare pairs ko visit karliya hai move
            // to above string
            return t[key] = solve(above, 0, "", mp);
        }

        string pair = curr.substr(idx, 2);
        if (!(mp.find(pair) != mp.end()))
            return t[key] = false; // agar pair hi nahi hai allowed string mai to pyramid
                          // nahi ban sakta

        for (auto ch : mp[pair]) {
            above.push_back(ch); // do
            if (solve(curr, idx + 1, above, mp) ==
                true) // explore this current state
                return t[key] = true;
            above.pop_back(); // agar iss state per solution nahi milta to
                              // revert back kardo and try new state
        }
        return t[key] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // first we will make an unordered_map taki easily pairs sai above char
        // mil sake
        unordered_map<string, vector<char>> mp;
        for (auto ele : allowed) {
            string key = ele.substr(0, 2);
            mp[key].push_back(ele[2]);
        }
        return solve(bottom, 0, "", mp);
    }
int main(){
    return 0;
}