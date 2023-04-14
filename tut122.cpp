// LCA 2.//
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftlca = LCA(root->left, n1, n2);
    Node* rightlca = LCA(root->right, n1, n2);

    if(leftlca && rightlca){
        return root;
    }
    if(leftlca!=NULL){
        return leftlca;
    }
    return rightlca;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    Node* lca = LCA(root, 7, 6);
    if(lca == NULL){
        cout<<"LCA doesn't exist"<<endl;
    }
    else{
        cout<<lca->data<<" ";
    }
    return 0;
}
