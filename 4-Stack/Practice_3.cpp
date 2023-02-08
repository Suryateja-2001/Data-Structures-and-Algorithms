//Span of the stock (Naive Approach)
// Time Complexity = O(N*N)

#include<iostream>
using namespace std;

void stockSpan(int *arr,int size){
    cout<<"1 ";
    for(int i=1;i<size;i++){
        int count = 1;
        for(int j=i-1; j>=0 && arr[j] < arr[i]; j--){
            count++;
        }
        cout<<count<<" ";
    }
}

int main(){

    int arr[] = {10, 4, 5, 90, 120, 80};
    int size = sizeof(arr)/sizeof(int);

    stockSpan(arr,size);

    return 0;
}