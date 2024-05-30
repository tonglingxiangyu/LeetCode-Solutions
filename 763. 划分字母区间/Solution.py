class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # 在遍历的过程中相当于是要找每一个字母的边界，如果找到之前遍历过的所有字母的最远边界，说明这个边界就是分割点了。
        # 可以分为如下两步：1.统计每一个字符最后出现的位置。2.从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
        from collections import defaultdict
        indexs = defaultdict(int)
        for i in range(len(s)):
            indexs[s[i]] = i
        ans = []
        max_index = 0
        last_index = 0

        for i in range(len(s)):
            max_index = max(max_index, indexs[s[i]])
            if i == max_index:
                ans.append(i - last_index + 1)
                last_index = i + 1
        return ans