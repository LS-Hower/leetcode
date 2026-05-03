class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        const auto n = matrix.size();
        for (const auto [i, j]
            : views::cartesian_product(
                views::iota(0zu, n / 2),
                views::iota(0zu, (n + 1) / 2)))
        {
            const auto lt        = matrix[    i][    j];
            matrix[    i][    j] = matrix[n-1-j][    i];
            matrix[n-1-j][    i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[    j][n-1-i];
            matrix[    j][n-1-i] = lt;
        }
    }
};
