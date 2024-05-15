class Solution:
    # 类似子集2的思路，但是因为数组不是递增的，所以去重的方法不一样
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
       ans = []
       path = []
       self.backtracking(ans, path, nums, 0)
       return ans
    def backtracking(self, ans, path, nums, start):
        if len(path) >= 2:
            ans.append(path[:])
        # 搜索的时候一层的不能出现相同的，否则会出现重复
        t = [] # 每一个子树的一层上都有一个t
        for i in range(start, len(nums)):
            if (not path or nums[i] >= path[-1]) and nums[i] not in t: # path为空nums[i]也可能在t中
                path.append(nums[i])
                t.append(nums[i])
            else:
                continue
                
            self.backtracking(ans, path, nums, i+1)
            path.pop()