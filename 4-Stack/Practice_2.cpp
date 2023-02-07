/*
Problem Statement
Determine the score of the provided string using the following rules after being given a string str 
that consists of pairs of balanced parentheses.

"()" has a 1 rating.
"x y" receives a score of x + y, where x and y are separate balanced pairs of parentheses.
"(x)" has a score twice as high as x, or 2 * the x-score.

Input :  ( () () )
Output : 4

Explanation :   ()() = 1+1 =2
                (x)  = 2 *x  = 2 * 2 = 4
*/

#include<iostream>
#include<stack>
using namespace std;

int parenthese_Score(string str){
    stack<string>st;
    int ans=0;

    for(int i=0;i<str.size();i++){

        if(str[i] == '('){
            st.push("(");
            continue;
        }

        if(str[i] == ')'){
            st.pop();
            st.push("1");

            
            // checks & evalutes the answer if parentheses is inside the parentheses
            if(i+1 < str.size()){
                continue;
            }

            if(str[i+1] == ')'){
                int temp=0;
                while(st.top() != "("){
                    temp+=1;
                    st.pop();
                }

                i++;
                st.pop();
                st.push(to_string(temp*2));
            }

        }
    }

    while(!st.empty()){
        ans += stoi(st.top());
        st.pop();
    }


    return ans;
}

int main(){
    string str;

    cout<<"Enter the Parentheses string:";
    cin>>str;
    cout<<"The score of the parentheses:"<<parenthese_Score(str);

    return 0;
}
