class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid)
    {
        return [](span<const vector<char>> res) {
            return views::iota(0zu, res[0].size())
                | views::transform(
                    [m = res.size(), res](auto j) {
                        return views::iota(0zu, m)
                            | views::transform(
                                [m, j, res](auto i) {
                                    return res[m - 1 - i][j];
                                }
                            );
                    }
                )
                | ranges::to<vector<vector<char>>>();
            }(
            boxGrid
            | views::transform(
                [](span<const char> row) {
                    return row
                        | views::split('*')
                        | views::transform(
                            [](span<const char> part) {
                                const size_t stone_cnt = ranges::count(part, '#');
                                return array{
                                    views::repeat('.', part.size() - stone_cnt),
                                    views::repeat('#', stone_cnt),
                                }
                                | views::join
                                | ranges::to<vector>();
                            }
                        )
                        | views::join_with('*');
                }
            )
            | ranges::to<vector<vector<char>>>()
        );
    }
};
