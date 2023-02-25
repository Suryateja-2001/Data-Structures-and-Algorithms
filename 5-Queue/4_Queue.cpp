// circular Queue using class, member functions and new

#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    private:
    int front,rear,currSize;
    unsigned int maxSize;
    int* arr;

    public:
    CircularQueue(int val){
        front = currSize = 0;
        rear = val-1;
        maxSize = val;
        arr = new int [maxSize];
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    void dequeue();
    void display();

};

bool CircularQueue::isEmpty(){

    if(currSize == 0){
        cout<<"Queue is Empty..!"<<endl;
        return true;
    }

    return false;
}

bool CircularQueue::isFull(){

    if(currSize == maxSize){
        cout<<"Queue is full..!"<<endl;
        return true;
    }

    return false;
}

void CircularQueue::enqueue(int val){
    if(isFull()) return;

    rear = (rear+1) % maxSize;
    arr[rear] = val;
    currSize++;
    
    cout<<val<<" is added to queue at "<<rear<<" position"<<endl;
}

void CircularQueue::dequeue(){
    if(isEmpty()) return;

    front = (front+1) % maxSize;
    currSize--;

    cout<<arr[front-1]<<" is deleted"<<endl;
}

void CircularQueue::display(){
    if(isEmpty()) return;

    cout<<"Elements are ";
    for(int i=0;i<currSize;i++){
        int j = (i+front) % maxSize;

        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

int main(){

    CircularQueue obj1 = CircularQueue(5);

    obj1.enqueue(10);
    obj1.enqueue(20);
    obj1.enqueue(30);
    obj1.enqueue(40);
    obj1.enqueue(50);
    obj1.enqueue(60);
    
    obj1.dequeue();
    obj1.dequeue();
    obj1.dequeue();

    obj1.display();


    obj1.enqueue(70);
    obj1.enqueue(80);
    obj1.enqueue(90);

    obj1.display();

    return 0;
}