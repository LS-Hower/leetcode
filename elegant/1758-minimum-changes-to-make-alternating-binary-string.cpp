class Solution {
public:
    int minOperations(string_view sb)
    {
        const auto step = ranges::count_if(
            sb | views::enumerate,
            [](auto p) -> bool {
                const auto [i, c] = p;
                return (c ^ i) & 1;
            }
        );
        return min<int>(step, sb.size() - step);
    }
};
