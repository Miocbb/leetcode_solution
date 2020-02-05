/**
 * Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst(2);
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] == target) {
                    rst[0] = i;
                    rst[1] = j;
                }
            }
        }
        return rst;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    Solution solver;
    auto rst = solver.twoSum(nums, target);
    for (auto i : rst) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
