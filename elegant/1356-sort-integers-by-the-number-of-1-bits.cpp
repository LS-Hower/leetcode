class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        ranges::sort(arr, {}, [](unsigned x) { return pair{popcount(x), x}; });
        return arr;
    }
};
