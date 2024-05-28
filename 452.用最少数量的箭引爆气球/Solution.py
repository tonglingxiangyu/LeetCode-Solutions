class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # 排序后从前往后找重叠的气球，后面的气球的左端小于等于第一个气球的右端说明重叠，计算重叠数即使答案
        ans = 1 # 至少需要一支箭
        points.sort(key=lambda x: x[0])
        for i in range(1, len(points)):
            if points[i][0] > points[i-1][1]: # 说明不重叠，前面的部分需要一支箭
                ans += 1
            else:
                points[i][1] = min(points[i-1][1], points[i][1]) # 更新重叠气球最小右边界
        return ans