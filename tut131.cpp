// Are BSTs identical? //
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

bool isidentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isidentical(root1->left, root2->left);
        bool cond3 = isidentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3 == true){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->left = new Node(3);
    if(isidentical(root, root)){
        cout<<"BSTs are identical";
        cout<<endl;
    }
    else{
        cout<<"BSTs are not identical";
        cout<<endl;
    }
    return 0;
}