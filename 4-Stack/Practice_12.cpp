// largest rectangular area under a histogram (optimised Approach)
// Time Complexity O(N)       ------>>>>> (N+N+N)
// Space Complexity O(N)

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

/*
arr[] = {12, 2, 5, 4, 1, 7, 8}
stores the index of prev smaller of the respective index or if no value exist we store -1 as shown below.
prevcount[size] = {-1, -1, 1, 1,-1, 4, 5}
*/
void psmallEle(int *arr,int *count,int size){
    stack<int>prevSmall;

    for(int i=0;i<size;i++){

        while(!prevSmall.empty() && arr[prevSmall.top()] >= arr[i]){
            prevSmall.pop();
        }

        if(prevSmall.empty()){
            count[i] = -1;
        }else{
            count[i] = prevSmall.top();
        }
        prevSmall.push(i);
    }
}

void nsmallEle(int *arr, int *count,int size){
    stack<int>nxtSmall;

    for(int i=size-1;i>=0;i--){

        while(!nxtSmall.empty() && arr[nxtSmall.top()] >= arr[i]){
            nxtSmall.pop();
        }
        if(nxtSmall.empty()){
            count[i] = size;
        }else{
            count[i] = nxtSmall.top();
        }
        nxtSmall.push(i);
    }
}

int maxArea(int *arr,int size){
    int ans=arr[0];
    int prevcount[size],nextcount[size];

    psmallEle(arr, prevcount, size);
    nsmallEle(arr, nextcount, size);

    for(int i=0;i<size;i++){
        int temp = arr[i];

        temp += (i- prevcount[i]-1)*arr[i];
        temp += (nextcount[i]-i-1)*arr[i]; 

        ans = max(ans,temp);
    }

    return ans;
}

int main(){
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"The maximum area is "<<maxArea(arr,size);

    return 0;
}