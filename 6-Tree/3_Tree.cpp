
#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
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

// Sprial Level Order
/*Method -1 using queue & stack
Time Complexity = O(N)

void sprialOrder(struct Node* root){

    stack<struct Node*>st;
    queue<struct Node*>qt;
    qt.push(root);
    bool rightToLeft = false;

    while(!qt.empty()){
        int n = qt.size();

        for(int i=0;i<n;i++){

            struct Node* node = qt.front();
            qt.pop();
            if(rightToLeft){
                st.push(node);
            }else{
                cout<<node->data<<" ";
            }

            if(node->left != nullptr)
                qt.push(node->left);
            if(node->right != nullptr)
                qt.push(node->right);
        }

        if(rightToLeft){
            for(int i=0;i<n;i++){
                cout<<st.top()->data<<" ";
                st.pop();
            }
        }
        
        rightToLeft = !rightToLeft;
        
    }
}
*/

// Method - 2
void sprialOrder(struct Node* root){
    stack<struct Node*> st1, st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()){
        int n = st1.size();
        for(int i=0;i<n;i++){
            struct Node* node = st1.top();
            st1.pop();
            cout<<node->data<<" ";

            if(node->left != nullptr)
                st2.push(node->left);
            if(node->right != nullptr)
                st2.push(node->right); 
        }

        n = st2.size();
        for(int i=0;i<n;i++){
            struct Node* node = st2.top();
            cout<<node->data<<" ";
            st2.pop();

            if(node->right != nullptr)
                st1.push(node->right);

            if(node->left != nullptr)
                st1.push(node->left);
        }

    }
}

// Max Diameter of Binary tree Naive Approach
int maxheight(struct Node* root){
    if(root == nullptr) return 0;

    return 1 + max(maxheight(root->left),maxheight(root->right));
}

int diameterBtree(struct Node* root){
    if(root == nullptr) return 0;

    int curr_dia,l_dia,r_dia;

    curr_dia = maxheight(root->left)+ maxheight(root->right);
    l_dia = diameterBtree(root->left);
    r_dia = diameterBtree(root->right);


    return(max(curr_dia,max(l_dia,r_dia)));
}



int main(){
    struct Node* root = new Node(15);

    root->left = new Node(8);
    root->right = new Node(23);

    root->left->left = new Node(4);
    root->left->right = new Node(10);

    root->right->left = new Node(19);
    root->right->right = new Node(25);
    root->right->right->right = new Node(24);

    cout<<"\nSpiral Order of Binary Tree is ";
    sprialOrder(root);

    cout<<"\nMax diameter is "<<diameterBtree(root);

    return 0;
}