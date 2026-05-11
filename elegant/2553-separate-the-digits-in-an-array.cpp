class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        return nums
            | views::transform(static_cast<string(*)(int)>(to_string))
            | views::join
            | views::transform([](char c) -> int { return c - '0'; })
            | ranges::to<vector>();
    }
};
