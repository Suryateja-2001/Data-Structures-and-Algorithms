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
    bool hsearch(Node* node,int val);
    Node* RHinsert(int val,Node* node);

    public:
    void insert(int val);
    void Rinsert(int val);
    void inOrder();
    bool search(int val);
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
    obj.Rinsert(17);

    obj.inOrder();

    bool flag = obj.search(25);
    if(flag){
        cout<<"\nData found...!"<<endl;
    }else{
        cout<<"\nData is not found"<<endl;
    }

    return 0;
}
// recursion insertion
Node* BSTree::RHinsert(int val,Node* node){
    if(node == nullptr){
        Node* new_node = new Node(val);
        node = new_node;
        cout<<node->data<<" is Inserted."<<endl;
        return node;
    }

    if(node->data > val){
        node->left = RHinsert(val,node->left);
    }else{
        node->right = RHinsert(val,node->right);
    }
    return node;
}
void BSTree::Rinsert(int val ){
    if(root == nullptr){
        Node* new_node = new Node(val);
        root = new_node;
        return;
    }
    if(root->data > val){
        root->left = RHinsert(val,root->left);
    }else{
        root->right = RHinsert(val,root->right);
    }
}

// iterative insertion
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

// search function

bool BSTree::hsearch(Node* node,int val){
    if(node == nullptr) return false;

    if(node->data == val) return true;

    return (val < node->data)?hsearch(node->left,val):hsearch(node->right,val);
}

bool BSTree::search(int val){
    if(root == nullptr) return false;

    if(root->data == val) return true;

    return (val < root->data)?hsearch(root->left,val):hsearch(root->right,val);
}