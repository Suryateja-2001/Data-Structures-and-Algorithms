/*
Problem statement: Find the sum of elements of all level of binary tree?

Input : root = [10,15,20,25,30,35,40,45]
Output : 220

Explanation :   Sum of all nodes is 220
*/
#include<iostream>
#include<queue>
using namespace std;

class Queue{
    public:
    int data;
    Queue *left, *right;

    Queue(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int sumOfNodes(Queue* root){
    queue<Queue*>qt;
    qt.push(root);
    int sum=0;

    while(!qt.empty()){
        Queue* node = qt.front();
        qt.pop();
        sum += node->data;

        if(node->left != nullptr)
            qt.push(node->left);

        if(node->right != nullptr)
            qt.push(node->right);
    }

    return sum;
}



int main(){

    Queue* root = new Queue(1);

    root->left = new Queue(2);
    root->right = new Queue(3);

    root->left->left = new Queue(4);
    root->left->right = new Queue(5);

    cout<<"sum of elements at all levels: "<<sumOfNodes(root);

    return 0;
}