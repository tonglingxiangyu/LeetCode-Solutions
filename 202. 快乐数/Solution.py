class Solution:
    def getsum(self, n):
        sum = 0
        while n:
            t = n % 10
            sum += t ** 2
            n //= 10
        return sum

    def isHappy(self, n: int) -> bool:
        numbers = set()
        while 1:
            n = self.getsum(n)
            if n == 1:
                return True
            if n in numbers:
                return False
            else:
                numbers.add(n)