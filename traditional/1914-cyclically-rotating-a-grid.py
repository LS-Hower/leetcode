type Pos = tuple[int, int]

def position(m: int, n: int) -> tuple[int, Callable[[int], Callable[[int], Pos]]]:
    def f(layer: int) -> tuple[int, Callable[[int], Pos]]:
        mm = m - 2 * layer - 1
        nn = n - 2 * layer - 1
        def g(ind: int) -> Pos:
            if 0 <= ind < mm:
                delta = ind
                return (layer + delta, layer)
            elif mm <= ind < mm + nn:
                delta = ind - mm
                return (m - 1 - layer, layer + delta)
            elif mm + nn <= ind < mm + nn + mm:
                delta = ind - (mm + nn)
                return (m - 1 - layer - delta, n - 1 - layer)
            elif mm + nn + mm <= ind < mm + nn + mm + nn:
                delta = ind - (mm + nn + mm)
                return (layer, n - 1 - layer - delta)
            else:
                raise ValueError
        return mm + nn + mm + nn, g
    return min(m, n) // 2, f

class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        def get(pos: Pos) -> int:
            i, j = pos
            return grid[i][j]
        def set_(pos: Pos, val: int) -> int:
            i, j = pos
            grid[i][j] = val
        m, n = len(grid), len(grid[0])
        layer_end, calc = position(m, n)
        for layer in range(layer_end):
            cycle_len, c = calc(layer)
            kk = k % cycle_len
            q = deque()
            for i in range(kk):
                q.append(get(c(i)))
            for delta in range(cycle_len):
                dest = (kk + delta) % cycle_len
                dest_pos = c(dest)
                q.append(get(dest_pos))
                set_(dest_pos, q.popleft())
        return grid
