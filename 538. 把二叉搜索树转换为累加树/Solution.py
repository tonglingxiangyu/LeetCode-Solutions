# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root):
        if not root:
            return
        self.traversal(root.right)
        root.val += self.pre
        self.pre = root.val
        self.traversal(root.left)

    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 可以看出是从右向左计算累加的，也就是反中序遍历
        self.pre = 0 # 记录前一个节点的值
        self.traversal(root)
        return root