// stack using struct, new & vectors

#include<iostream>
#include<vector>
using namespace std;

struct Stack{
    vector<int>vec;
    int size;

    Stack(){
        size = -1;
    }

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(vec.size() == 0){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        cout<<vec.back()<<" is popped"<<endl;
        vec.pop_back();
    }

    int peek(){
        if(vec.size() == 0){
            cout<<"Stack is empty!"<<endl;
            return INT32_MIN;
        }
        return vec.back();
    }

    void display(){
        if(vec.size() == 0){
            cout<<"Stack is empty!"<<endl;
            return;
        }

        cout<<"Elements in the stack:";
        vector<int>::iterator it;
        for(it = vec.end()-1; it >= vec.begin(); it--){
            cout<<" "<<*it;
        }
        cout<<endl;
    }

};

int main(){

    Stack stack;

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
                stack.display();
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);


    return 0;
}