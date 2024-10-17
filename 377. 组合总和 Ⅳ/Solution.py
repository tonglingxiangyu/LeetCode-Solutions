class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dp = [0] * (target+1)
        dp[0] = 1
        for j in range(0, target+1): # 先遍历背包容量后遍历物品表示排列，反之表示组合
            for i in range(n):
                if j - nums[i] >= 0:
                    dp[j] += dp[j - nums[i]]
        return dp[-1]