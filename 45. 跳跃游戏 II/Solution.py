class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = 0
        cover = 0
        if len(nums) == 1:
            return 0
        index = 0
        while index < len(nums):
            ans += 1
            for i in range(index, cover+1):
                cover = max(cover, nums[i]+i)
                if cover >= len(nums)-1:
                    return ans
                index = i
        