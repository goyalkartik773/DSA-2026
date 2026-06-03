#include<iostream>
#include<vector>
using namespace std;
int searchElement(int arr[],int n,int key){
    int result  = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==key)
        result = i;
    }
    return result;
}
int main(){
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int key = 30;
    cout<<searchElement(arr,n,key);
}