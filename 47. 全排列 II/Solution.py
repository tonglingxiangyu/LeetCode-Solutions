class Solution:
    # 考虑去重，同一层的遇到使用过的数字就跳过，排序后判断前一位数字与当前一样跳过即可
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        used = [False] * len(nums)
        nums.sort()
        self.backtracking(ans, path, nums, used)
        return ans
    def backtracking(self, ans, path, nums, used):
        if len(path) == len(nums):
            ans.append(path[:])
            return
        for i in range(0, len(nums)):
            # 因为这里的used是全局变量，表示同一个树枝有重复；而子集问题中的used是局部变量，表示同一个树层有重复
            # used[i-1] 是在 nums[i-1] 在回退的时候刚刚被撤销的选择
            # used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            # used[i - 1] == false，说明同一树层nums[i - 1]使用过，刚刚被撤销的选择
            # 如果同一树层nums[i - 1]使用过则直接跳过
            if i > 0 and not used[i-1] and nums[i] == nums[i-1]: # 去重
                continue
            if not used[i]:
                used[i] = True
                path.append(nums[i])
                self.backtracking(ans, path, nums, used)
                path.pop()
                used[i] = False