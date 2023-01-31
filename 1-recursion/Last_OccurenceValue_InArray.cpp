// Returning the index of Last Occurence of the given value in array using recursion. 
// If the given value is not present then it returns the size of array.
#include<iostream>
using namespace std;
/*
bool Last_Occurnce(int *arr,int size,int val, int count=0){
    if(count == size) return 0;
    bool flag = Last_Occurnce(arr,size,val,count+1);
    if(flag){
        return 1;
    }
    if(val == arr[count]){
        cout<<val<<" found at index: "<<count;
        return 1;
    }
    return 0;
}
*/
int Last_Occurnce(int *arr,int size,int val, int count=0){

    if(count == size) return size;

    if(val == arr[size-count-1]) {
        return size-count-1;
    }

    return Last_Occurnce(arr,size,val,count+1);

}
int main(){

    int size,val;

    cout<<"Enter the size of array:";
    cin>>size;

    cout<<"Enter the Elements of array:";
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Enter val to be searched:";
    cin>>val;

    
    cout<<val<<" found at index: "<<Last_Occurnce(arr,size,val);
}