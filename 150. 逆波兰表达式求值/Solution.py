class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i in "+-*/":
                if not stack:
                    return -1
                t1 = int(stack.pop())
                t2 = int(stack.pop())
                if i == '+':
                    t = t2 + t1
                elif i == '-':
                    t = t2 - t1
                elif i == '*':
                    t = t2 * t1
                else:
                    t = t2 / t1
                stack.append(t)
            else:
                stack.append(i)
        return int(stack.pop())