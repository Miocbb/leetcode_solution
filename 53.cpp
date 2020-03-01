#include <iostream>
#include <vector>

using std::vector;

/**
 * Define A(i, j) is the summation of array A[i:j]. Then the problem is defined
 * as find the solution max{A(i, j), i<=j}
 * The problem can be rewrite as finding the solution of
 * max{ (max{A(i, j0), i<=j0}), j0=1->n}.
 * Now we can use the dynamic programming to solve the problem.
 * Denote state DP[j0] = max{A(i, j0), i<=j0}. Then
 * DP[j0 + 1] = (DP[j0] > 0 ? DP[j0] + A[j0 + 1] : A[j0 + 1]).
 * The final solution of the original problem is max{DP[j0], j0=1->n}.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t size = nums.size();
        int dp = nums[0];
        int max = dp;
        for (size_t i = 1; i < size; ++i) {
            int dp_new = (dp > 0 ? dp + nums[i] : nums[i]);
            dp = dp_new;
            max = (dp_new > max ? dp_new : max);
        }
        return max;
    }
};


int main()
{
    Solution solution;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    a = {1};
    std::cout << solution.maxSubArray(a);
}
