#include<iostream>
#include<map>
using namespace std;
class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        int ans = 0;
        int sum = 0;
        for(auto &ele:mp){
            int vs = ele.second;
            sum += vs;
            ans = max(ans,sum);
        }
        return ans;
    }
};

int main(){

}