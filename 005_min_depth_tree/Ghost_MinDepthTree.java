/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Ghost_MinDepthTree {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        //BFS
        java.util.Queue<TreeNode> queue = new java.util.LinkedList<>();
        queue.offer(root);
        int sol = 0;
        while (!queue.isEmpty()) {
            sol++;
            int size = queue.size();
            for (int idx = 0; idx < size; idx++) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null) {
                    return sol;
                }
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        return sol;
    }
}