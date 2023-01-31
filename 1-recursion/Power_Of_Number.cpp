// power of a number using recursion

#include<iostream>
using namespace std;

int pow_fun(int base,int power){

    if(base == 1 || power == 0) return 1;

    return base*pow_fun(base,power-1);
}

int main(){
    int base,power;

    cout<<"Enter base and power: ";
    cin>>base>>power;

    cout<<pow_fun(base,power);

    return 0;
}