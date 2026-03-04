class Solution {
public:
    int concatenatedBinary(unsigned n)
    {
        return ranges::fold_left(
            views::iota(1U, n + 1),
            0ULL,
            [](unsigned long long acc, unsigned x) -> unsigned {
                return (acc << bit_width(x) | x) % 1'000'000'007U;
            }
        );
    }
};
