# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root):
        # 如果发现有子树不是平衡二叉树则逐级返回-1
        if not root:
            return 0
        left = self.traversal(root.left)
        right = self.traversal(root.right)
        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1
        else:
            return max(left, right) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.traversal(root) != -1