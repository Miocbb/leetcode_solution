#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> rst = {lfind(nums, target), rfind(nums, target)};
        return rst;
    }

    int lfind(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l != r) {
            // m is always smaller than r at least by one.
            // m could equal to l.
            int m = (l + r) / 2;
            // The equal sign makes the matched number still have chance to
            // move left to the left-most matched number.
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
            // make both l and r change at least 1. So that termination
            // condition can reach.
        }
        return (nums[r] == target) ? r : -1;
    }

    int rfind(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int l = 0;
        int r = nums.size() - 1;
        while (r != l) {
            // m is always bigger than l at least by one.
            // m could equal to r.
            int m = (l + r + 1) / 2;
            // The equal sign makes the matched number still have chance to
            // move right to the right-most matched number.
            if (nums[m] <= target)
                l = m;
            else
                r = m - 1;
            // make both l and r change at least 1. So that termination
            // condition can reach.
        }
        return (nums[l] == target) ? l : -1;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // nums = {-1, 2, 1, -4};
    // nums = {0, 0, 0, 1};
    nums = {2, 2};
    int target = 2;
    Solution solver;
    auto rst = solver.searchRange(nums, target);
    std::cout << "answer: " << solver.lfind(nums, target) << std::endl;
    std::cout << "answer: " << solver.rfind(nums, target) << std::endl;
    // std::cout << "answer2 : " << solver.threeSumClosest_2(nums, target);
}
