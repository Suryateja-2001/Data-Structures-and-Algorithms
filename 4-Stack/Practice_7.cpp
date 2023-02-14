//Next Greater element in array of given index (Naive Approach)
// Time Complexity : O(N*N)

#include<iostream>
using namespace std;

void nextGreater(int *arr,int size){
    for(int i=0;i<size;i++){
        bool flag = 0;
        for(int j=i+1;j<size;j++){

            if(arr[j] > arr[i]){
                cout<<arr[j]<<" ";
                flag = 1;
                break;
            }

        }
        if (!flag){
            cout<<"- ";
        }
        
    }
}

int main(){

    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, size);

    return 0;
}