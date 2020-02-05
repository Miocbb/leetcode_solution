#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        /**
         * intuitive solution:
         * 1. find the largest number.
         * 2. check each element in the rest. If we can find one element that is
         * greater than 2 * max_number, return -1. Otherwise, return the index for the largest number.
         */
        int n = nums.size();
        if (n == 0)
            return 0;

        int max_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != max_idx && 2 * nums[i] > nums[max_idx])
                return -1;
        }
        return max_idx;
    }
};

int main()
{
    vector<int> nums = {3, 6, 1, 0};
    Solution solver;
    int idx = solver.dominantIndex(nums);
    std::cout << "Problem 747: " << idx << std::endl;
}
