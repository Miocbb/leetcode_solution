#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
public:
    /**
     * 1. The brutal force.
     * Check all the combinations of three numbers in the list.
     * This will be O(N^3).
     *
     * 2. Use the sorted array properties.
     * First we sort the array. The first loop is used to traverse all
     * array elements. Then we only needs to find all the pairs in the
     * rest of array (starting from the current number to the end) that
     * gives the summation to be negative of current number. Since the
     * array now is sorted, completion of this task will only need O(N)
     * time.
     * The overall time complexity is O(N^2).
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t size = nums.size();
        vector<vector<int>> rst;
        if (size < 3) return rst;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < size - 2; ++i) {
            if (nums[i] > 0) return rst;
            // always start from the first unique number to avoid duplicated results.
            if (i == 0 || i > 0 && nums[i] != nums[i-1]) {
                int j = i + 1;
                int k = size - 1;
                while (j < k) {
                    int target = nums[j] + nums[k] + nums[i];
                    if (target == 0) {
                        int left = nums[j];
                        int right = nums[k];
                        vector<int> t = {nums[i], nums[j], nums[k]};
                        rst.push_back(t);
                        while (j < size && nums[j] == left) j++;
                        while (k >= 0 && nums[k] == right) k--;
                    } else if (target < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return rst;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    nums = {0, 0, 0};
    Solution solver;
    auto rst = solver.threeSum(nums);
    std::cout << "answer:\n";
    for (auto i : rst) {
        for (auto ele : i) {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }

}
