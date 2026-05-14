class Solution: isGood = lambda self, nums: (lambda sl: lambda n: (lambda f: f(f)(0))(lambda me: lambda i: i == n or sl[i] == i + (i < n - 1) and me(me)(i + 1)))(sorted(nums))(len(nums))
