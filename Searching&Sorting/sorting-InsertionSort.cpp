// *** Insertion Sort --> Inserting elements ***
// Time Complexity : O(N*N)
// Space Complexity: O(1)

#include<iostream>
using namespace std;

void dispalyArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//array =  1 5 11 15(j = i-1) 2(i = 4) 8 
// 1 5 11 15 15 8   target = 2
// 1 5 11 11 15 8   target = 2            ---> for 5th iteration
// 1 5  5 11 15 8   target = 2
// 1 2  5 11 15 8

void InsertionSort(int *arr,int size){
 
   int j,i;
   for(int i=1;i<size;i++){

        j=i-1;
        int target = arr[i];

        while(j >= 0 && target < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target;
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

    InsertionSort(arr,size);

    cout<<"Array after sorting:";
    dispalyArr(arr,size);

    return 0;
}