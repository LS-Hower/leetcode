class Solution {
public:
    int findMin(vector<int>& nums)
    {
        const int n = nums.size();
        const int first = nums[0];
        int diff_l = 0;
        int diff_r = n;
        while (diff_l < n && nums[diff_l] == first
               && diff_r > 0 && nums[diff_r - 1] == first
               && diff_l <= diff_r)
        {
            ++diff_l, --diff_r;
        }

        if (!(diff_l <= diff_r)) {
            return first;
        }
        if (nums[diff_l] != first && nums[diff_r - 1] != first) {
            --diff_l;
        }
        const int new_first = nums[diff_l];
        int l = diff_l;
        int r = diff_r;
        while (l < r) {
            const int mid = midpoint(l, r);
            //println("{} {} => {}", l, r, mid);
            if (nums[mid] >= new_first) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l == diff_r ? diff_l : l];
    }
};
