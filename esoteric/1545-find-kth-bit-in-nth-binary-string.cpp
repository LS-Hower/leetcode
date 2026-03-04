class Solution {
public:
    char findKthBit(int n, int k)
    {
        return k == 1 ? '0' : [this, n, k, m = 1 << (n - 1)]() -> char { return k == m ? '1' : k < m ? findKthBit(n - 1, k) : '0' + ('1' - (findKthBit(n - 1, m + (m - k)))); }();
    }
};
