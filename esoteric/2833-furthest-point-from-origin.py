class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return (lambda l, r: abs(l - r) + len(moves) - (l + r))(moves.count('L'), moves.count('R'))
