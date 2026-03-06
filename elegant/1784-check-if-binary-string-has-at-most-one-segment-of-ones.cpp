class Solution {
public:
    bool checkOnesSegment(string_view s) {
        return ranges::is_sorted(s, greater{});
    }
};
