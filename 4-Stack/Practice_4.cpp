//Span of the stock (Optimised Approach)
// Time Complexity = O(N)

#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int *arr,int size){
    stack<int>index;

    for(int i=0;i<size;i++){
        if(i==0){
            cout<<1<<" ";
            index.push(i);
            continue;
        }
        while(!index.empty() && arr[index.top()] <= arr[i]){
            index.pop();
        }
        if(index.empty()) {
            cout<<i+1<<" ";
            index.push(i);
            continue;
        }
        cout<<i-index.top()<<" ";
        index.push(i);
    }
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(int);

    stockSpan(arr,size);


    return 0;
}