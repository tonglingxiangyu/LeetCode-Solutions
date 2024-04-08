# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self, left, right, nums):
        if left > right:
            return None
        maxindex = left
        Max = float('-inf')
        for i in range(left, right+1):
            if nums[i] > Max:
                Max = nums[i]
                maxindex = i
        node = TreeNode(nums[maxindex])
        node.left = self.traversal(left, maxindex-1, nums)
        node.right = self.traversal(maxindex+1, right, nums)
        return node

    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        return self.traversal(0, len(nums)-1, nums)