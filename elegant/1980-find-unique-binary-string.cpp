class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        // 康托尔对角线
        const int n = nums.size();
        return views::iota(0, n)
            | views::transform([nums](int i) -> char {
                return nums[i][i] ^ 1;
            })
            | ranges::to<string>();
    }
};
