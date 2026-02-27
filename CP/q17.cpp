#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        stack<char> st;
        st.push(str[0]);
        for(int i=1;i<n;i++){
                bool flag = false;
            if(st.size()!=0 && st.top() == str[i]){
            st.pop();
            }
            else
            st.push(str[i]);
        }
        if(st.empty())cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
