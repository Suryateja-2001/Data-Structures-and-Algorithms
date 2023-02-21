/*
Given is a string S made up of the parentheses "(" and ")" at the beginning and end.
Find the length of the longest parenthesis substring that is still valid.
A parenthesis string is legitimate if
-----> There is a closing parenthesis for each starting parenthesis.
-----> The correct order must be used to close opening parenthesis. 

Input : ((())
Output : 4

Explanation : ( ( ) ) whose length is 4.
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int parenthesisLength(string str){
    int max_val=0;
    stack<int>index;
    index.push(-1);

    for(int i=0;i<str.size();i++){

        if(str[i] == '('){

            index.push(i);

        }else{ // if it is closing bracket

            if( -1 < index.top() && str[index.top()] == '('){
                index.pop();
                max_val=max(max_val,i-index.top());
            }else{
                index.push(i);
            }
        }
    }
    
    
    return max_val;
}

int main(){
    string str;

    cout<<"Enter the string:";
    cin>>str;
    cout<<parenthesisLength(str);

    return 0;
}