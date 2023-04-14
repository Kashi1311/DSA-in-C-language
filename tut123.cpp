// Maximum sum path problem. //
#include<iostream>
#include<vector>
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

int maxsumutil(Node* root, int ans){
    if(root == NULL){
        return 0;
    }
    int left = maxsumutil(root->left, ans);
    int right = maxsumutil(root->right, ans);

    int nodemax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));
    ans = max(ans, nodemax);
    int singlepathsum = max(root->data, max(root->data + left, root->data + right));
    return singlepathsum;
}

int maxsum(Node* root){
    int ans = INT8_MIN;
    maxsumutil(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout<<maxsum(root);

    return 0;
}
