#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BSTree{
    private:
    Node* root = nullptr;
    void Orderin(Node* node);

    public:
    void insert(int val);
    void inOrder();
};

int main(){

    BSTree obj;
    obj.insert(20);
    obj.insert(23);
    obj.insert(9);
    obj.insert(15);
    obj.insert(29);
    obj.insert(25);
    obj.insert(5);

    obj.inOrder();

    return 0;
}

void BSTree::insert(int val){
    Node* new_node = new Node(val);

    if(root == nullptr){
        root = new_node;
        return;
    }

    Node *temp = root,*prevNode;
    while(temp != nullptr){
        prevNode = temp;

        if(temp->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    if(prevNode->left == nullptr){
        prevNode->left = new_node;
        cout<<prevNode->left->data<<" is inserted."<<endl;
    }else{
        prevNode->right = new_node;
        cout<<prevNode->left->data<<" is inserted."<<endl;
    }
}

void BSTree::Orderin(Node* node){
    if(node != nullptr){
        Orderin(node->left);
        cout<<node->data<<" ";
        Orderin(node->right);
    }
}

void BSTree::inOrder(){
    Orderin(root);
}