class Solution:
    def backtracking(self, index, n, k, path, ans):
        if len(path) == k:
            ans.append(path[:]) # 这里需要复制path的内容，不然会加入path的引用
            return
        for i in range(index, n + 1):
            path.append(i)
            self.backtracking(i+1, n, k, path, ans)
            path.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        path = []
        self.backtracking(1, n, k, path, ans)
        return ans