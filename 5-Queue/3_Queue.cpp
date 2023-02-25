// Circular Queue using struct and malloc

#include<iostream>
#include<cstdlib>
#include<limits>
using namespace std;

// creating datastructure of circular queue
struct CircularQueue{
    int maxsize;
    unsigned int front,rear,currSize;

    // pointer to store array address
    int* arr;
};

struct CircularQueue* createQueue(int val){
    // allocating memory of size struct CircularQueue
    struct CircularQueue* queue = (struct CircularQueue*) malloc(sizeof(struct CircularQueue));
    
    queue->front = queue->currSize = 0;
    queue->rear = val-1;
    queue->maxsize = val;

    // allocating memory for array of val size
    queue->arr = (int *) malloc(sizeof(val*sizeof(int)));
    return queue;
}

// if Queue if full returns true otherwise false
bool isFull(struct CircularQueue* queue){
    if(queue->currSize == queue->maxsize){
        cout<<"Queue is Full..!"<<endl;
        return true;
    }

    return false;
}

// if Queue is Empty returns true otherwise false
bool isEmpty(struct CircularQueue* queue){
    if(queue->currSize == 0){
        cout<<"Queue is empty..!"<<endl;
        return true;
    }

    return false;
}

void enqueue(struct CircularQueue* queue, int val){
    if(isFull(queue)) return;

    queue->rear = (queue->rear+1) % queue->maxsize;
    queue->arr[queue->rear] = val;
    queue->currSize++;

    cout<<val<<" is added to queue at"<<queue->rear<<" position"<<endl;
}

void dequeue(struct CircularQueue* queue){
    if(isEmpty(queue)) return;

    int i = queue->front;
    queue->front = (queue->front+1) % queue->maxsize;
    queue->currSize--;

    cout<<queue->arr[i]<<" is deleted"<<endl;
}

void display(struct CircularQueue* queue){
    if(isEmpty(queue)) return;

    cout<<"Elements are ";
    for(int i=0;i<queue->currSize;i++){

        int j = (queue->front+i) % queue->maxsize;
        cout<<queue->arr[j]<<" ";
    }
    cout<<endl;
}


int main(){

    struct CircularQueue* queue = createQueue(5);

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    enqueue(queue,50);
    enqueue(queue,60);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    display(queue);


    enqueue(queue,70);
    enqueue(queue,80);
    enqueue(queue,90);

    display(queue);


    return 0;
}