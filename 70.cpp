#include <iostream>
#include <vector>

using std::vector;

/**
 * Define dp[n] is the number of ways to climb n stairs. The DP states
 * relation is
 * dp[n] = 2 * dp[n-2] + (df[n-1] - df[n-2]);
 * starting from n-2 stairs:
 * (1) n stairs: n-2 stairs + 1 stair + 1 stair.
 * (2) n stairs: n-2 stairs + 2 stair.
 * starting from n-1 stairs:
 * The ways of getting to n-1 stairs NOT from n-2 stairs + 1 stair (other cases
 * not included in cases (1)) is (ways to n-1 stairs - ways to n-2 stairs). So
 * we also need to include following cases
 * n stairs: (ways to n-1 stairs - ways to n-2 stairs) + 1 steps.
 *
 * dp[1] = 1;
 * dp[2] = 1;
 *
 * This is like a Fibonacci number problem.
 */

class Solution {
public:
    int climbStairs(int n) {
        size_t dp0 = 1;
        size_t dp1 = 2;
        if (n == 1) return dp0;
        if (n == 2) return dp1;
        size_t rst = 0;
        for (size_t i = 3; i <= n; ++i) {
            rst = dp0 + dp1;
            dp0 = dp1;
            dp1 = rst;
        }
        return rst;
    }
};


int main()
{
    Solution solution;
    std::cout << solution.climbStairs(3) << std::endl;
    std::cout << solution.climbStairs(4) << std::endl;
    std::cout << solution.climbStairs(5) << std::endl;
    std::cout << solution.climbStairs(6) << std::endl;
}
