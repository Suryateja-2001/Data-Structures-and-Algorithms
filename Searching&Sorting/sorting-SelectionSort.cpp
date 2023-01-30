// *** Selection Sort ***
// Time Complexity: O(N*N)
// Space Complexity: O(1)

#include<iostream>
using namespace std;

void dispalyArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *first,int *sec){

    int temp = *first;
    *first = *sec;
    *sec = temp;
}

void SelectionSort(int *arr,int size){

    for(int i=0;i<size;i++){
        int min_index=i;
        for (int j = i+1; j < size; j++){
            if(arr[min_index]>arr[j]){
                min_index = j;
            }
        }

        swap(&arr[min_index],&arr[i]);
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

    SelectionSort(arr,size);

    cout<<"Array after sorting:";
    dispalyArr(arr,size);

    return 0;
}