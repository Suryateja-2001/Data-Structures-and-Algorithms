// checking if value is present or not using Binary Search. If value is present return index otherwise return -1.
// ******** Binary Search is used only when a elements in Data Structure are sorted.  *********
// Time Complexity = O(log n) 
// Space Complexity = O(log n) -> as we are using recursive approach. for iterative it will be O(1) space complexity.

#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> &nums, int &target, int left, int right){

        if(right >= left){
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return mid;

            if(target < nums[mid]){
                return BinarySearch(nums,target,left,mid-1);
            }

            if(target > nums[mid]){
                return BinarySearch(nums,target,mid+1,right);
            }

        }
            return -1;
    }


int main(){
    int size,target,index;

    cout<<"Enter the Size of array:";
    cin>>size;

    vector<int>nums;
    cout<<"Enter the Elements of array:";
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<"Enter Value to be searched:";
    cin>>target;
    cout<<BinarySearch(nums,target,0,size-1);
    return 0;
}