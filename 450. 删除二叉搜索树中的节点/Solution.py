# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 有以下五种情况：
    # 第一种情况：没找到删除的节点，遍历到空节点直接返回了
    # 找到删除的节点
    #     第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
    #     第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
    #     第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
    #     第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，
    #     返回删除节点右孩子为新的根节点。
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val == key:
            if not root.right and not root.left:
                return None
            elif not root.left:
                return root.right
            elif not root.right:
                return root.left
            else:
                cur = root.right
                while cur.left:
                    cur = cur.left
                cur.left = root.left
                return root.right
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        return root