class Solution {
public:
    int minimumCost(vector<int>& cost)
    {
        constexpr auto intsum = [](auto&& r) {
            return ranges::fold_left(r, 0, plus{});
        };
        ranges::sort(cost, greater{});
        return intsum(
            cost
            | views::chunk(3)
            | views::transform(views::take(2))
            | views::transform(intsum)
        );
    }
};
