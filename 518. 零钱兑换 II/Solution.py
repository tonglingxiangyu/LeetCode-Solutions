class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [0] * (amount + 1)
        dp[0] = 1 # 如果j和coins[i]刚好相等则等于1，其余情况下无法刚好装满为0
        for i in range(n):
            for j in range(coins[i], amount+1):
                dp[j] += dp[j - coins[i]]
        return dp[-1]