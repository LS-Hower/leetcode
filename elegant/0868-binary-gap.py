class Solution:
    def binaryGap(self, n: int) -> int:
        return 1 + max(len(p) for p in bin(n)[2:].rstrip('0').split('1')) if n.bit_count() > 1 else 0
