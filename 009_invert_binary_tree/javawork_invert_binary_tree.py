# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        q = deque([root])
        root2 = root
        q2 = deque([root2])
        while len(q) > 0:
            runner = q.popleft()
            if runner is None:
                continue
            
            temp = runner.left
            runner.left = runner.right
            runner.right = temp
            
            runner2 = q2.popleft()
            runner2.left = runner.left
            runner2.right = runner.right
            
            if runner.left is not None:
                q.append(runner.left)
                q2.append(runner2.left)
            if runner.right is not None:
                q.append(runner.right)
                q2.append(runner2.right)
                
        return root2