/*
Find the kth node from the last of linked list?
Input : 2, 3, 5, 7, 9, 10
n= 3
Output : 7
Explanation: 3rd node from last is 7  
*/

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

int counter(Node* *head){
    if(*head == nullptr){
        cout<<"List is Empty!"<<endl;
        return 0;
    }

    int count = 1;
    Node* temp = *head;
    while(temp->next != *head){
        count++;
        temp = temp->next;
    }
    return count;
}

void NodeValue(Node* *head,int pos){

    if(*head == nullptr){
        cout<<"List is Empty!"<<endl;
        return;
    }

    int count = counter(head);
    if(count < pos){
        cout<<"Entered value is greater than List size"<<endl;
        return;
    }

    pos = count-pos;
    if(pos == 1){
        cout<<(*head)->data;
    }

    Node* temp = *head;
    while(pos--){
        temp = temp->next;
    }
    cout<<temp->data;
}

int main(){
    Node* head = nullptr;

    head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = head;

    NodeValue(&head,3);


    return 0;
}