class Solution:
    numSpecial = lambda self, mat: (lambda rows_sum, cols_sum: sum(1 for i, row in enumerate(mat) for j, x in enumerate(row) if x == 1 and rows_sum[i] == 1 and cols_sum[j] == 1))([sum(row) for row in mat], [sum(col) for col in zip(*mat)])
