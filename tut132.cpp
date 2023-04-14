// Longest BST in a Binary Tree. //
#include<iostream>
#include<climits>
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

struct Info {
    int size;
    int max;
    int min;
    int ans;
    bool isBST;

};

Info largestBST(Node* root){
    if(root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    Info left = largestBST(root->left);
    Info right = largestBST(root->right);

    Info curr;
    curr.size = (1 + left.size + right.size);

    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data){
        curr.min = min(left.min, min(right.min, root->data));
        curr.max = max(right.max, max(left.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;

}

int main(){
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout<<"Largest BST in the tree is : "<<largestBST(root).ans<<endl;\

    return 0;
}