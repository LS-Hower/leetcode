class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (const int i : views::iota(0, k / 2)) {
            ranges::swap_ranges(
                span(grid[x + i]         | views::drop(y) | views::take(k)),
                span(grid[x + k - 1 - i] | views::drop(y) | views::take(k))
            );
        }
        return grid;
    }
};
