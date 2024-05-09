class Solution:
    # 分割和组合问题类似。用回溯的方法暴力搜索答案
    def isPalindrome(self, s, start, i): # 用双指针法判断是否是回文串
        left = start
        right = i
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True

    def backtracking(self, s, start, path, ans):
        if start >= len(s): # 说明找到一个满足的分割方法
            ans.append(path[:])
            return
        for i in range(start, len(s)):
            if(self.isPalindrome(s, start, i)):
                path.append(s[start: i+1])
            else:
                continue
            self.backtracking(s, i+1, path, ans)
            path.pop()


    def partition(self, s: str) -> List[List[str]]:
        ans = []
        path = []
        self.backtracking(s, 0, path, ans)
        return ans