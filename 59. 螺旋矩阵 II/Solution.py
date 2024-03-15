class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        # 每次循环遍历两列，如果 n 为奇数需要单独计算中心的值
        loop, mid = n // 2, n // 2
        ans = [[0] * n for _ in range(n)]
        count = 1
        for l in range(loop): # 拐角处的横纵坐标相等
            for i in range(n - 1 - 2 * l):
                ans[l][i + l] = count
                count += 1
            for i in range(n - 1 - 2 * l):
                ans[i + l][n - 1 - l] = count
                count += 1
            for i in range(n - 1 - 2 * l):
                ans[n - 1 - l][n - 1 - l - i] = count
                count += 1
            for i in range(n - 1 - 2 * l):
                ans[n - 1 - l - i][l] = count
                count += 1
        if n % 2 == 1:
            ans[mid][mid] = count
        return ans

