/*
Create a data structure called SpecialStack that supports all stack operations, including push(), pop(), isEmpty(), and isFull(),
as well as the extra method getMin(), which should return the Special Stack's  minimum element. 

Input : let stack elements are 
23
24
12
27
76

Output : 12
*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int getMin(stack<int> &st){
    if(st.empty()) return INT32_MAX;

    int temp = st.top();
    st.pop();
    int minEle = min(getMin(st),temp);
    st.push(temp);

    return minEle;
}

int main(){

    stack<int>st;

    st.push(76);
    st.push(27);
    st.push(12);
    st.push(24);
    st.push(23);

    cout<<"The minimum element in the stack is "<<getMin(st);
    

    return 0;
}