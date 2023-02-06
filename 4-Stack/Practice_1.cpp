// Balanced Parenthesis problem
#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str){
    stack<char>st;

    for(int i=0;i<str.size();i++){

        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);
            continue;
        }

        if(st.top() == '('  && str[i] == ')'|| st.top() == '['  && str[i] == ']' || st.top() == '{'  && str[i] == '}'){
            st.pop();
            continue;
        }

        return 0;
    }

    return 1;
}

int main(){

    string str;

    cout<<"Enter a string:";
    cin>>str;

    if(isBalanced(str)){
        cout<<str<<" is balanced"<<endl;
    }else{
        cout<<str<<" is not balanced"<<endl;
    }

    return 0;
}