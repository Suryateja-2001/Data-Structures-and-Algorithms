/*
Caesar Cipha Encryptor
Given a non-empty string of lowercase letters and a non-negative integer representing a key, 
write a function that returns a new string obtained by shifting every letter in the input string by k positions in the alphabet, 
where k is the key

Sample Input
String = “xyz”
Key = 2

Sample Output
“zab”
*/

#include<iostream>
using namespace std;

string caesarCipher(string str, int key){

    string ans;
    key = key>26? key%26 : key;

    for(int i=0;i<str.size();i++){

        int temp = (int)str[i]+key;
        
        if(temp > int('z')){
            temp = temp - int('z');
            temp = int('a')+temp-1;
        }
        ans+=char(temp);

    }

  return ans;  

}

int main(){
    string str;
    int key;

    cin>>str>>key;
    cout<<caesarCipher(str,key);

    return 0;
}