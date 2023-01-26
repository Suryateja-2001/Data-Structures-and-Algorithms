// returning the factorial of a number using recursion

#include<iostream>
using namespace std;

int factorial(int n){

    if(n == 1) return n;

    return n*factorial(n-1);

}

int main(){

    int number;

    cout<<"Enter the number:";
    cin>>number;

    cout<<factorial(number);


    return 0;
}