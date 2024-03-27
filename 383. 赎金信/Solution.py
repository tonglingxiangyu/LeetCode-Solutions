class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict1 = {}
        for i in magazine:
            if i not in dict1.keys():
                dict1[i] = 1
            else:
                dict1[i] += 1
        for i in ransomNote:
            if i not in dict1.keys() or dict1[i] == 0:
                return False
            else:
                dict1[i] -= 1
        return True
