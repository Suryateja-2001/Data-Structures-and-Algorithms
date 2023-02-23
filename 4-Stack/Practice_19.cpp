/*
Calculate how much water a bar with a width of 1 on an elevation map (represented by an array of N non-negative integers) can hold after a rainstorm. 

Input :  
arr[] = {3,0,1}

Output : 1
*/

#include<iostream>
#include<stack>
using namespace std;

int maxWater(int *arr, int size){
   int water=0;
   stack<int>decOrder;

   for(int i=0;i<size;i++){
        while(!decOrder.empty() && arr[decOrder.top()] < arr[i]){
            int curr = decOrder.top();
            decOrder.pop();

            if(decOrder.empty()) break;

            int hDistance = i - decOrder.top() - 1;  //horizontal distance of block
            water += (min(arr[decOrder.top()], arr[i]) - arr[curr]) * hDistance;
        }
        decOrder.push(i);
   }

    return water;
}

int main(){
    int arr[]={ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxWater(arr, n)<<endl;

    int arr2[] = {3,0,1};
    cout << maxWater(arr2, 3)<<endl;

    int arr3[] = {2,1,0,4,3,1,1,3,5};
    cout << maxWater(arr3, 9);

    return 0;
}