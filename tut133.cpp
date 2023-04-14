// Restore BST. //
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcpointers(Node* root, Node** first, Node** mid, Node** last, Node** previous){
    if(root == NULL){
        return;
    }

    calcpointers(root->left , first, mid, last, previous);
    if(*previous && root->data < (*previous)->data){
        if(!*first){
            *first = *previous;
            *mid = root;
        }
        else{
            *last = root;
        }
    }

    *previous = root;
    calcpointers(root->right, first, mid, last, previous);
}

void restoreBST(Node* root){
    Node *first, *mid, *last, *previous;
    first = NULL;
    mid = NULL;
    last = NULL;
    previous = NULL;

    calcpointers(root, &first, &mid, &last, &previous);

    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);
    inorder(root);
    cout<<endl;
    restoreBST(root);
    cout<<endl;
    inorder(root);

    return 0;
}