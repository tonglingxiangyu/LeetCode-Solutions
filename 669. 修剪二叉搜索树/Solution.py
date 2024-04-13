# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val < low:
            node = self.trimBST(root.right, low, high) # 向右寻找满足条件的节点，包括了头节点的情况
            return node
        if root.val > high:
            node = self.trimBST(root.left, low, high) # 向左寻找满足条件的节点
            return node
        
        root.left = self.trimBST(root.left, low, high) # 返回满足条件的左右节点
        root.right = self.trimBST(root.right, low, high)
        return root