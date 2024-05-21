class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 其实可以细化到计算每一天的利润，然后把所有利润为正的值加起来即是最大利润
        ans = 0
        for i in range(1, len(prices)):
            if prices[i] - prices[i-1] > 0:
                ans += prices[i] - prices[i-1]
        return ans
        