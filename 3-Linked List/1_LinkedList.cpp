// Linked List using struct, malloc.

#include<iostream>
using namespace std;

//Node of linkedlist dataStructure
struct Node{
    int data;
    struct Node* next;      // "next"  stores the address of " struct Node* " datatype
};

void InsertNode(struct Node* *head,int val){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  //creating newnode for insertion

    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
       
}

void InsertNode_End(struct Node* *head,int val){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  //creating newnode for insertion
    newNode->data = val;

    if(*head == nullptr){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // moving to the last element in list
    struct Node* temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

void InsertNode_Pos(struct Node* *head,int val,int pos){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  //creating newnode for insertion
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
    struct Node* temp = *head;
    while(count < pos){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

void DeleteElement(struct Node* *head){
    
    if(*head == nullptr){ 
        cout<<"List is Empty!"<<endl;
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    cout<<temp->data<<" is deleted"<<endl;

}

void display(struct Node* node){ 
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
        cout<<"\n1 for Insert || 2  for Insert at End || 3 for Insert at Position || 4 for Delete the Element || 5 for Display"<<endl;
        cout<<"Enter the number to perform Operation:";
        int op;
        cin>>op;
        
        int Element,Position;
        if(op != 4 && op != 5){
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
                DeleteElement(&head);
                break;
            case 5:
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