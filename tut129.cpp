// Possible BSTs in a given number of nodes. //
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

vector<Node*> cosntructtrees(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start;i<=end;i++){
        vector<Node*> leftsubtrees = cosntructtrees(start, i-1);
        vector<Node*> rightsubtrees = cosntructtrees(i+1, end);

        for(int j=0; j<leftsubtrees.size(); j++){
            Node* left = leftsubtrees[j];
            for(int k=0; k<rightsubtrees.size(); k++){
                Node* right = rightsubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorderprint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}

int main(){
    vector<Node*> totaltrees = cosntructtrees(1,3);
    for(int i=0;i<totaltrees.size();i++){
        cout<< (i+1) <<" : ";
        preorderprint(totaltrees[i]);
        cout<<endl;
    }
    return 0;
}