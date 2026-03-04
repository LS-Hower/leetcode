class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        return ranges::distance(
            mat
            | views::filter([](span<int> row) { return ranges::count(row, 1) == 1; })
            | views::transform([](span<int> row) { return ranges::find(row, 1) - row.begin(); })
            | views::filter(
                [&mat](auto j) {
                    return ranges::count(
                        mat | views::transform([j](span<int> row) { return row[j]; } ),
                        1
                    ) == 1;
                }
            )
        );
    }
};
