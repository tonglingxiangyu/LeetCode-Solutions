# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root, val):
        if not root:
            return
        if val > root.val:
            if not root.right:
                root.right = TreeNode(val)
            self.traversal(root.right, val)
        if val < root.val:
            if not root.left:
                root.left = TreeNode(val)
            self.traversal(root.left, val)
        return

    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        # 最简单的方式就是不改变树的结构，碰到空节点插入即可
        if not root:
            return TreeNode(val)
        self.traversal(root, val)
        return root