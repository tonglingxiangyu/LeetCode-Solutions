class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len( nums) - 1  # 闭区间[left, right]
        if target < nums[left] or target > nums[right]:
            return -1
        while left <= right:  #区间不为空
            # left + (right - left) / 2 在c++和java中可以不溢出
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1 #[mid+1, right]
            else:
                right = mid - 1 #[left, mid-1]
        return left if nums[left] == target else -1
    
nums = [-1,0,3,5,9,12]
target = 9
solution = Solution()
print(solution.search(nums, target))