// Approach 3 - Morris //
#include<iostream>
using namespace std;

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* pred = nullptr;
    TreeNode* x = nullptr;  // 1st wrong node
    TreeNode* y = nullptr;  // 2nd wrong node

    while (root) {
      if (root->left) {
        TreeNode* morrisPred = findPredecessor(root);
        if (morrisPred->right) {  // Already connected before
          visit(root, pred, x, y);
          morrisPred->right = nullptr;  // Break the connection
          root = root->right;
        } else {
          morrisPred->right = root;  // Connect it!
          root = root->left;
        }
      } else {
        visit(root, pred, x, y);
        root = root->right;
      }
    }

    swap(x, y);
  }

 private:
  TreeNode* findPredecessor(TreeNode* root) {
    TreeNode* pred = root->left;
    while (pred->right && pred->right != root)
      pred = pred->right;
    return pred;
  }

  void visit(TreeNode*& root, TreeNode*& pred, TreeNode*& x, TreeNode*& y) {
    if (pred && root->val < pred->val) {
      y = root;
      if (x == nullptr)
        x = pred;
    }
    pred = root;
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};
