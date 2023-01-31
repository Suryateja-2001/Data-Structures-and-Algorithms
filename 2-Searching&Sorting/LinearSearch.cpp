// checking if value is present or not using Linear Search. If value is present return index otherwise return size of array.

#include<iostream>
using namespace std;

int LinearSearch(int *arr,int size,int val){
    
    for(int i=0;i<size;i++){
        if(arr[i] == val){
           return i;
        }
    }
   return size;
}

int main(){
    int size,val,index;

    cout<<"Enter the Size of array:";
    cin>>size;

    int arr[size];
    cout<<"Enter the Elements of array:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Enter Value to be searched:";
    cin>>val;

    index = LinearSearch(arr,size,val);
    (index == size)? cout<<"Value Not Found!!!"<<endl : cout<<val<<" found at index:"<<index<<endl;

    return 0;
}