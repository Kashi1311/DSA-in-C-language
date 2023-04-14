// Print all Nodes at distance k. //
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
//Case 1
void printsubtrees(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printsubtrees(root->left, k-1);
    printsubtrees(root->right, k-1);
}
//Case 2
int printNodesatK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printsubtrees(root, k);
        return 0;
    }
    int dl = printNodesatK(root->left, target, k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printsubtrees(root->right, k-dl-2);
        }
        return 1+dl;
    }
    int dr = printNodesatK(root->right, target, k);
    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printsubtrees(root->left, k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    printNodesatK(root, root->left, 1);
    return 0;
}