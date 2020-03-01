#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int rob(vector<int> &nums) {
        /**
         * DP:
         * Define f(n) is the maximum money we can get from the A[0:n].
         * The DP state relation is:
         * f(n) = max(f(n-2) + A[n], f(n-1))
         * f(1) = A[0]
         * f(2) = max(A[1], A[2])
         */
        size_t size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        int f1 = nums[0];
        int f2 = std::max(nums[0], nums[1]);
        int fn = f2;
        for (size_t i = 2; i < size; ++i) {
            fn = std::max(f1 + nums[i], f2);
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};


int main()
{
    vector<int> a = {1, 2, 3, 1};
    a = {2, 7, 9, 3, 1};
    Solution solution;
    std::cout << solution.rob(a) << std::endl;
}
