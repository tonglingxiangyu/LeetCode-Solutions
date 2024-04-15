class Solution:
    def backtracking(self, start, k, n, path, ans):
        if len(path) == k:
            if sum(path) == n:
                ans.append(path[:])
            return
        for i in range(start, 10):
            path.append(i)
            self.backtracking(i+1, k, n, path, ans)
            path.pop()
        
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        path = []
        self.backtracking(1, k, n, path ,ans)
        return ans