class Solution:
    # 剪枝：如果下一层的sum（就是本层的 sum + candidates[i]）已经大于target，就可以结束本轮for循环的遍历。
    def traversal(self, candidates, target, path, ans, Sum, start):
        if Sum == target:
            ans.append(path[:])
        if Sum > target:
            return
        for i in range(start, len(candidates)):
            if Sum + candidates[i] > target: # 剪枝
                break
            Sum += candidates[i]
            path.append(candidates[i])
            self.traversal(candidates, target, path, ans, Sum, i) # 不用i+1了，表示可以重复读取当前的数
            Sum -= candidates[i]
            path.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        candidates.sort()
        self.traversal(candidates, target, path, ans, 0, 0)
        return ans