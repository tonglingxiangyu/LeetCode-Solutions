# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 后序遍历的最后一个节点是根节点，然后根据根节点从中序遍历分离出左右子树，然后根据左右子树的长度也可以将后序遍历分成左右子树两部分
    # 之后的操作都是一样的子问题，递归即可
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not postorder:
            return None
        size = inorder.index(postorder[-1])
        left = self.buildTree(inorder[:size], postorder[:size])
        right = self.buildTree(inorder[size+1:], postorder[size:-1])
        return TreeNode(postorder[-1], left, right)