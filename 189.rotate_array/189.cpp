/* Given an array, rotate the array to the right by k steps, where k is non-negative.
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * Example 2:
 *
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * Note:
 *
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 */
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;


void show_vec(vector<int>& nums)
{
    for (auto i : nums) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

class Solution {
public:
    // wrong solution
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        int i0 = 0;
        int j = (i0 + k) % l;
        int T = nums[i0];
        int step = 0;
        while (j != i0) {
            int t = nums[j];
            nums[j] = T;
            T = t;
            j = (j + k) % l;
            std::cout << "rotation step: " << step << std::endl;
            show_vec(nums);
            step++;
        }
        nums[i0] = T;
        show_vec(nums);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    //nums = {1, 2};
    int k = 2;
    std::cout << "original array:\n";
    show_vec(nums);

    Solution solver;
    solver.rotate(nums, k);
    std::cout << "after rotation:\n";
    show_vec(nums);
}
