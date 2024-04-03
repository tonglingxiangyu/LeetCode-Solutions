class Solution:
    # KMP算法。数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
    # 强烈建议大家把next数组打印出来，看看next数组里的规律，有助于理解KMP算法
    def repeatedSubstringPattern(self, s: str) -> bool:  
        if len(s) == 0:
            return False
        nxt = [0] * len(s)
        self.getNext(nxt, s)
        if nxt[-1] != -1 and len(s) % (len(s) - (nxt[-1] + 1)) == 0:
            return True
        return False
    
    def getNext(self, nxt, s):
        nxt[0] = -1
        j = -1
        for i in range(1, len(s)):
            while j >= 0 and s[i] != s[j+1]:
                j = nxt[j]
            if s[i] == s[j+1]:
                j += 1
            nxt[i] = j
        return nxt


    # def repeatedSubstringPattern(self, s: str) -> bool:
    #     if len(s) == 0:
    #         return False
    #     ss = s[1:] + s[:-1] # 首位相连并且去头去尾，如果还能找到s说明满足条件
    #     return ss.find(s) != -1
    