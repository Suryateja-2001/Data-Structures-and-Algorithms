// Infix to prefix

#include<iostream>
#include<stack>
using namespace std;

int opPrecedence(char st){
    if(st == '+' || st == '-') return 1;
    else if(st == '*' || st == '/') return 2;
    else if(st == '^') return 3;
    else return -1;
}

bool checkIfOperator(char str){

    if(str =='+' || str == '*' || str == '/' || str == '-'|| str == '^'|| str == '('|| str == ')'){  
        return true;
    }

    return false;
}

string reverse(string &str){
    
    string temp;

    for(int i=str.size()-1;i>=0;i--){
        if( str[i]== ')') temp += '(';
        else if(str[i] == '(') temp += ')';
        else temp+=str[i];
    }

    str = temp;
}


string infixToPost(string str){

    string postfix="";
    stack<char>st;

    for(int i=0;i<str.size();i++){

        if(checkIfOperator(str[i])){

            if(str[i] == ')'){
                while(st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }

            if(str[i] == '(' || st.empty() || opPrecedence(str[i]) > opPrecedence(st.top()) ){
               
                st.push(str[i]);
                continue;
            }
            
            if(opPrecedence(str[i]) <= opPrecedence(st.top())){

                while(!st.empty() && st.top() != '(' && opPrecedence(str[i]) <= opPrecedence(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(str[i]);

            }

        }else{
            postfix += str[i];
        }

    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;

}

string infixTopre(string str){
    reverse(str);
    str = infixToPost(str);
    reverse(str);

    return str;
}

int main(){

    string str = "((a/b)+c)-(d+(e*f))";
    string preFix = infixTopre(str);
    cout<<preFix;
    return 0;
}