// Stack using array,Struct,malloc

#include<iostream>
using namespace std;

struct Stack{
    int arr_size;
    int top;
    int* arr;
};

// creating a stack and return the address of stack
struct Stack* create(int size){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->arr_size = size;
    stack->top = -1;
    
    // allocates the memory of "arr[size]"
    stack->arr = (int*) malloc(sizeof(int)*size);
}

// To check if stack is full or not
bool isFull(struct Stack* stack){
    if(stack->top == stack->arr_size-1){
        return 1;
    }
    return 0;
}

// To check if stack is empty or not
bool isEmpty(struct Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

// To push the element into the stack
void push(struct Stack* stack, int val){
    if(isFull(stack)){
        cout<<"stack is full"<<endl;
        return;
    }

    //pushes the element 
    stack->arr[++stack->top] = val;
}

// To pop the element from the stack
void pop(struct Stack* stack){
    if(isEmpty(stack)){
        cout<<"Stack is empty"<<endl;
        return;
    }

    cout<<"Popped Element :"<<stack->arr[stack->top--]<<endl;
}

// To return the top element of stack
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        cout<<"Stack is empty"<<endl;
        return INT32_MIN;
    }

    return stack->arr[stack->top];
}

// To return the size of stack
int stackSize(struct Stack* stack){
    return stack->top+1;
}

int main(){
    int size;
    cout<<"Enter the size of stack:";
    cin>>size;
    struct Stack* stack = create(size);

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
                push(stack,Element);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                cout<<"Top Element of stack is "<<peek(stack)<<endl;
                break;
            case 4:
                cout<<"Size of the stack is "<<stackSize(stack)<<endl;
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);


    return 0;
}