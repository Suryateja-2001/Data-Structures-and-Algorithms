// Prevoius Greater element in array of given index (Optimised Approach)
// TimeComplexity :- O(N)

#include<iostream>
#include<stack>
using namespace std;

void prevGreater(int *arr,int size){
    stack<int>gtval;

    // for i = 0
    cout<<"- ";
    gtval.push(arr[0]);

    for(int i=1;i<size;i++){

        while(!gtval.empty() && gtval.top() <= arr[i]){
            gtval.pop();
        }

        if(gtval.empty()){
            cout<<"- ";
        }else{
            cout<<gtval.top()<<" ";
        }
        gtval.push(arr[i]);
    }
}

int main(){
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, size);

    return 0;
}