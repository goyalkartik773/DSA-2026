// blackslex --> elevator going through several floors in fixed order
// moving from one floor to another floor took absolute difference time between the floor numbers
// need to minimize the travel time can skip one floor between
#include<iostream>
#include<vector>
using namespace std;
/*
int solve(vector<int>& arr,int idx,int skip)
{
    if(idx >= arr.size()-1)
    {
        return 0;
    }
    int r1 = INT_MAX;
    int r2 = INT_MAX;
    if(skip!=0)
    {
        r1 = 0 + solve(arr,idx+1,skip-1);
    }
    else
    {
        if(idx + 1 < arr.size())
            r2 = abs(arr[idx+1]-arr[idx]) + solve(arr,idx+1,skip);
    }
    return min(r1,r2);
}*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
       /* vector<int> diff;
        for(int i=1;i<n;i++){
            diff.push_back(abs(arr[i]-arr[i-1]));
        }
        int idx = -1;
        int maxDiff = INT_MIN;
        for(int i=0;i<diff.size();i++){
            if(maxDiff < diff[i]){
                maxDiff = diff[i];
                idx = i;
            }
        }
        vector<int> actual;
        for(int i=0;i<n;i++){
            if(idx!=i)
                actual.push_back(arr[i]);
        }
        int result = 0;
        for(int i=1;i<actual.size();i++){
            result += abs(actual[i]-actual[i-1]);
        }
        cout<<result<<endl; */

        int maxProfit = 0;
        // try to skip first element;
        maxProfit = max(maxProfit,abs(arr[1]-arr[0]));
        // try to skip last element;
        maxProfit = max(maxProfit,abs(arr[n-1]-arr[n-2]));
        // try to remove ith element;
        for(int i=1;i<=n-2;i++){
            int profit = abs( abs(arr[i]-arr[i-1]) + abs(arr[i]-arr[i+1]) - abs(arr[i+1]-arr[i-1]) );
            maxProfit = max(maxProfit,profit);
        }
        // total cost
        int totalCost = 0;
        for(int i=1;i<n;i++){
            totalCost += abs(arr[i]-arr[i-1]);
        }
        cout<<totalCost-maxProfit<<endl;
    }
}
