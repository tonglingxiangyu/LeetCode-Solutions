class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort() # 排序了才能使用双指针
        n = len(nums)
        ans = []

        for i in range(n - 3):
            if nums[i] * 4 > target:
                return ans
            if i > 0 and nums[i-1] == nums[i]: # 去重
                continue
            for j in range(i+1, n-2):
                if j > i + 1 and nums[j-1] == nums[j]: # 去重
                    continue
                left = j + 1
                right = n - 1
                while left < right:
                    sums = nums[i] + nums[j] + nums[left] + nums[right]
                    if sums > target:
                        right -= 1
                    elif sums < target:
                        left += 1
                    else:
                        ans.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        while left < right and nums[left] == nums[left+1]:
                            left += 1
                        left += 1
                        
                        while left < right and nums[right] == nums[right-1]:
                            right -= 1
                        right -= 1
                        
                        
        return ans
            