// checking if a string is Palindrome or not by recursion.
#include<iostream>
using namespace std;

bool PalindromeStr(string str,int count=0){
    if(count == str.size()/2) return 1;

    if(str[count] == str[str.size()-count-1]) {
        return PalindromeStr(str,++count);
    }

    return 0;
}

int main(){
    string str;

    cout<<"Enter the string:";
    cin>>str;

    cout<<PalindromeStr(str);

    return 0;
}