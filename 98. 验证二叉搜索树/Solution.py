# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root, tlist):
        if not root:
            return
        self.traversal(root.left, tlist)
        tlist.append(root.val)
        self.traversal(root.right, tlist)
        return

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # 利用二叉搜索树的中序遍历是递增序列的特性即可
        tlist = []
        self.traversal(root, tlist)
        for i in range(len(tlist) - 1):
            if tlist[i] >= tlist[i+1]:
                return False
        return True