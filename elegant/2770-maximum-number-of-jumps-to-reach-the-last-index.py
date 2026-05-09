class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @cache
        def dp(i: int) -> int:
            if i == 0:
                return 0
            return 1 + max(
                (
                    dp(j)
                    for j in range(i)
                    if abs(nums[i] - nums[j]) <= target
                ),
                default=-inf
            )
        res = dp(len(nums) - 1)
        return -1 if res < 0 else res
