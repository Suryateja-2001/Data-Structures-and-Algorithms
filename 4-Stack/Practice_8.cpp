//Next Greater element in array of given index (Optimised Approach)
// Time Complexity O(N)

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextGreater(int arr[],int size){
    stack<int>GtEle;
    vector<int>vec;

    vec.push_back(INT32_MIN);
    GtEle.push(arr[size-1]);

    for(int i=size-2;i>=0;i--){
        
        while (!GtEle.empty() && GtEle.top() <= arr[i]){
            GtEle.pop();
        }

        int val = GtEle.empty()? INT32_MIN: GtEle.top();
        vec.push_back(val);
        GtEle.push(arr[i]);
        
    }
    reverse(vec.begin(),vec.end());
    return vec;
}

int main(){

    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(auto ele : nextGreater(arr, size)){
        if(ele == INT32_MIN){
            cout<<"- ";
        }else{
            cout<<ele<<" ";
        }
    }


    return 0;
}