// Queue using global variables.


#include<iostream>
#define SIZE 5   
using namespace std;

int queue[SIZE],front = -1,rear = -1;

void enqueue(int val){
    if(rear == SIZE-1){
        cout<<"Queue is Full...!"<<endl;
        return;
    }

    if(front == -1) front = 0;

    queue[++rear] = val;
    cout<<val<<" is inserted."<<endl;
}

void dequeue(){
    if(rear == -1){
        cout<<"Queue is Empty..!"<<endl;
        return;
    }

    cout<<queue[front++]<<" is deleted"<<endl;

    //resetting the queue when last item is Dequeued
    if(front > rear) {
        rear = front = -1;
    }
}

void display(){
    
    if(rear == -1){
        cout<<"Queue is Empty..!"<<endl;
        return;
    }
    cout<<"The elements are: ";
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();
    dequeue();
    dequeue();

    display();

    return 0;
}