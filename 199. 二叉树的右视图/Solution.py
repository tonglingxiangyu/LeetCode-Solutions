# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # 类似层序遍历，保留每层最后一个元素即可
        queue = collections.deque()
        ans = []
        if root:
            queue.append(root)
        else:
            return ans
        while queue:
            n = len(queue)
            for i in range(n):
                cur = queue.popleft()
                if i == n-1:
                    ans.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
        return ans