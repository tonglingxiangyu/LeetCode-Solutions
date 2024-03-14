class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 0
        Sum = nums[left]
        ans = 0
        length = 0
        if Sum >= target:
            length = 1
            ans = length

        n = len(nums)
        while (right + 1) < n:
            right += 1
            Sum += nums[right]
            if Sum >= target:
                length = right - left + 1
            while (Sum - nums[left]) >= target:   
                Sum -= nums[left]
                left += 1
                length -= 1
            if ans == 0 or ans > length:
                ans = length
        return ans
        