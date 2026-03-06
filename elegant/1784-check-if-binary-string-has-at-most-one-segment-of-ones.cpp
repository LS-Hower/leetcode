class Solution {
public:
    bool checkOnesSegment(string s) {
        return ranges::all_of(
            ranges::find(s, '1'),
            ranges::find_last(s, '1').begin(),
            [](char c) { return c == '1'; }
        );
    }
};
