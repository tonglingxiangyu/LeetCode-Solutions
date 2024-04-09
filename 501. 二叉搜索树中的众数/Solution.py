# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, root, tlist):
        if not root:
            return
        self.traversal(root.left, tlist)
        tlist.append(root.val)
        self.traversal(root.right, tlist)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        if not root.left and not root.right:
            return [root.val]
        tlist = []
        ans = []
        self.traversal(root, tlist)
        Maxcount = 1
        count = 1
        pre = tlist[0]
        for i in range(1, len(tlist)):
            if pre == tlist[i]:
                count += 1
            if pre != tlist[i] or i == len(tlist)-1:
                if count > Maxcount:
                    ans.clear()
                    ans.append(pre)
                    Maxcount = count
                elif count == Maxcount:
                    ans.append(pre)
                pre = tlist[i]
                count = 1
            if i == len(tlist)-1:
                if count > Maxcount:
                    ans.clear()
                    ans.append(pre)
                    Maxcount = count
                elif count == Maxcount:
                    ans.append(pre)
        return ans