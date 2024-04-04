class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i in "([{":
                stack.append(i)
            elif i in ")]}":
                if not stack:
                    return False
                t = stack.pop()
                if i == ')' and t == '(':
                    continue
                if i == ']' and t == '[':
                    continue
                if i == '}' and t == '{':
                    continue
                else:
                    return False
        return True if not stack else False