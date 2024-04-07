# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # 队列先进先出，符合一层一层遍历的逻辑，而用栈先进后出适合模拟深度优先遍历也就是递归的逻辑。
        # 而这种层序遍历方式就是图论中的广度优先遍历，只不过我们应用在二叉树上。
        queue = collections.deque()
        ans = []
        if root:
            queue.append(root)
        else:
            return ans
        while queue:
            lever = []
            size = len(queue)
            for _ in range(size):
                cur = queue.popleft()
                lever.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
            ans.append(lever)
        return ans