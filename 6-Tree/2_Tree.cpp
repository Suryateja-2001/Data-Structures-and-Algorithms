// basic Binary tree Using struct,struct-constructor and new

#include<iostream>
#include<cstdlib>
#include<queue>
#include<limits>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


// first left sub-tree then right sub-tree and at last parent node.(LRN)
void postOrder(struct Node* node){

    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<" ";
    }

}


// first left sub-tree then root node and at last right sub-tree. (LNR)
void inOrder(struct Node* node){

    if(node != nullptr){
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
}


// first root node then left sub-tree and at last right sub-tree. (NLR)
void preOrder(struct Node* node){

    if(node != nullptr){
        cout<<node->data<<" ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// level order traversal.
void levelOrder(struct Node* node){
    if (node == nullptr) return;

    queue<Node*>qt;
    qt.push(node);

    while(!qt.empty()){
        Node* queue = qt.front();
        qt.pop();
        cout<<queue->data<<" ";

        if(queue->left != nullptr)
            qt.push(queue->left);
        
        if(queue->right)
            qt.push(queue->right);
    }
    
}

// max-depth or max-height of a tree.
int maxHeight(struct Node* node){
    if(node == nullptr) return 0;

    int lheight = maxHeight(node->left);
    int rheight = maxHeight(node->right);

    if(lheight > rheight){
        return (lheight+1);
    }else{
        return (rheight+1);
    }
}

// printing nodes at K-distance

void node_KDistance(struct Node* node, int distance){

    if(distance < 0) return;

    if(node == nullptr){
        cout<<"Distance is greater than height..!"<<endl;
        return;
    }

    node_KDistance(node->left,distance-1);
    node_KDistance(node->right,distance-1);

    if(distance == 0){
        cout<<node->data<<" ";
        return;
    }

}

// size of Binary Tree.
int BTSize(struct Node* root){

    if(root == nullptr) return 0;

    int size = BTSize(root->left) + BTSize(root->right) + 1;

    return size;
}

// max Element in a Binary Tree
int maxElement(struct Node* root){
    if(root == nullptr) return INT32_MIN;
    int max_val = max((root->data), maxElement(root->left));
    max_val = max(max_val, maxElement(root->right));

    return max_val;
}


// Left View of Tree
/* 
Method -1

int maxVisited_level = 0;
void leftViewTree(struct Node* root, int currLevel = 1){
    if(root == nullptr) return;

    if(maxVisited_level < currLevel){
        cout<<root->data<<" ";
        maxVisited_level = currLevel;
    }

    leftViewTree(root->left,currLevel+1);
    leftViewTree(root->right,currLevel+1);
}
*/

/* Method-2 */
void leftViewTree(struct Node* root){
    if(root == nullptr) return;

    queue<struct Node*>qt;
    qt.push(root);

    while(!qt.empty()){
        int n = qt.size();

        for(int i=0;i<n;i++){
            struct Node* node = qt.front();
            qt.pop();

            if(i == 0)
                cout<<node->data<<" ";
            
            if(node->left != nullptr)
                qt.push(node->left);
            
            if(node->right != nullptr)
                qt.push(node->right);
        }
    }

}


int main(){
    struct Node* root = new Node(15);

    root->left = new Node(8);
    root->right = new Node(23);

    root->left->left = new Node(4);
    root->left->right = new Node(10);

    root->right->left = new Node(19);
    root->right->right = new Node(25);
    root->right->right->left = new Node(24);

    cout<<"post Order: ";
    postOrder(root);
    
    cout<<"\npre Order: ";
    preOrder(root);

    cout<<"\nIn Order: ";
    inOrder(root);

    cout<<"\n"<<maxHeight(root)<<endl;

    cout<<"\nelements at distance 2 are ";
    node_KDistance(root,2);

    cout<<"\nLevel Order traversal: ";
    levelOrder(root);

    cout<<"\nSize of Tree: "<<BTSize(root)<<endl;

    cout<<"Max Element in array:"<<maxElement(root)<<endl;

    cout<<"Left View of the Binary Tree is ";
    leftViewTree(root);

    return 0;
}