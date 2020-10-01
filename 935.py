class Solution:
    def knightDialer(self, n: int) -> int:
        """
        dp[xi, n] = An, starting from digit xi, dial n number, there are An number of choices.
        dp[xi, n+1] = \sum_j [xi -> xj] * dp[xj, n]

        dp[n] = \sum_i dp[xi, n]
        """

        valid = [
            (0, 4),
            (0, 6),
            (1, 6),
            (1, 8),
            (2, 7),
            (2, 9),
            (3, 4),
            (3, 8),
            (4, 0),
            (4, 3),
            (4, 9),
            (6, 0),
            (6, 1),
            (6, 7),
            (7, 2),
            (7, 6),
            (8, 1),
            (8, 3),
            (9, 2),
            (9, 4),
        ]
        print(valid)

        # dp[xi, n]
        # n = 1
        mod = 10**9 + 7
        dp_n = [1 for _ in range(10)]
        for n in range(n-1):
            dp_n_1 = [0] * 10
            for xi, xj in valid:
                dp_n_1[xi] += dp_n[xj]
            dp_n = dp_n_1
        return sum(dp_n) % mod

print(Solution().knightDialer(3131))
