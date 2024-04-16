class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。
        ans = float('-inf')
        n = len(nums)
        if n == 1:
            return nums[0]

        Sum = 0
        for i in range(n):
            Sum += nums[i]
            ans = max(ans, Sum)
            if Sum < 0:
                Sum = 0
        return ans