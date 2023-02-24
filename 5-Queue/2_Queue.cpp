// Queue using struct & malloc

#include<iostream>
using namespace std;

// creating queue structure
struct Queue{
    int front, rear;
    unsigned int size;

    // creating a pointer which points to the memory of array which is created using create queue function
    int* arr;
};

struct Queue* createQueue(unsigned int size){
    // allocating memory of struct Queue size.
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    queue->size = size;
    queue->front = -1;
    queue->rear = -1;

    // allocating memory of queue->size size of memory
    queue->arr = (int*) malloc(size * sizeof(int));

    return queue;
}

// If queue is full returns true otherwise false.
bool isFull(struct Queue* queue){
    if(queue->rear == queue->size-1) {
        cout<<"Queue is full"<<endl;
        return 1;
    }
    return 0;
}

// If queue is empty returns true otherwise false.
bool isEmpty(struct Queue* queue){
    if(queue->front == -1) {
        cout<<"Queue is Empty"<<endl;
        return 1;
    }
    return 0;
}



void enqueue(struct Queue* queue, int val){
    if(isFull(queue)) return;

    if(queue->front == -1) queue->front = 0;
    queue->arr[++queue->rear] = val;
    
    cout<<queue->arr[queue->rear]<<" is added to queue"<<endl;
};

void dequeue(struct Queue* queue){
    if(isEmpty(queue)) return;

    cout<<queue->arr[queue->front++]<<" is deleted"<<endl;

    // if last element is deleted
    if(queue->front > queue->rear){
        queue->front = queue->rear = -1;
    }
}

void display(struct Queue* queue){
    if(isEmpty(queue)) return;

    cout<<"Elements are ";
    for(int i=queue->front;i <= queue->rear;i++){
        cout<<queue->arr[i]<<" ";
    }
    cout<<endl;
}



int main(){
    // creating a queue of size 5
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    display(queue);

    return 0;
}