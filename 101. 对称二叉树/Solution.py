# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # 这里的迭代法可不是前中后序的迭代写法，因为本题的本质是判断两个树是否是相互翻转的，其实已经不是所谓二叉树遍历的前中后序的关系了。
        # 通过队列来判断根节点的左子树和右子树的内侧和外侧是否相等，成对的来入队和出队
        queue = collections.deque()
        if root:
            queue.append(root.left)
            queue.append(root.right)
        else:
            return True
        while queue:
            left = queue.popleft()
            right = queue.popleft()
            if not left and not right: # 左右节点为空说明相等
                continue
            if not left or not right or left.val != right.val: # 两边都不为空的情况下，两边不相等的情况
                return False
            queue.append(left.left) # 先存左边的左节点和右边的右节点，然后再存左边的右节点和右边的左节点
            queue.append(right.right)
            queue.append(left.right)
            queue.append(right.left)
        return True