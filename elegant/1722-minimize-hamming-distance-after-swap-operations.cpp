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

    void link(T x, T y)
    {
        T xr = repr(x), yr = repr(y);
        if (xr == yr) {
            return;
        }
        if (height[xr] < height[yr]) {
            return link(yr, xr);
        }
        parent[yr] = xr;
        if (height[xr] == height[yr]) {
            ++height[xr];
        }
    }
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps)
    {
        UnionFind<int> uf(source.size());
        unordered_map<int, unordered_map<int, int>> appear{};

        for (const span sw : allowedSwaps) {
            uf.link(sw[0], sw[1]);
        }
        for (const auto [i, x] : source | views::enumerate) {
            ++appear[uf.repr(i)][x];
        }
        int dist = 0;
        for (const auto [i, x] : target | views::enumerate) {
            if (const int r = uf.repr(i); appear[r][x]) {
                --appear[r][x];
                continue;
            }
            ++dist;
        }
        return dist;
    }
};
