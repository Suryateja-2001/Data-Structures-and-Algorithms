// print frequency of each element in an array

#include<iostream>
#include<algorithm>
using namespace std;

/* 
* Navie Approach
* Time Complexity : O(N*N)
* Space Complexity : O(1)
*/ 
void PrintFrequency(int *arr,int size){

    for(int i=0;i<size;i++){
        bool flag = 0;
        for(int j=i+1;j<size;j++){

            if(arr[i]==arr[j]){
                flag = 1;
                break;
            }
        }

        if(flag == 1) continue;

        int count = 0;
        for(int j=0;j<=i;j++){
            if(arr[i] == arr[j]) count++;
        }
        cout<<arr[i]<<" : "<<count<<endl;
    }
}

/* 
* Best Approach
* Time Complexity : O(N *logN)
* Space Complexity : O(1)
*/ 

void DisplayFrequency(int arr[], int size){
    sort(arr,arr+size);                         //O(N *logN)
    int count=1;

    for(int i=0;i<size;i++){                    // O(N)

        if(arr[i] == arr[i+1]){
            count++;
        }else{
            cout<<arr[i]<<" : "<<count<<endl;
            count = 1;
        }
    }

}


int main(){
    int size;
    cout<<"Enter the size:";
    cin>>size;

    int arr[size];
    cout<<"Enter the elements:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    PrintFrequency(arr,size);
    DisplayFrequency(arr,size);

}