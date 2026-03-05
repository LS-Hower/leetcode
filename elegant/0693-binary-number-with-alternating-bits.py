class Solution: hasAlternatingBits = lambda self, n: (lambda a: a & (a + 1) == 0)(n ^ (n >> 1))
