// *** Quick sort  *** 
// Time Complexity: O(N*log N) 
// Space Complexity: O(N) 

#include<iostream>
using namespace std;

void dispalyArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int MergeArray(int *arr,int low,int mid, int high){
     
    int i=low,j=mid+1,index = low;
    int temp[high];

    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[index++]=arr[i++];
        }else{
            temp[index++]=arr[j++];
        }
    }
    while(i<= mid){
        temp[index++]=arr[i++];
    }
    while(j<=high){
        temp[index++] = arr[j++];
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i];
    }

}

void MergeSort(int *arr,int low,int high){

    int mid;
   
   if(low < high){
        mid = mid = low+(high-low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        MergeArray(arr,low,mid,high);
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

    MergeSort(arr,0,size-1);

    cout<<"Array after sorting:";
    dispalyArr(arr,size);

    return 0;
}