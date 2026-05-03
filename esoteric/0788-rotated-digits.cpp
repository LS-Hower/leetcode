

class Solution {
public:
    int rotatedDigits(int n)
    {
        constexpr static int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
        return ranges::count_if(views::iota(1, n + 1), [](int i) { return [](string_view num) { return ranges::all_of(num, [](char ch) { return check[ch - '0'] != -1; }) && ranges::any_of(num, [](char ch) { return check[ch - '0'] == 1; }); }(to_string(i)); });
    }
};
