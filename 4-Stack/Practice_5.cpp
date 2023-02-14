// Prevoius Greater element in array of given index (Navie Approach)
// TimeComplexity :- O(N*N)

#include<iostream>
using namespace std;

void prevGreatElement(int *arr,int size){
    
    for (int i = 0; i < size; i++){
        bool flag = 0;
        for(int j=i-1;j>=0;j--){
            if(arr[j] >arr[i]){
                flag = 1;
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(!flag) cout<<"- ";
    }
}

int main(){

    int arr[]={30, 50, 20, 15, 25};
    int size = sizeof(arr)/sizeof(arr[1]);
    prevGreatElement(arr,size);

    return 0;
}