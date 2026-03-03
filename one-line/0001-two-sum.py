class Solution:
    twoSum = lambda self, nums, target: (lambda f: f(f, sorted([i for i in range(len(nums))], key=lambda i: nums[i]), len(nums) - 1, 0))(lambda me, ls, i, j: (lambda sigma: (ls[i], ls[j]) if sigma == target else me(me, ls, i, j + 1) if sigma < target else me(me, ls, i - 1, j))(nums[ls[i]] + nums[ls[j]]))
