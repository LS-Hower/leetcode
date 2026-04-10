class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ind = defaultdict(list)
        for i, x in enumerate(nums):
            ind[x].append(i)
        return min(
            (
                min(
                    2 * (c - a)
                    for a, c in zip(ind_ls, islice(ind_ls, 2, None))
                )
                for ind_ls in ind.values()
                if len(ind_ls) >= 3
            ),
            default=-1,
        )
