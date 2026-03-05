class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        char buf[32];
        return ranges::all_of(
            ranges::subrange{buf, buf + sprintf(buf, "%b", n)}
            | views::pairwise_transform(not_equal_to<char>{}),
            identity{}
        );
    }
};
