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
    Node* hdeleteNode(Node* node,int val);
    Node* inorderSuccessor(Node* node);

    public:
    void insert(int val);
    void Rinsert(int val);
    void inOrder();
    bool search(int val);
    void deleteNode(int val);
    void floor(int val);
    void ceil(int val);
};

int main(){

    BSTree obj;
    obj.insert(20);
    obj.insert(23);
    obj.insert(9);
    obj.insert(29);
    obj.insert(25);
    obj.insert(5);
    obj.Rinsert(17);
    obj.insert(15);

    obj.inOrder();

    bool flag = obj.search(17);
    if(flag){
        cout<<"\nData found...!"<<endl;
    }else{
        cout<<"\nData is not found"<<endl;
    }

    obj.floor(5);
    obj.ceil(17);
    obj.deleteNode(23);
    obj.inOrder();
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
        cout<<root->data<<" is inserted."<<endl;
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
    if(prevNode->data > val){
        prevNode->left = new_node;
        cout<<prevNode->left->data<<" is inserted."<<endl;
    }else{
        prevNode->right = new_node;
        cout<<prevNode->right->data<<" is inserted."<<endl;
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
    return hsearch(root,val);
}

// delete a node.
Node* BSTree::inorderSuccessor(Node* node){
    if(node == nullptr) return node;

    while(node != nullptr && node->left != nullptr){
        node = node->left;
    }

    return node;
}

Node* BSTree::hdeleteNode(Node* node,int val){
    if(node == nullptr) return node;

    //finding the node to delete
    if(node->data > val){
        node->left = hdeleteNode(node->left,val);
        return node;
    }else if(node->data < val){
        node->right = hdeleteNode(node->right,val);
        return node;
    }else{
        // if right is null
        if(node->right == nullptr){

            Node* temp = node->left;
            free(node);
            return temp;
            // if left is null
        }else if(node->left == nullptr){   

            Node* temp = node->right;
            free(node);
            return temp;

        }else{   

            // if both are not null
            Node* successorNode = inorderSuccessor(node->right);
            node->data = successorNode->data;
            node->right = hdeleteNode(node->right,node->data); 
        }
    }
    return node;
}


void BSTree::deleteNode(int val){
    Node* node = root;
    hdeleteNode(node,val);
}

// finding value or floor of the given value.
int max_floor = 0;

void BSTree::floor(int val){
    Node* node = root;

    if(node == nullptr) {
       cout<<"Tree is not present."<<endl;
        return;
    }

    while(node != nullptr){
        if(node->data == val){
            max_floor = val;
            break;
        }

        if(node->data < val){
            max_floor = max(max_floor,node->data);
        }

        if(node->data > val){
            node = node->left;
        }else{
            node = node->right;
        }  
    }

    cout<<max_floor<<" is the floor of the given value in the tree."<<endl;
}

// finding value or ceil of the given value.
int max_ceil = INT32_MAX;
void BSTree::ceil(int val){
    Node* node = root;

    if(node == nullptr) {
       cout<<"Tree is not present."<<endl;
        return;
    }

    while(node != nullptr){
        if(node->data == val){
            max_ceil = val;
            break;
        }

        if(node->data > val){
            max_ceil = min(max_ceil,node->data);
        }

        if(node->data > val){
            node = node->left;
        }else{
            node = node->right;
        }  
    }

    cout<<max_ceil<<" is the ceil of the given value in the tree."<<endl;
}