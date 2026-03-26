class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k)
    {
        const int n = mat[0].size();
        const int l = k % n;
        const int r = n - l;
        return ranges::all_of(
            mat,
            [n, l, r](span<int> row) {
                // C++26: views::concat
                return ranges::equal(
                    row | views::drop(l),
                    row | views::take(r)
                ) && ranges::equal(
                    row | views::take(l),
                    row | views::drop(r)
                );
            }
        );
    }
};
