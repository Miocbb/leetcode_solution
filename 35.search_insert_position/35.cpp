
#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
    // O(n)
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return 0;

        for (int i = -1; i < size; ++i) {
            if (i == -1) {
                if (target <= nums[0])
                    return 0;
            } else if (i == size - 1) {
                if (target > nums[i])
                    return size;
            } else {
                if (target > nums[i] && target <= nums[i + 1])
                    return i + 1;
            }
        }

        return 0;
    }

    // O(log n): binary search
    int searchInsert_2(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (target <= nums[0])
            return 0;
        else if (target > nums[size - 1])
            return size;
        else if (target == nums[size - 1])
            return size - 1;

        int left = 0;
        int right = size - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] < target)
                left = mid;
            else if (target < nums[mid])
                right = mid;
        }
        return right;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int val = 4;

    Solution solver;
    int idx = solver.searchInsert_2(nums, val);
    std::cout << idx << std::endl;
}
