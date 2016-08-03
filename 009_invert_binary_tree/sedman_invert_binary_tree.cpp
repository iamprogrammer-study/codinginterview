class Solution {
private:
  TreeNode* InOrderTraverse(TreeNode *node)
  {
    if(node == nullptr)
    {
      return nullptr;
    }
     
    TreeNode *tmp_right = InOrderTraverse(node->left);
    node->left = InOrderTraverse(node->right);
    node->right = tmp_right;
    return node;
  }

public:
    TreeNode* invertTree(TreeNode* root) {
      return InOrderTraverse(root);   
    }
};

