//Printing Elements in array in reverse Order by Recursion

#include<iostream>
using namespace std;

void PrintElements(int *arr,int size,int count = 0){

    if(count == size-1){
        cout<<arr[count]<<" ";
    }else{
        PrintElements(arr,size,1+count);
        cout<<arr[count]<<" ";
    }

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

    cout<<"Elements in reverse order:";
    PrintElements(arr,size);

    return 0;
}