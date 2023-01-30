// *** Quick sort  *** 
// Time Complexity: O(N*N) -> worstcase, O(N*log N) -> average and bestcase
// Space Complexity: O(1) 

#include<iostream>
using namespace std;

void dispalyArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void SwapElements(int *first,int *sec){
    int temp = *first;
    *first = *sec;
    *sec = temp; 
}

int PartitionArray(int *arr,int low, int high){
    int swapIndex = low-1;
    int Pivot = arr[high];   // choosing the pivot element as last element of array

    // arranging the elements according to pivot element i.e small elements left and big on right
    for(int i=low;i<high;i++){

        if(arr[i] < Pivot){
            swapIndex++;
            SwapElements(&arr[i], &arr[swapIndex]);
        }
    }
    swapIndex++;
    SwapElements(&arr[high], &arr[swapIndex]);

    return swapIndex; 

}

void QuickSort(int *arr,int low,int high){
   
   if(low < high){

        int indexPI = PartitionArray(arr,low,high);

        QuickSort(arr,low,indexPI-1);
        QuickSort(arr,indexPI+1,high);
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

    QuickSort(arr,0,(size-1));

    cout<<"Array after sorting:";
    dispalyArr(arr,size);

    return 0;
}