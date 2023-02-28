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


    return 0;
}