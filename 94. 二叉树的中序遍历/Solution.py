# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # 不同于先序遍历的存储结果的顺序
        stack = []
        ans = []
        if root:
            cur = root
        else:
            return ans
        
        while stack or cur: # 可能右子树存在栈为空
            if cur:
                stack.append(cur) # 一直存储左节点
                cur = cur.left    
            else:
                cur = stack.pop() # 左节点到尽头了开始存储答案，并且尝试访问右子树
                ans.append(cur.val)
                cur = cur.right
        return ans