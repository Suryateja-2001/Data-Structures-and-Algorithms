/*
Problem Statement: Print the right view of binary tree? 

Input : root = [20,70,90, 30,40,70] 
Output : 20 90 70

Explanation : Right view of binary tree : 20, 90, 70
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
        left = right = nullptr;
    }  
};

// method 1
/*
void rightView(Queue* root){
    queue<Queue *>qt;
    qt.push(root);

    while(!qt.empty()){
        int n = qt.size();

        for(int i=0;i<n;i++){
            Queue* node = qt.front();
            qt.pop();

            if(i == n-1)
                cout<<node->data<<" ";

            if(node->left != nullptr)
                qt.push(node->left);
            
            if(node->right != nullptr)
                qt.push(node->right);
        }
    }
}
*/

//method 2
int maxVisited = 0;
void rightView(Queue* root, int currLevel = 1){
    if(root == nullptr) return;

    if(maxVisited < currLevel){
        cout<< root->data<<" ";
        maxVisited = currLevel;
    }
    rightView(root->right,currLevel+1);
    rightView(root->left,currLevel+1);
    
}

int main(){

    Queue* root = new Queue(20);

    root->left = new Queue(70);
    root->right = new Queue(90);

    root->left->left = new Queue(30);
    root->left->right = new Queue(40);

    root->right->left = new Queue(70);

    cout<<"Right view of Binary tree is ";
    rightView(root);

    return 0;
}