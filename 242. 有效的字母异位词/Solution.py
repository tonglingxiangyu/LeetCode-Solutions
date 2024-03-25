class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        alphas = [0] * 26
        for i in s:
            alphas[ord(i) - ord('a')] += 1
        for i in t:
            alphas[ord(i) - ord('a')] -= 1
        for a in alphas:
            if a != 0:
                return False
        return True



# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         if len(s) != len(t):
#             return False
#         a_count = Counter(s)
#         t_count = Counter(t)
#         return a_count == t_count