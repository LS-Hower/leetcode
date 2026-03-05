struct Solution {
    function<int(string_view)> numSteps { [](string_view s) { return plus{}(minus{}(ranges::size(s), 1), [s](auto ind) { return ind ? plus{}(ranges::count(plus{}(ranges::begin(s), 1), plus{}(ranges::begin(s), ind), '0'), 2) : 0; }(ranges::distance(ranges::begin(s), ranges::find_last(s, '1').begin()))); } };
};
