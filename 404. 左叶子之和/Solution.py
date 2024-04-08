# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 在调用其他函数时基本数据类型是不可变的，如整数。所以可以用列表来存储答案或者使用一个类变量来累加结果
    def traversal(self, root):
        if not root:
            return 0
        left_val = self.traversal(root.left)
        mid_val = 0
        if root.left and not root.left.left and not root.left.right:
            mid_val = root.left.val
        right_val = self.traversal(root.right)
        return left_val + mid_val + right_val

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.traversal(root)