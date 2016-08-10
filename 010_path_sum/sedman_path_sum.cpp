#include <cassert>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
  private:
    int sum;
    bool recursive(TreeNode *node, const int total)
    {
      if(node->left == nullptr && node->right == nullptr)
        return (total + node->val == sum) ? true : false;

      if(node->left && recursive(node->left, total + node->val) == true)
        return true;
      if(node->right)
        return recursive(node->right, total + node->val);
      return false;
    }

  public:
    bool hasPathSum(TreeNode *root, int sum_)
    {
      if(root == nullptr)
        return false;
      sum = sum_;
      return recursive(root, 0);
    }
};

int main(void)
{
  Solution s;
  assert(s.hasPathSum(nullptr, 1) == false);
  assert(s.hasPathSum(nullptr, 0) == false);
  assert(s.hasPathSum(new TreeNode(10), 10) == true);
  
  TreeNode *node = new TreeNode(1);
  node->left = new TreeNode(2);
  node->right = new TreeNode(3);
  assert(s.hasPathSum(node, 1) == false);
  assert(s.hasPathSum(node, 3) == true);
  assert(s.hasPathSum(node, 4) == true);
  std::cout<<"passed\n";    
}
