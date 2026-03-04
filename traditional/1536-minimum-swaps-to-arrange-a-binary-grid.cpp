class Solution {
public:
    int minSwaps(vector<vector<int>>& grid)
    {
        const int n = grid.size();

        auto tail0 = grid | views::transform(
            [n](span<int> row) -> int {
                const auto it = ranges::find_last(row, 1).begin();
                return it == row.end() ? n : row.end() - it - 1;
            }
        ) | ranges::to<vector>();
        int res = 0;

        for (const int i : views::iota(0, n)) {
            const auto ind = views::iota(i, n);
            const auto it = ranges::find_if(
                ind,
                [n, i, &tail0](int row_ind) {
                    return tail0[row_ind] >= n - i - 1;
                }
            );
            if (it == ind.end()) {
                return -1;
            }
            const int ok = *it;
            res += ok - i;
            for (const int j : views::iota(i, ok) | views::reverse) {
                swap(tail0[j], tail0[j + 1]);
                grid[j].swap(grid[j + 1]);
            }
        }
        return res;
    }
};
