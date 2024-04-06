# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 把先序遍历的结果逆序就行
        stack = []
        ans = []
        if root:
            stack.append(root)
        else:
            return ans
        while stack:
            cur = stack.pop()
            ans.append(cur.val)
            if cur.left:
                stack.append(cur.left)
            if cur.right:
                stack.append(cur.right)
        return ans[::-1]