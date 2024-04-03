class Solution:
    # KMP算法 构建前后缀相同的next数组。这里采用下标减一的方法利于表示
    def getNext(self, next, s):
        j = -1
        next[0] = j
        for i in range(1, len(s)):
            while j >= 0 and s[j+1] != s[i]: # 不相等时去找上一个相等的下标
                j = next[j]
            if s[j+1] == s[i]:
                j += 1 # 相等时同时加1，i已经在循环中加1了
            next[i] = j # 设置next数组的值
            
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        next = [0] * len(needle)
        self.getNext(next, needle)

        j = -1
        for i in range(len(haystack)): # j表示needle的下标，i表示haystack的下标，它们开始匹配
            while j >= 0 and needle[j+1] != haystack[i]:
                j = next[j]
            if needle[j+1] == haystack[i]:
                j += 1
            if j == len(needle) - 1: # 如果匹配到了needle的最后一个下标说明匹配成功
                return i - len(needle) + 1
        return -1