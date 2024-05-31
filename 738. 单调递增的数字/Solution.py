class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        # 一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），首先想让strNum[i - 1]--，然后strNum[i]给为9
        # 需要从后往前遍历，因为从前向后遍历的话，遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]减一，但此时如果strNum[i - 1]减一了，可能又小于strNum[i - 2]。
        ans = []
        n = str(n)
        if len(n) == 1:
            return int(n)
        for i in n:
            ans.append(i)
        flag = len(ans) # 从flag的位置往后都变成9
        for i in range(len(ans)-1, 0, -1):
            if ans[i-1] > ans[i]:
                ans[i-1] = str(int(ans[i-1]) - 1)
                flag = i
        for i in range(flag, len(ans)):
            ans[i] = '9'
        return  int(''.join(ans))