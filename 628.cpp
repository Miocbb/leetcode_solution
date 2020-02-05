/**
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 * Output: 6
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4]
 * Output: 24
 *
 *
 * Note:
 *
 * The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    // product = a * b * c.
    // 3 conditions:
    //    a  b  c
    // 1. +  +  +: all positive, choose last three.
    // 2. +  +  -: when there is only one negative number, if size == 3, chose these three.
    //              if size > 3, choose the last three.
    // 3. +  -  -: when there are equal or more than two negative numbers,
    //             choose the first two and the last one.
    // 4. -  -  -: there are all negative numbers, pick the last three numbers.
    // sort the array first.
    // a,
    int maximumProduct(vector<int>& nums) {
        int l = nums.size();
        std::sort(nums.begin(), nums.end());
        int max1 = nums[l-1] * nums[l-2] * nums[l-3];
        if (nums[0] < 0 && nums[1] < 0) {
            return std::max(max1, nums[0] * nums[1] * nums[l-1]);
        } else
            return max1;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    nums =  {-1, -2, 3, 4};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    std::cout << "max: " << solver.maximumProduct(nums) << std::endl;
}
