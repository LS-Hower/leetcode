class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        return sum(
            1
            for j in (
                row.index(1)
                for row in mat
                if row.count(1) == 1
            )
            if sum(
                1
                for i in range(len(mat))
                if mat[i][j]
            ) == 1
        )
