class Solution:
    def reverseWords(self, s: str) -> str:
        string = s.split()
        n = len(string)
        left = 0
        right = n - 1
        while left < right:
            string[left], string[right] = string[right], string[left]
            left += 1
            right -= 1
        return ' '.join(string) # ' '在表示每一个单词之间加空格