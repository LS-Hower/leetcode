template <std::integral T>
class UnionFind {
    vector<T> parent;
    vector<T> height;

public:
    UnionFind(vector<T>::size_type size)
        : parent(size)
        , height(size, 0)
    {
        ranges::iota(parent, 0);
    }

    T repr(T x)
    {
        return parent[x] != x ? parent[x] = repr(parent[x]) : x;
    }

    bool link(T x, T y)
    {
        T xr = repr(x), yr = repr(y);
        if (xr == yr) {
            return false;
        }
        if (height[xr] < height[yr]) {
            return link(yr, xr);
        }
        parent[yr] = xr;
        if (height[xr] == height[yr]) {
            ++height[xr];
        }
        return true;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        const auto m = grid.size();
        const auto n = grid[0].size();
        const auto f = [n](auto i, auto j) { return i * n + j; };
        UnionFind<size_t> uf(m * n);
        for (const auto [i, j] :
            views::cartesian_product(
                views::iota(0zu, m),
                views::iota(0zu, n)))
        {
            const auto current = grid[i][j];
            const auto k = f(i, j);
            if (i != 0 && current == grid[i - 1][j] && !(uf.link(k, f(i - 1, j)))
                || j != 0 && current == grid[i][j - 1] && !(uf.link(k, f(i, j - 1))))
            {
                return true;
            }
        }
        return false;
    }
};
