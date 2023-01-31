/*
Find the middle element of LinkedList?
Input : 1,3,4,5,7
Output : 4

Explanation :  middle element is 4
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

 // Parameterised constructor 
    Node(int val){
        data = val;
    }
};

void InsertNode(Node* *head,int val){
    Node* newNode = new Node(val);  // allocating memory dynamically

    newNode->next = *head;
    *head = newNode;
}

int counter(Node* *head){
    int count = 0;

    if(*head == nullptr) return 0;
    Node* temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

void MiddleElement(Node* *head){
    int count = counter(head);
    if(count == 0){
        cout<<"List is Empty!"<<endl;
    }

    count /= 2;
    Node* temp = *head;
    while(count--){
        temp = temp->next;
    }
    cout<<"Middle Element is:"<<temp->data<<endl;
}

void display(Node* node){ 
   cout << "\n\n";
   // as linked list will end when Node is Null
  
   while(node!=NULL){ 
      cout << node->data << " ";
      node = node->next;
   }
   cout << "\n" << endl;
} 


int main(){
    Node* head = nullptr;
    bool flag ;

    do{
        cout<<"\n1 for Insert  || 2 for finding mid value || 3 for Display"<<endl;
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
                InsertNode(&head,Element);
                break;
            case 2:
                MiddleElement(&head);
                break;
            case 3:
                display(head);
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);
    return 0;
}