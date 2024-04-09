# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 本题最好自底向上查找，而后序遍历是自底向上的。
        # 当找到p或者q的时候返回节点。如果左右节点都不为空说明当前节点就是最近公共祖先。如果一边为空一边不为空则返回不为空的那个节点。两边为空返回null.
        # 最后遍历完所有节点之后根节点依然按照上面的逻辑返回节点
        if not root:
            return None
        if q == root or p == root:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        elif not left and right:
            return right
        elif left and not right:
            return left
        else:
            return None