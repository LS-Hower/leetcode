class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        inds = defaultdict(list)
        for i, x in enumerate(nums):
            inds[x].append(i)

        ans = [0] * len(nums)
        for ls in inds.values():
            n = len(ls)
            s = sum(ls) - n * ls[0]
            ans[ls[0]] = s
            for i in range(1, n):
                ans[ls[i]] = ans[ls[i-1]] + (i * 2 - n) * (ls[i] - ls[i - 1])
        return ans
