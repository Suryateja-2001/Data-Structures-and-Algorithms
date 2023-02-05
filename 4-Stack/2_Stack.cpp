// stack using array and global functions

#include <iostream>
using namespace std;

#define arr_size 10
int arr[arr_size];
int size = -1;

void push(int val){
    if(size == arr_size-1){
        cout<<"Stack is full"<<endl;
        return;
    }
    arr[++size] = val;
}

void pop(){
    if(size == -1){
        cout<<"stack is Empty!"<<endl;
        return;
    }
    cout<<arr[size]<<" is Popped"<<endl;
    size--;
}

int peek(){
    if(size == -1){
        cout<<"stack is Empty!"<<endl;
        return INT32_MIN;
    }
    return arr[size];
}

void display(){
    if(size == -1){
        cout<<"stack is Empty!"<<endl;
        return;
    }

    for(int i=size;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    bool flag;

    do{
        cout<<"\n1 To Push Element || 2  To POP Element || 3 To Get Top Element || 4 To Display all Elements"<<endl;
        cout<<"Enter the number to perform Operation:";
        int op;
        cin>>op;
        
        int Element;
        if(op == 1){
            cout<<"Enter the element:";
            cin>>Element;
        }

        switch (op)
        {
            case 1:
                push(Element);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout<<"Top Element of stack is "<<peek()<<endl;
                break;
            case 4:
                display();
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);

    return 0;
}