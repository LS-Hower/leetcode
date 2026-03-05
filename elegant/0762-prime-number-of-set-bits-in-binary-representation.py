class Solution: countPrimeSetBits = lambda self, left, right: sum(1 for i in range(left, right + 1) if i.bit_count() in (2, 3, 5, 7, 11, 13, 17, 19))
