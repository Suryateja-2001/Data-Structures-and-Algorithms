// Largest rectangle with all 1's
// Time Complexity O(R*C)

#include<iostream>
#include<stack>
#include<algorithm>
#define C 4
#define R 4
using namespace std;

int CurrMaxArea(int *arr,int size){
    int max_area=0,curr_area,topIndex_stack;
    stack<int>PrevSmall;

    for(int i=0;i<size;i++){

        while(!PrevSmall.empty() && arr[PrevSmall.top()] >= arr[i]){
            topIndex_stack = PrevSmall.top();
            PrevSmall.pop();

            curr_area = arr[topIndex_stack] *(PrevSmall.empty()?i:i-PrevSmall.top()-1);
            max_area = max(curr_area,max_area);
        }

        PrevSmall.push(i);
    }

    while(!PrevSmall.empty()){
        topIndex_stack = PrevSmall.top();
        PrevSmall.pop();
        curr_area = arr[topIndex_stack]*(PrevSmall.empty()?size:PrevSmall.top()-size-1);
        max_area = max(max_area,curr_area);
    }

    return max_area;
}

int MaxArea(int mat[][C]){
    int res = CurrMaxArea(mat[0],C);

    for(int i=1;i<R;i++){
        for(int j=0;j<C;j++){
            if(mat[i][j])
                mat[i][j] = mat[i-1][j]+mat[i][j];
        }
        res = max(res,CurrMaxArea(mat[i],C));
    }

    return res;
}

int main()
{
    int mat[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Maximum rectangle is:  " << MaxArea(mat);

    return 0;
}