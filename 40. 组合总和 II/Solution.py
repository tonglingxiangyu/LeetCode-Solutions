class Solution:
    def traversal(self, ans, candidates, target, path, Sum, start):
        if Sum == target:
            ans.append(path[:])
            return
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i-1]: # 去除重复的组合。说明前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]。
                continue
            if Sum + candidates[i] > target: # 剪枝
                break
            Sum += candidates[i]
            path.append(candidates[i])
            self.traversal(ans, candidates, target, path, Sum, i+1)
            Sum -= candidates[i]
            path.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        path = []
        self.traversal(ans, candidates, target, path, 0, 0)
        return ans
