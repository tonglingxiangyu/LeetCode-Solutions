class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n-2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]: # 防止结果重复
                continue
            if nums[i] + nums[i + 1] + nums[i + 2] > 0:  # 优化一
                break
            if nums[i] + nums[-2] + nums[-1] < 0:  # 优化二
                continue
            left = i + 1
            right = n - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                elif nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    ans.append([nums[i], nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    
                    right -= 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
        return ans