// Delete in BST. //
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

Node* inordersucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteinBST(Node* root, int key){
    // case 1
    if(key < root->data){
        root->left = deleteinBST(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteinBST(root->right, key);
    }
    // case 2
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inordersucc(root);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    inorderprint(root);
    cout<<endl;
    root = deleteinBST(root, 5);
    inorderprint(root);
    return 0;
}