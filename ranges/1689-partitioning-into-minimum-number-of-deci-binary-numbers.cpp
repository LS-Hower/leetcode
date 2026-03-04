class Solution {
public:
    int minPartitions(string_view n)
    {
        return ranges::max(
            n | views::transform([](char c) { return c - '0'; })
        );
    }
};
