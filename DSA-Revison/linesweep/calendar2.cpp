#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        mp.clear();
    }
    bool book(int startTime, int endTime) {
        int sum = 0;
        mp[startTime]+=1;
        mp[endTime]-=1;
        for(auto &ele:mp){
            int vs = ele.second;
            sum += vs;
            if(sum > 2){
                // matlab iss interval mai humne double booking kardi jo ki allowed nahi hai
                // remove bookings first;
                mp[startTime]-=1;
                mp[endTime]+=1;
                return false;
            }
        }
        return true;   
    }
};
int main(){
    
}