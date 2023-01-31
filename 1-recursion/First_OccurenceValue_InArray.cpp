// Returning the index of first Occurence of the given value in array using recursion. 
// If the given value is not present then it returns the size of array.  

#include<iostream>
using namespace std;

int first_Occurnce(int *arr,int size,int val,int count=0){

    if(size == count) {
        cout<<"No Element found"<<endl;
        return count;
    }

    if(val == arr[count]) {
        cout<<val<<" found at index "<<count;
        return count;
    }

    return first_Occurnce(arr,size,val,++count);

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

    first_Occurnce(arr,size,val);


    return 0;
}