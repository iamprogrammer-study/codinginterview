/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
function hasPathSum(root, sum) {
  
  // 최상위 노드에 대한 가드 조건
  if (!root) {
    return false
  }
  
  const {val, left, right} = root
  
  // 단말 노드인가?
  const isLeaf = !left && !right
  
  // sum 값에서 현재 노드의 val 값을 뺀 나머지
  const remainder = sum - val
  
  // 단말 노드일 경우에 나머지가 떨어지는지?
  if (isLeaf) {
    return 0 === remainder
  
  // 자식 노드에 대해서 재귀 호출
  } else {
    return hasPathSum(left, remainder) || hasPathSum(right, remainder)
  }
}
