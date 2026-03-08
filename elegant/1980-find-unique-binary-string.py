class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        return ''.join(str(int(s[i]) ^ 1) for i, s in enumerate(nums))
