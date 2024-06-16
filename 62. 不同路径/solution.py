class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径。
        # 想要求dp[i][j]，只能有两个方向来推导出来，即dp[i - 1][j] 和 dp[i][j - 1]。
        # 此时在回顾一下 dp[i - 1][j] 表示啥，是从(0, 0)的位置到(i - 1, j)有几条路径，dp[i][j - 1]同理。
        # 那么很自然，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，因为dp[i][j]只有这两个方向过来。
        dp = [[0] * n for i in range(m)]
        # 初始化第一列和第一行
        for i in range(n):
            dp[0][i] = 1
        for i in range(m):
            dp[i][0] = 1
        # 一行一行的遍历
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
