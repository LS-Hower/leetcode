class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks)
    {
        ranges::sort(
            tasks,
            {},
            [](span<int> t) { return t[1] - t[0]; }
        );
        return ranges::fold_left(
            tasks,
            int{},
            [](int m, span<int> t) { return ranges::max(m + t[0], t[1]); }
        );
    }
};
