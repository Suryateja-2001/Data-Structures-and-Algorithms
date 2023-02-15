// largest rectangular area under a histogram (Naive Approach)
// Time Complexity O(N*N)
// Space Complexity O(1)

#include<iostream>
using namespace std;

int maxArea(int *arr,int size){
    int ans=arr[0];
    for(int i=0;i<size;i++){
        int val,count=0;
        for(int j=i+1;j<size;j++){
            if(arr[i] <= arr[j]){
                count++;
                continue;
            }
            break;
        }

        for(int j=i-1;j>=0;j--){
            if(arr[i] <= arr[j]){
                count++;
                continue;
            }
            break;
        }

        val = count*arr[i];
        ans = max(val,ans);
    }

    return ans;
}

int main(){
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"The maximum area is "<<maxArea(arr,size);

    return 0;
}