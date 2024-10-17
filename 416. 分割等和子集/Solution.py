class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums) // 2
        if target * 2 != sum(nums):
            return False
        n = len(nums)
        dp = [0] * (target + 1)
        for i in range(n):
            for j in range(target, nums[i]-1, -1):
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
        if dp[target] == target:
            return True
        return False