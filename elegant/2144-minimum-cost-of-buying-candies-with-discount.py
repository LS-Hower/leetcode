class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        return sum(map(lambda batch: sum(batch[:2]), batched(sorted(cost, reverse=True), 3)))
