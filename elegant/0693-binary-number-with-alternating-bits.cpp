class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        if (n < 1) {
            unreachable();
        }
        return has_single_bit(0u + n + (n >> 1) + 1);
    }
};
