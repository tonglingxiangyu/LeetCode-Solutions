class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        # 分别计算A+B和C+D的所有和，然后再在集合中查找需要的数和出现的次数
        ans = 0
        dict1 = {}
        for i in nums1:
            for j in nums2:
                if (i + j) in dict1.keys():
                    dict1[i+j] += 1
                else:
                    dict1[i+j] = 1

        dict2 = {}
        for i in nums3:
            for j in nums4:
                if (0 - i - j) in dict1.keys(): # 匹配成功
                    ans += dict1[0 - i - j]
        return ans
        
