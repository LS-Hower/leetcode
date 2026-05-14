class Solution {
public:
    bool isGood(vector<int>& nums)
    {
        const int n = nums.size();
        ranges::sort(nums);
        return ranges::equal(
            views::join(
                array{
                    views::iota(1, n),
                    views::iota(n - 1, n)}),
            nums);
    }
};
