class Solution:
    def numSteps(self, s: str) -> int:
        return s.count('0') + (lambda x: x + 2 * (x > 0))(s.rfind('1'))
