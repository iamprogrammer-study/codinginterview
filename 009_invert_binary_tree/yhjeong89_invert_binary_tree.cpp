/**
* Post-Order로 트리를 탐색하며 각 child의 invert가 끝났다면 root를 invert 하는 방식으로 구현 했습니다.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        
        // Swap left and right child pointer;
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};