class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        for (const span q : queries) {
            const int v { q[3] };
            for (const int i : views::iota(q[0], q[1] + 1) | views::stride(q[2])) {
                nums[i] = (1LL * nums[i] * v) % 1'000'000'007;
            }
        }

        return ranges::fold_left(nums, 0, bit_xor<int>{});
    }
};
