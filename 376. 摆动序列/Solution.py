class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        if len(nums) == 2:
            if nums[0] == nums[1]:
                return 1
            return 2
        prediff = 0
        curdiff = 0
        ans = 1
        for i in range(len(nums) - 1):
            curdiff = nums[i+1] - nums[i]
            if (prediff <= 0 and curdiff > 0) or (prediff >= 0 and curdiff < 0):
                ans += 1
                prediff = curdiff
        return ans