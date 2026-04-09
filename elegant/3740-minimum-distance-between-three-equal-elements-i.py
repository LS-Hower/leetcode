class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        return min(
            starmap(
                lambda i, j, k:
                    abs(i - j) + abs(j - k) + abs(k - i),
                filter(
                    lambda ijk:
                        nums[ijk[0]] == nums[ijk[1]] == nums[ijk[2]],
                    combinations(range(len(nums)), 3),
                )
            ),
            default=-1,
        )
