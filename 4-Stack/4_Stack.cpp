//stack using struct and intialising variables using struct constructor

#include<iostream>
using namespace std;

struct Stack{
    int Max;
    int size;
    int* arr;
    Stack(int val){
        Max = val;
        size = -1;
        arr = new int [Max];
    }

    // pushing element into stack
    void push(int val){
        if(size == Max-1){
            cout<<"stack is full"<<endl;
            return;
        }
        arr[++size] = val;
    }

    // poping element from stack
    void pop(){
        if(size == -1){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<arr[size--]<<" is Popped"<<endl;
    }

    // display the top element
    int peek(){
        if(size == -1){
            cout<<"Stack is empty!"<<endl;
            return INT32_MIN;
        }
        return arr[size];
    }

    // returning the  size of stack
    int stackSize(){
        return size+1;
    }
};

int main(){
    int size;

    cout<<"Enter the size of stack:";
    cin>>size;
    Stack stack(size);

    bool flag;

    do{
        cout<<"\n1 To Push Element || 2  To POP Element || 3 To Get Top Element || 4 To get the Size of Stack"<<endl;
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
                stack.push(Element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"Top Element of stack is "<<stack.peek()<<endl;
                break;
            case 4:
                cout<<"Size of the stack is "<<stack.stackSize()<<endl;
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);


    return 0;
}