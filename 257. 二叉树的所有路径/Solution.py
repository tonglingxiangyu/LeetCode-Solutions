# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, node, s, ans):
        if not node:
            return
        if not node.left and not node.right:
            s += str(node.val)
            ans.append(s)
            return
        s += str(node.val) + "->"
        self.traversal(node.left, s, ans)
        self.traversal(node.right, s, ans)
        return

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        if not root:
            return ans
        s = ""
        self.traversal(root, s, ans)
        return ans