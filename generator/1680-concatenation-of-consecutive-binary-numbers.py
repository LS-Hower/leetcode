class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return reduce(lambda acc, x: (acc << x.bit_length() | int(x)) % 1_000_000_007, range(1, n + 1))
