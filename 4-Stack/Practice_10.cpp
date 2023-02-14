// Previous smallest element in array of given index (Optimised Approach)
// Time Complexity O(N)

#include<iostream>
#include<stack>
using namespace std;

void prevSmallest(int arr[],int size){
    stack<int>PrevSm;
    cout<<"- ";
    PrevSm.push(arr[0]);
    for(int i=1;i<size;i++){
        while(!PrevSm.empty() && PrevSm.top()>arr[i]){
            PrevSm.pop();
        }

        if(PrevSm.empty()){
            cout<<"- ";
        }else{
            cout<<PrevSm.top()<<" ";
        }
        PrevSm.push(arr[i]);
    }
}

int main(){

    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevSmallest(arr,size);

    return 0;
}