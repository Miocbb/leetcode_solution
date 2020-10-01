class Solution:
    def maxSlidingWindow(self, nums, k: int):
        i = 0
        j = k
        rst = []
        while nums[i: j] and j <= len(nums):
            rst.append(max(nums[i:j]))
            i += 1
            j = i + k
        return rst

    def dp(self, nums, k):
        dp = [0 for _ in range(len(nums) - k + 1)]
        dp[0] = max(nums[:k])
        for i in range(1, len(dp)):
            if nums[i - 1] != dp[i - 1]:
                dp[i] = max(dp[i-1], nums[i+k-1])
            else:
                dp[i] = max(nums[i: i+k])
        return dp

    def linear(self, nums, k):
        left = [0 for _ in range(len(nums))]
        right = [0 for _ in range(len(nums))]
        start = 0
        for i in range(len(nums)):
            if i % k == 0:
                start = nums[i]
            else:
                start = max(start, nums[i])
            left[i] = start

        for i in range(len(nums)-1, -1, -1):
            if i == len(nums) - 1 or (i+1) % k == 0:
                start = nums[i]
            else:
                start = max(start, nums[i])
            right[i] = start

        rst = []
        for i in range(len(nums) - k + 1):
            rst.append(max(right[i], left[i+k-1]))
        return rst




nums = [1,3,-1,-3,5,3,6,7]
k = 3
print(Solution().maxSlidingWindow(nums, k))
print(Solution().dp(nums, k))
print(Solution().linear(nums, k))
