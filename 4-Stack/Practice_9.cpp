// Next smallest element in array of given index (Optimised Approach)
// Time Complexity O(N)

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nextSmallest(int *arr,int size){
    stack<int>SmEle;
    vector<int>vec;

    SmEle.push(arr[size-1]);
    vec.push_back(INT32_MAX);

    for(int i=size-2;i>=0;i--){
        while (!SmEle.empty() && SmEle.top()>=arr[i]){
            SmEle.pop();
        }

        int val = SmEle.empty() ?INT32_MAX:SmEle.top();
        SmEle.push(arr[i]);
        vec.push_back(val); 
    }
    reverse(vec.begin(),vec.end());
    return vec;

}

int main(){

    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(auto ele : nextSmallest(arr,size)){
        if(ele == INT32_MAX){
            cout<<"- ";
        }else{
            cout<<ele<<" ";
        }
    }

    return 0;
}