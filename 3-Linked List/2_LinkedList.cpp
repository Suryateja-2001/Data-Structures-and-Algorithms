// singly Linked list using class, new and external functions
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void InsertNode(Node* *head,int val){
    Node* newNode = new Node();  // allocating memory dynamically

    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void InsertNode_End(Node* *head,int val){
    Node* newNode = new Node();  // allocating memory dynamically
    newNode->data = val;

    if(*head == nullptr){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // moving to the last element in list
    Node* temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void InsertNode_Pos(Node* *head,int val,int pos){
    Node* newNode = new Node();  // allocating memory dynamically
    newNode->data = val;

    if(pos == 0){
        cout<<"Please enter a position greater than 0."<<endl;
        return;
    }

    if(pos == 1){
        InsertNode(head,val);
        return;
    }

    int count =2;
    Node* temp = *head;
    while(count < pos){
        if(temp->next == nullptr) break;
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void Delete(Node* *head){
    if(*head == nullptr){ 
        cout<<"List is Empty!"<<endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    cout<<temp->data<<" is deleted"<<endl;
    delete(temp);
}

void DeleteElement(Node* *head,int val){
    if(*head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }
    Node* temp = *head;
    while(temp->next->next != nullptr && temp->next->data != val){
        temp = temp->next;
    }

    Node* free_temp;  // used to delete the element from memory

    if(temp->next->data == val){
        free_temp = temp->next;
        temp->next = temp->next->next;
        delete(free_temp);
        cout<<val<<" is deleted"<<endl;
        return;
    }

    cout<<val<<" is not present in list"<<endl;
    
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

    bool flag = 0;
    struct Node* head = nullptr;  // stores the  head address of linkedlist

    do{
        cout<<"\n1 for Insert || 2  for Insert at End || 3 for Insert at Position || 4 to Delete first Element || 5 To Delete the given Element || 6 for Display"<<endl;
        cout<<"Enter the number to perform Operation:";
        int op;
        cin>>op;
        
        int Element,Position;
        if(op != 4 && op != 6){
            cout<<"Enter the element:";
            cin>>Element;
        }

        if(op == 3){
            cout<<"Enter the Position:";
            cin>>Position;
        }

        switch (op)
        {
            case 1:
                InsertNode(&head,Element);
                break;
            case 2:
                InsertNode_End(&head,Element);
                break;
            case 3:
                InsertNode_Pos(&head,Element,Position);
                break;
            case 4:
                Delete(&head);
            case 5:
                DeleteElement(&head,Element);
                break;
            case 6:
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