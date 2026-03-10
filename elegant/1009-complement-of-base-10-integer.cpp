class Solution {
public:
    int bitwiseComplement(unsigned n)
    {
        return n == 0 ? 1 : ~n & ((1 << bit_width(n)) - 1);
    }
};
