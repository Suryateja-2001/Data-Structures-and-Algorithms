// double linked list using class, new and class member functions

#include<iostream>
using namespace std;

class Node{
    public:
    int data;

    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Double_LinkedList{
    private:
    Node* head;

    public:
    Double_LinkedList(){
        head = nullptr;
    }

    void InsertNode(int val);
    void InsertNode_End(int val);
    void InsertNode_Pos(int val,int pos);
    void Delete();
    void DeleteElement(int val);
    void display();
    int counter();
};


int main(){
    bool flag = 0;
    Double_LinkedList list;

    do{
        cout<<"\n1 for Insert || 2  for Insert at End || 3 for Insert at Position || 4 To Delete first element || 5 for Delete the Element || 6 for Display"<<endl;
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
                list.InsertNode(Element);
                break;
            case 2:
                list.InsertNode_End(Element);
                break;
            case 3:
                list.InsertNode_Pos(Element,Position);
                break;
            case 4:
                list.Delete();
                break;
            case 5:
                list.DeleteElement(Element);
                break;
            case 6:
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
int Double_LinkedList::counter(){
    int count = 1;
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

void Double_LinkedList::InsertNode(int val){
    Node* newNode = new Node(val);

    if(head == nullptr){
        head = newNode;
        return;
    }

    newNode->next=head;
    head->prev = newNode;
    head = newNode;
}

void Double_LinkedList::InsertNode_End(int val){

    if(head == nullptr){
        InsertNode(val);
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Double_LinkedList::InsertNode_Pos(int val,int pos){
    
    // if list is empty new node is created by ignoring position of insertion
    if(head == nullptr){
        InsertNode(val);
        return;
    }

    int count = counter();
    if(pos > count){
        cout<<"Position is greater than the size of linked list"<<endl;
        return;
    }

    // if pos is 1(and there maybe only one element)
    Node* temp = head;
    if(pos == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // if pos in between 1 and count
    if(pos > 1 && pos <= count){
        pos--;
        while(pos--){
            temp = temp->next;
        }
        temp = temp->prev;
        Node* newNode = new Node(val);
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

  
}

void Double_LinkedList::Delete(){
    
    if(head == nullptr) {
        cout<<"Empty List"<<endl;
        return;
    }

    Node* temp = head;
    
    // if more than 1 element is present
    if(temp->next != nullptr){
        head = head->next;
        head->prev = nullptr;
        cout<<temp->data<<" is deleted"<<endl;
        delete(temp);
        return;
    }

    // if only one element is present
    head = head->next;
    cout<<temp->data<<" is deleted"<<endl;
    delete(temp);
    
}

void Double_LinkedList::DeleteElement(int val){
    
    if(head == nullptr) {
        cout<<"Empty List"<<endl;
        return;
    }

    Node* temp = head;
    // if value is present at first
    if(head->data == val){
        head = temp ->next;
        cout<<temp->data<<" is deleted"<<endl;
        delete(temp);
        return;
    }
    
    while(temp->next != nullptr && temp->data != val){
        temp = temp->next;
    }

    // if value is at last  
    if(temp->data == val && temp->next==nullptr){
        Node *left = temp->prev;
        left->next = nullptr;
        cout<<temp->data<<" is deleted"<<endl;
        delete(temp);
        return;
    }

    // if value is at middle
    if(temp->data == val){

        Node* left = temp->prev;
        Node* right = temp->next;

        left->next = right;
        right->prev = left;
        cout<<temp->data<<" is deleted"<<endl;
        delete(temp);
        return;
    }

    cout<<val<<" is not Found"<<endl;
}

void Double_LinkedList::display(){ 

    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }
   cout << "\n\n";
   // as linked list will end when Node is Null
   Node* node = head;
   while(node != nullptr){ 
      cout << node->data << " ";
      node = node->next;
   }
   cout << "\n" << endl;
} 

