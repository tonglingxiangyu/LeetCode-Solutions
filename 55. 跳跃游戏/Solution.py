class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # 更新覆盖范围，只要最后的下标在覆盖范围内则说明可以到达
        cover = 0
        if len(nums) < 2:
            return True
        cover = nums[0]
        i= 0
        while i <= cover: # 这里的cover会动态更新
            cover = max(cover, nums[i]+i)
            if cover >= len(nums)-1:
                return True
            i += 1
        return False