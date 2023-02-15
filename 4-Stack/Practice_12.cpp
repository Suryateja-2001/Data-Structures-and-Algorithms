// largest rectangular area under a histogram (Naive Approach)
// Time Complexity O(N)       ------>>>>> (N+N+N)
// Space Complexity O(N)

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void psmallEle(int *arr,int *count,int size){
    stack<int>prevSmall;
    prevSmall.push(arr[0]);

    for(int i=1;i<size;i++){

        while(!prevSmall.empty() && prevSmall.top()>= arr[i]){
            prevSmall.pop();
            // counts no.of elements greater equal to arr[i] before arr[i]
            count[i] += 1;
        }
        prevSmall.push(arr[i]);
    }
}

void nsmallEle(int *arr, int *count,int size){
    stack<int>nxtSmall;
    nxtSmall.push(arr[size-1]);

    for(int i=size-2;i>=0;i--){

        while(!nxtSmall.empty() && nxtSmall.top()>= arr[i]){
            nxtSmall.pop();
            // counts no.of elements greater equal to arr[i] after arr[i]
            count[i] += 1;
        }
        nxtSmall.push(arr[i]);
    }
}

int maxArea(int *arr,int size){
    int ans=arr[0];
    int count[size]={1};

    psmallEle(arr, count, size);
    nsmallEle(arr, count, size);

    for(int i=0;i<size;i++){
        ans = max(ans,(arr[i] * count[i]));
    }

    return ans;
}

int main(){
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"The maximum area is "<<maxArea(arr,size);

    return 0;
}