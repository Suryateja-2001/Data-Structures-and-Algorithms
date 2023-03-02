// Least common Ansestor

#include<bits/stdc++.h>
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

// LCA Naive Approach

bool findPath(vector<int> &path, int fVal, Queue* root){
    if(root == nullptr) return false;

    path.push_back(root->data);
    if(root->data == fVal) return true;

    if(findPath(path, fVal, root->left) || findPath(path, fVal, root->right))
        return true;
    path.pop_back();
    return false;
}

int LeastCommon_Ancestor(vector<int> &pathOne, vector<int> &pathTwo, Queue* root){
    int i=0;
    while(pathOne[i] == pathTwo[i]){
        i++;
    }

    return pathOne[--i];
}

// LCA Optimised Approach
Queue* LeastCommon_Ancestor_OA(Queue* root,int val1,int val2){
    // base case
    if(root == nullptr) return root;

    // if any of the value is present at root return root as it will be the LCA.
    if(root->data == val1 || root->data == val2) return root;
 
    Queue* lLCA = LeastCommon_Ancestor_OA(root->left, val1, val2);
    Queue* rLCA = LeastCommon_Ancestor_OA(root->right, val1, val2); 

    // if the values are present on either side of  returns root
    if(lLCA != nullptr && rLCA != nullptr) return root;

    // if only one value is found 
    return (lLCA != nullptr)?lLCA:rLCA;
}

int LCA(Queue* root,int val1,int val2){
    Queue* node = LeastCommon_Ancestor_OA(root,val1,val2);

    return node->data;
}

int main(){
    vector<int> pathOne, pathTwo;
    
    Queue* root = new Queue(15);

    root->left = new Queue(8);
    root->right = new Queue(23);

    root->left->left = new Queue(4);
    root->left->right = new Queue(10);

    root->right->left = new Queue(19);
    root->right->right = new Queue(25);
    root->right->right->right = new Queue(24);

    if(findPath(pathOne, 25, root) && findPath(pathTwo, 19, root)){
       cout<<"Least Common Ancestor is "<<LeastCommon_Ancestor(pathOne,pathTwo,root)<<endl;
    }else{
        cout<<"Element entered are not available in the tree..!"<<endl;
    }

    cout<<"Least Common Ancestor is "<<LCA(root,25,19)<<endl;
    return 0;
}