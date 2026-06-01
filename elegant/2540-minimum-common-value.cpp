class Solution {
public:
    int getCommon(span<int> nums1, span<int> nums2)
    {
        if (nums1.empty() || nums2.empty()) {
            return -1;
        }
        const int h1 = nums1.front();
        const int h2 = nums2.front();
        if (h1 < h2) {
            return getCommon(nums1.subspan<1>(), nums2);
        } else if (h1 > h2) {
            return getCommon(nums1, nums2.subspan<1>());
        } else {
            return h1;
        }
    }
};
