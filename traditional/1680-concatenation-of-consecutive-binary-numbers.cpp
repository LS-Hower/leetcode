class Solution {
public:
    int concatenatedBinary(unsigned n)
    {
        unsigned long long res = 1;
        int width = 1;
        for (const unsigned i : views::iota(2U, n + 1)) {
            if (has_single_bit(i)) {
                ++width;
            }
            res = (res << width | i) % 1'000'000'007U;
        }
        return res;
    }
};
