#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int result = INT_MIN;
int dp[10][2];
int dp2[10][2][2];
void f(vector<bool> &black, vector<int> &arr, int idx) {
  if (idx == black.size()) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (black[i])
        continue;
      if (i - 1 >= 0 && black[i - 1] == true && !black[i]) {
        sum += arr[i];
      }
    }
    result = max(result, sum);
    return;
  }
  black[idx] = true;
  f(black, arr, idx + 1);
  black[idx] = false;
  f(black, arr, idx + 1);
}
int ftd(bool isBlack,vector<int>& arr,int idx){
    if(idx == arr.size())
    return 0;
    if(dp[idx][isBlack]!=-1) return dp[idx][isBlack];
    int black = ftd(true,arr,idx+1);
    int white = ftd(false,arr,idx+1) + (isBlack?arr[idx]:0) ;
    return dp[idx][isBlack] = max(white,black);
}

void f1(vector<int> &arr,vector<bool>& black,int idx){
    if(idx==arr.size()){
        int sum  = 0;
        for(int i=0;i<arr.size();i++){
            if(black[i]) continue;
            else if(i-1 >= 0 && (black[i-1] || black[i+1]) && i+1 < arr.size())
            sum += arr[i];
        }
        result = max(result,sum);
        return;
    }
    black[idx] = true;
    f1(arr,black,idx+1);
    black[idx] = false;
    f1(arr,black,idx+1);
}

int ftd2(bool isPrevPrevBlack,bool isPrevBlack,vector<int>& arr,int idx){
    if(idx >= arr.size())
    return 0;
    if(dp2[idx][isPrevPrevBlack][isPrevBlack]!=-1)
    return dp2[idx][isPrevPrevBlack][isPrevBlack];
    int white = ftd2(isPrevBlack,false,arr,idx+1) + (!isPrevBlack && isPrevPrevBlack ? arr[idx-1]:0);
    int black = ftd2(isPrevBlack,true,arr,idx+1) +  (!isPrevBlack ? arr[idx-1]:0);
    return dp2[idx][isPrevPrevBlack][isPrevBlack] = max(white,black);
}
int main() { 
    vector<int> arr={2,7,4,6,5,4}; 
    int n = arr.size();
    vector<bool> black(n,false);
    memset(dp,-1,sizeof(dp));
    cout<<ftd(false,arr,0);
    //cout<<result<<" ";
}