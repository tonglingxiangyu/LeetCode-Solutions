# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 三种遍历方式都可以，只要把中间节点的左右节点交换就可以实现翻转了，层序遍历当然也可以
        # 左右节点交换要在访问中间节点的时候进行，不同的遍历方式决定了不同的代码顺序
        if root == None:
            return root
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
