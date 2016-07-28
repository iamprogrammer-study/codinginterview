class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

def minDepth(root):
	if root == None:
		return 0
	elif root.left == None or root.right == None:
		return 1
	else:
		return min([minDepth(root.left), minDepth(root.right)]) + 1

root = TreeNode(1)
root.left = TreeNode(1)
root.left.left = TreeNode(1)
root.left.right = TreeNode(1)
root.left.left.left = TreeNode(1)
root.left.left.right = TreeNode(1)

root.right = TreeNode(1)
root.right.left = TreeNode(1)
root.right.right = TreeNode(1)

print minDepth(root)


