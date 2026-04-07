class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        return reduce(xor, reduce(lambda ls, q: reduce(lambda ls, i: (ls.__setitem__(i, (ls[i] * q[3]) % (10**9 + 7)), ls)[-1], range(q[0], q[1]+1, q[2]), ls), queries, nums))
