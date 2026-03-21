class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        const int n = mat.size();
        return ranges::fold_left_first(
            views::cartesian_product(views::iota(0, n), views::iota(0, n))
            | views::transform(
                [n, &mat, &target](auto p) -> unsigned {
                    const auto [i, j] = p;
                    const int x = mat[i][j];
                    return (x == target[i][j]) << 3
                        | (x == target[j][n-1-i]) << 2
                        | (x == target[n-1-j][i]) << 1
                        | (x == target[n-1-i][n-1-j]);
                }
            ),
            bit_and<unsigned>{}
        ).value();
    }
};
