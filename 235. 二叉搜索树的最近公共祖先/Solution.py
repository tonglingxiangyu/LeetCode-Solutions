# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 根据二叉搜索树的性质，满足 p < val < q 的节点就是最近公共祖先
        if not root:
            return None
        if root.val > p.val and root.val > q.val:
            cur = self.lowestCommonAncestor(root.left, p, q)
            if cur:
                return cur
        elif root.val < p.val and root.val < q.val:
            cur = self.lowestCommonAncestor(root.right, p, q)
            if cur:
                return cur
        return root