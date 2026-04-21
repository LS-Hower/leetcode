class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        return [q for q in queries if any(sum(map(ne, s, q)) <= 2 for s in dictionary)]
