// basic tree Using struct,struct-constructor and new

#include<iostream>
#include<cstdlib>
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

    cout<<"\n elements at distance 2 are ";
    node_KDistance(root,2);

    return 0;
}