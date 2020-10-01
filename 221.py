class Solution:
    def maximalSquare(self, matrix) -> int:
        """
        DP problem:
        dp[i][j] = the length of largest square whose bottom-right corner is at
            (i, j) in the matrix.

        Transition equation:
        1. matrix(i, j) = 1:
        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        2. matrix(i, j) = 0:
        dp[i][j] = 0
        """
        if not matrix or not matrix[0]:
            return 0
        row = len(matrix)
        col = len(matrix[0])

        dp = [[0 for _ in range(col)] for _ in range(row)]
        print(dp)
        rst = 0
        for i in range(row):
            for j in range(col):
                if (matrix[i][j] == '1'):
                    if i > 0 and j > 0:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    else:
                        dp[i][j] = 1
                    rst = max(dp[i][j], rst)
        return rst**2


matrix = [
    '1 0 1 0 0'.split(),
    '1 0 1 1 1'.split(),
    '1 1 1 1 1'.split(),
    '1 0 0 1 0'.split(),
]
print(matrix)
print(Solution().maximalSquare(matrix))
