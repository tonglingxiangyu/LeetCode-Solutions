class Solution:
    # 排列问题不需要考虑起始位置即不需要start了，而且需要每次都从开头寻找没有插入的数，使用used数组记录插入过的数
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        used = [False] * len(nums)
        self.backtracking(ans, path, nums, used)
        return ans
    def backtracking(self, ans, path, nums, used):
        if len(path) == len(nums):
            ans.append(path[:])
            return
        
        for i in range(0, len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            self.backtracking(ans, path, nums, used)
            path.pop()
            used[i] = False