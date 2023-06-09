// Approach - 2 DFS //
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr)
      return nullptr;
    if (const auto it = map.find(node); it != cend(map))
      return it->second;

    Node* newNode = new Node(node->val);
    map[node] = newNode;

    for (Node* neighbor : node->neighbors)
      newNode->neighbors.push_back(cloneGraph(neighbor));

    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
