/**
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
 *
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 *
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * Example 2:
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one element.
 * Note: The n belongs to [1, 10,000].
 */

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    bool check(vector<int>& nums, int n) {
        if (n == 1) {
            return true;
        }
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }

    // brutal force: update each element, then check if the updated array is non-decreasing.
    // If no solution found, return false, otherwise, we can find a solution.
    // Time complexity: O(n2).
    // Space complexity: O(1).
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool status = false;
        for (int i = 0; i < n; ++i) {
            int copy = nums[i];
            if (i == 0) {
                nums[i] = std::numeric_limits<int>::min();
            } else if ( i == n-1) {
                nums[i] = std::numeric_limits<int>::max();
            } else {
                nums[i] = nums[i-1];    // make it non-decreasing.
            }
            if (check(nums, n)) {
                status = true;
                break;
            }
            nums[i] = copy;
        }
        return status;
    }
};

int main()
{
    vector<int> nums = {4, 2, 1};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    std::cout << "max: " << solver.checkPossibility(nums) << std::endl;
}
