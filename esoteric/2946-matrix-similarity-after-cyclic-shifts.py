class Solution: areSimilar = lambda self, mat, k: (lambda l: all(all(map(eq, row, chain(islice(row, l, None), islice(row, l)))) for row in mat))(k % len(mat[0]))
