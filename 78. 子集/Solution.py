class Solution:
    # 组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点。
    # 因为数组中的元素互不相同，所以不会存在重复子集的情况，保存每一个节点即可。
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        self.backtracking(ans, path, nums, 0)
        return ans
    def backtracking(self, ans, path, nums, start):
        ans.append(path[:])
        if start >= len(nums):
            return
        for i in range(start, len(nums)):
            path.append(nums[i])
            self.backtracking(ans, path, nums, i+1)
            path.pop()
