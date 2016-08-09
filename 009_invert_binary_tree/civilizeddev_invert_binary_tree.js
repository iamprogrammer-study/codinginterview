/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
const invertTree = (root) => {
  
  /*
   * Early exit if node is null
   */
  if (!root) return root
  
  const {left, right} = root
  
  /*
   * Recursively swap the child nodes
   */
  root.left = invertTree(right)
  root.right = invertTree(left)
  
  return root
}
