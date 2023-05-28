#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    dfs(root, {}, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, vector<string>&& path, vector<string>& ans) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr) {
      ans.push_back(join(path) + to_string(root->val));
      return;
    }

    path.push_back(to_string(root->val) + "->");
    dfs(root->left, move(path), ans);
    dfs(root->right, move(path), ans);
    path.pop_back();
  }

  string join(const vector<string>& path) {
    string joined;
    for (const string& s : path)
      joined += s;
    return joined;
  }
};
