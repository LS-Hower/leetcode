constexpr std::array prime20 {
    2, 3, 5, 7, 11, 13, 17, 19
};

class Solution {
public:
    int countPrimeSetBits(int left, int right)
    {
        return ranges::count_if(
            views::iota(0u + left, 0u + right + 1)
            | views::transform(popcount<unsigned>),
            [](int cnt) {
                return ranges::find(prime20, cnt) != prime20.end();
            }
        );
    }
};
