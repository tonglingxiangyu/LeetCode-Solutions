class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0
        fast = 0 # 快慢指针，slow指向新数组的下标，fast指向需要传入新数组的下标，即遇到val直接跳过
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow