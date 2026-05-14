class Solution {
public:
    int findMin(span<int> nums)
    {
        const int n = nums.size();
        const int first = nums[0];
        int l = 0;
        int r = n;
        while (l < r) {
            const int mid = midpoint(l, r);
            if (nums[mid] >= first) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l % n];
    }
};
