// Circular Linked List
// All functions are Optimized approach
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Circular_LinkedList{
    private:
    Node* head;
        
    public:
        Circular_LinkedList();
        int counter();
        void InsertNode(int val);
        void InsertNode_End(int val);
        void Delete();
        void Delete_Pos(int pos);
        void display();
};

Circular_LinkedList::Circular_LinkedList(){
    head = nullptr;
}



int main(){

     bool flag = 0;
    Circular_LinkedList list;

    do{
        cout<<"\n1 for Insert || 2  for Insert at End || 3 for Delete at Position || 4 To Delete first element || 5 for Display"<<endl;
        cout<<"Enter the number to perform Operation:";
        int op;
        cin>>op;
        
        int Element,Position;
        if(op != 4 && op != 6 && op != 3){
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
                list.Delete_Pos(Position);
                break;
            case 4:
                list.Delete();
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

int Circular_LinkedList::counter(){

    if(head == nullptr) return 0;

    int count = 1;
    Node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    return count;
}

void Circular_LinkedList::InsertNode(int val){
    // if list is empty
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    // inserting node after first node
    newNode->next = temp->next;
    temp->next = newNode;

    //swapping first node data and inserted node data, So that new data is always inserted at first
    int temp_val = newNode->data;
    newNode->data = temp->data;
    temp->data = temp_val;
    
}

void Circular_LinkedList::InsertNode_End(int val){
    // if list is empty
    if(head == nullptr){ 
        InsertNode(val);
        return;
    }

    // if is not empty
    Node* newNode = new Node(val);
    Node* temp = head;

    // inserting node after first node
    newNode->next = temp->next;
    temp->next = newNode;

    //swapping first node data and inserted node data, So that new data is always inserted at first
    int temp_val = newNode->data;
    newNode->data = temp->data;
    temp->data = temp_val;

    // now the head is shifted to original data node, So the inserted node becomes last node
    head = head->next;
}

void Circular_LinkedList::Delete(){
    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }

    // if one element is present
    Node* temp = head;
    if(head->next == head){
        head = nullptr;
        delete(temp);
        return;
    }

    // if more than one element is present
    // swap first element and second element
    int temp_val = head->data;
    head->data = head->next->data;
    head->next->data = temp_val;

    // now deleting second Node
    temp = temp->next;
    head->next = temp->next;
    delete(temp);
}

void Circular_LinkedList::Delete_Pos(int pos){

    // if list is empty
    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }

    int count = counter();
    if(pos>count){
        cout<<"Enter value is greater than list size"<<endl;
        return;
    }

    //if only one element is present
    if(count == pos && pos == 1){
        Delete();
        return;
    }

    //if more than one element is present (or) deleting last element

    pos=pos-2; // to stop before deleting position
    Node* temp = head;
    while(pos--){
        temp = temp->next;
    }
    Node* right = temp->next;
    temp->next = right->next;
    cout<<right->data<<" is deleted"<<endl;
    delete(right);
}

void Circular_LinkedList::display(){ 

    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }
   cout << "\n\n";
   // as linked list will end when Node->next is head
   Node* node = head;
   while(node->next != head){ 
      cout << node->data << " ";
      node = node->next;
   }
   cout << "\n" << endl;
} 
