// stack using class 

#include<iostream>
using namespace std;

class Stack{
    public:
    int Max;
    int size;
    int arr[];

    //constructor
    Stack(int val){
        Max = val;
        size = -1;
        arr[Max];
    }

};

// stack functions
void push(Stack* stack,int val){
    if(stack->size == stack->Max-1){
        cout<<"Stack is full"<<endl;
        return;
    }

    stack->arr[++stack->size] = val;
}

void pop(Stack* stack){
    if(stack->size == -1){
        cout<<"Stack is empty!"<<endl;
        return;
    }

    cout<<stack->arr[stack->size--]<<" is Popped"<<endl;
}

int peek(Stack* stack){
    if(stack->size == -1){
        cout<<"Stack is empty!"<<endl;
        return INT32_MIN;
    }

    return stack->arr[stack->size];
}

int stackSize(Stack* stack){
    return stack->size+1;
}

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
                push(&stack,Element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                cout<<"Top Element of stack is "<<peek(&stack)<<endl;
                break;
            case 4:
                cout<<"Size of the stack is "<<stackSize(&stack)<<endl;
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);


    return 0;
}

