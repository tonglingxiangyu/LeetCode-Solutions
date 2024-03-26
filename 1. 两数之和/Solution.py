class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 使用哈希表（这里是字典）
        n = len(nums)
        numbers = {}
        ans = []
        for i in range(n):
            if (target - nums[i]) in numbers.keys():
                ans.append(i)
                ans.append(numbers[target-nums[i]])
                break
            else:
                numbers[nums[i]] = i
        return ans






# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         n = len(nums)
#         ans = []
#         for i in range(n):
#             sum = nums[i]
#             for j in range(n - 1 - i):
#                 sum += nums[i + 1 + j]
#                 if sum == target:
#                     ans.append(i)
#                     ans.append(i+1+j)
#                     return ans
#                 sum = nums[i]