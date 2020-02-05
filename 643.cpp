/**
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 *
 *Example 1:
 *
 *Input: [1,12,-5,-6,50,3], k = 4
 *Output: 12.75
 *Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 *Note:
 *
 *1 <= k <= n <= 30,000.
 *Elements of the given array will be in the range [-10,000, 10,000].
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    // slice window method.
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double a1 = 0;
        double a2 = 0;
        double rst = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (i == 0) {
                double sum = 0;
                for (int j = 0; j < k; j++) {
                    sum += nums[j];
                }
                rst = a1 = a2 = sum/k;
            } else {
                a2 = a1 + (nums[i + k - 1] - nums[i - 1])/(double)k;
                rst = std::max(rst, a2);
            }
            a1 = a2;
            //std::cout << "a1=" << a1 << ", a2=" << a2 << std::endl;
        }
        return rst;
    }
};

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    nums = {5};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    std::cout << "max: " << solver.findMaxAverage(nums, k) << std::endl;
}
