class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i, v in enumerate(nums):
            nums[i] = v * v
        nums.sort()
        return nums