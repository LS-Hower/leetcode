bitset<(1 << 20)> appear{};

class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        const int n = s.size();
        if (k > n) {
            return false;
        }
        const int substrcnt = n - k + 1;
        const int destcnt = 1 << k;
        if (substrcnt < destcnt) {
            return false;
        }

        appear.reset();
        int current = 0;
        for (int i = 0; i < k; ++i) {
            current <<= 1;
            current |= (s[i] - '0');
        }
        appear.set(current);
        for (int i = k; i < n; ++i) {
            current <<= 1;
            current &= (1 << k) - 1;
            current |= (s[i] - '0');
            appear.set(current);
        }
        return appear.count() == destcnt;
    }
};
