class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> ind{};
        for (const auto [i, x] : nums | views::enumerate) {
            ind[x].emplace_back(i);
        }
        const auto ind_lss = ind | views::values;
        const auto below3 = [](span<int> sp) { return sp.size() < 3; };
        return ranges::all_of(ind_lss, below3) ?
            -1 :
            ranges::min(
                ind_lss
                | views::filter(not_fn(below3))
                | views::transform(
                    [](span<int> sp) {
                        return ranges::min(
                            views::zip_transform(
                                [](int a, int c) { return 2 * (c - a); },
                                sp,
                                sp | views::drop(2)
                            )
                        );
                    }
                )
            );
    }
};
