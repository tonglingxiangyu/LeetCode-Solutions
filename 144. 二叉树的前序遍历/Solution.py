# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 递归版本
# class Solution:
#     def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         if not root:
#             return []
#         left = self.preorderTraversal(root.left)
#         right = self.preorderTraversal(root.right)
#         return [root.val] + left + right

# 迭代版本
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = []
        ans = []
        if root:
            stack.append(root)
        else:
            return []
        while stack:
            cur = stack.pop()
            ans.append(cur.val)
            # 模拟递归的出入栈，所以要右节点先入栈左节点后入栈才能保证先序遍历
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
        return ans