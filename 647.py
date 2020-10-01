class Solution:
    def is_valid(self, s):
        return s and s == s[::-1]

    def countSubstrings(self, s: str) -> int:
        # brutal force
        N = len(s)

        if N <= 1:
            return max(0, N)

        count = 0
        for i in range(N):
            for j in range(1, N + 1):
                if self.is_valid(s[i:j]):
                    count += 1
        return count

s = "abc"
s = "aaa"
print(Solution().countSubstrings(s))
