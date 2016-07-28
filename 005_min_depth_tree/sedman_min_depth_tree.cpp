#include <cassert>
#include <iostream>
#include <map>
#include <queue>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int minDepth(TreeNode* root) {
      if(root == nullptr)
      {
        return 0;
      }
      
      std::queue<TreeNode*> queue;
      queue.push(root);
      std::map<TreeNode*, int> dist;
      dist.insert({root, 1});
      while(queue.empty() == false)
      {
        TreeNode *node = queue.front();
        queue.pop();
        
        if(node->left == nullptr && node->right == nullptr)
        {
          return dist[node]; 
        }
        if(node->left != nullptr)
        {
          queue.push(node->left);
          dist.insert({node->left, dist[node] + 1});
        }
        if(node->right != nullptr)
        {
          queue.push(node->right);
          dist.insert({node->right, dist[node] + 1});
        }
      }
      return 0;
    }
};

int main(void)
{
  //test
  TreeNode *node = new TreeNode(5);
  node->left = new TreeNode(10);
  node->right = new TreeNode(12);
  
  node->left->left = new TreeNode(15);
  node->left->right = new TreeNode(25);

  Solution s;
  assert(s.minDepth(node) == 2);
  assert(s.minDepth(nullptr) == 0);
  assert(s.minDepth(node->left->left) == 1);
}
