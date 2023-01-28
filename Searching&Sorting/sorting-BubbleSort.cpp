// *** Bubble Sort is a swapping Algorithm ***
// Time Complexity : O(N*N)
// Space Complexity : O(1)
// No.of operations performed is N*(N-1)/2 where N is no.of elements.

#include<iostream>
using namespace std;

void dispalyArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort(int *arr,int size){
    for (int i = 0; i < size-1; i++){
        bool flag=0;
        for(int j = 1; j < size-i ;j++){
            if(arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                flag = 1;
            }
        }
        if(!flag) break;                // if no swapping happens this statement executes and exits from the loop.
    }
    
}

int main(){
    int size;

    cout<<"Enter the size of array:";
    cin>>size;

    int arr[size];
    cout<<"Enter elements:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array before sorting:";
    dispalyArr(arr,size);

    BubbleSort(arr,size);

    cout<<"Array after sorting:";
    dispalyArr(arr,size);

    return 0;
}