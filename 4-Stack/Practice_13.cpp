// largest rectangular area under a histogram (Optimised Approach)
// Time Complexity O(N)       
// Space Complexity O(1)

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


int maxArea(int *arr,int size){

    stack<int>prevSmall;         // stores the index of previous small element
    int max_area=0;
    int Curr_area,topIndex_inStack;

    for(int i=0;i<size;i++){

        while(!prevSmall.empty() && arr[prevSmall.top()] >= arr[i]){

            topIndex_inStack = prevSmall.top();
            prevSmall.pop();
            Curr_area = arr[topIndex_inStack] * (prevSmall.empty()?i:i-prevSmall.top()-1);
            max_area = max(max_area,Curr_area);

        }
        prevSmall.push(i);
    }

    // for elements which are remaning in stack in increasing order
    while(!prevSmall.empty()){

        topIndex_inStack = prevSmall.top();
        prevSmall.pop();
        Curr_area = arr[topIndex_inStack] * (prevSmall.empty()?size:size-prevSmall.top()-1);
        max_area = max(max_area,Curr_area);

    }

    return max_area;

}

int main(){
    int arr[] = {12, 2, 5, 4, 1, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"The maximum area is "<<maxArea(arr,size);

    return 0;
}