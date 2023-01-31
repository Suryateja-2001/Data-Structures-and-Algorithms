// singly Linked list using class, new and class member functions

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = nullptr;
    }

    Node(int n){
        this->data = n;
        this->next = nullptr; 
    }
};

class LinkedList{
    private:
    Node* head;

    public:

    // constructor
    LinkedList(){
        head = nullptr;
    }

    // list function
    void InsertNode(int val);
    void InsertNode_End(int val);
    void InsertNode_Pos(int val,int pos);
    void DeleteElement();
    void display(); 

};

void LinkedList::InsertNode(int val){
    Node* newNode = new Node();  // allocating memory dynamically

    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void LinkedList::InsertNode_End(int val){
    Node* newNode = new Node();  // allocating memory dynamically
    newNode->data = val;

    if(head == nullptr){
        newNode->next = head;
        head = newNode;
        return;
    }

    // moving to the last element in list
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::InsertNode_Pos(int val,int pos){
    Node* newNode = new Node();  // allocating memory dynamically
    newNode->data = val;

    if(pos == 0){
        cout<<"Please enter a position greater than 0."<<endl;
        return;
    }

    if(pos == 1){
        InsertNode(val);
        return;
    }

    int count =2;
    Node* temp = head;
    while(count < pos){
        if(temp->next == nullptr) break;
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::DeleteElement(){
    if(head == nullptr){ 
        cout<<"List is Empty!"<<endl;
        return;
    }
    Node* temp = head;
    head = (head)->next;
    cout<<temp->data<<" is deleted"<<endl;
}

void LinkedList::display(){ 
   cout << "\n\n";
   // as linked list will end when Node is Null
   Node* node = head;
   while(node!=NULL){ 
      cout << node->data << " ";
      node = node->next;
   }
   cout << "\n" << endl;
} 

int main(){

    bool flag = 0;
    LinkedList list;

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
                list.InsertNode(Element);
                break;
            case 2:
                list.InsertNode_End(Element);
                break;
            case 3:
                list.InsertNode_Pos(Element,Position);
                break;
            case 4:
                list.DeleteElement();
                break;
            case 5:
                list.display();
                break;
            default:
                cout<<"Entered Wrong Number, Please try again!!!"<<endl;
        }

        
        cout<<"To continue enter 1 else 0:";
        cin>>flag;

        

    }while(flag);
    return 0;

}


