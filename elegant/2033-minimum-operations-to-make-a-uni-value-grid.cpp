class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        if (ranges::any_of(
            grid,
            [x, first = grid[0][0]](span<int> row) {
                return ranges::any_of(
                    row,
                    [x, first](int g) {
                        return (g - first) % x != 0; });}))
        {
            return -1;
        }
        auto ser = grid | views::join | ranges::to<vector>();
        const auto mid = ser.begin() + ser.size() / 2;
        ranges::nth_element(ser, mid);
        return ranges::fold_left(
            ser
            | views::transform(
                [median = *mid, x](int g) {
                    return abs(g - median) / x; }),
            0,
            plus<int>{});
    }
};
