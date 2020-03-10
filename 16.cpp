#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
  public:
    /**
     * 1. Sort the input array: note the sorted input array as A. O(NlogN) time.
     * 2. Use an auxiliary array B: B[i] = A[i] + A[i+1] + A[i+2]; O(N) time,
     * O(N) space
     * 3. Using binary search to find the insertion position of target in B
     * array. Note the position as idx. We have B[idx] <= target <= B[idx+1].
     * O(logN) time.
     * 4. the closet solution is in a set {A[idx], A[idx+1], A[idx+2],
     * A[idx+3]}.
     *
     * Wrong!
     */
    int threeSumClosest_2(vector<int> &nums, int target)
    {
        size_t size = nums.size();
        int rst = 0;
        bool is_first = true;
        if (size < 3)
            throw "Error";

        vector<int> B(size - 2);
        for (size_t i = 0; i < B.size(); ++i) {
            B[i] = nums[i] + nums[i + 1] + nums[i + 2];
        }

        if (target <= B[0])
            return B[0];
        else if (target >= B[size - 2])
            return B[size - 2];

        int l = 0;
        int r = B.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (B[m] > target)
                r = m;
            else if (B[m] < target)
                l = m;
            else
                return target;
        }

        vector<int> C = {nums[l], nums[l + 1], nums[l + 2], nums[l + 3]};
        vector<int> D = {C[0] + C[1] + C[2], C[0] + C[1] + C[3],
                         C[0] + C[2] + C[3], C[1] + C[2] + C[3]};
        int diff = std::numeric_limits<int>::max();
        for (int i = 0; i < 4; ++i) {
            int curr_diff = std::abs(D[i] - target);
            if (curr_diff < diff) {
                curr_diff = diff;
                rst = D[i];
            }
        }
        return rst;
    }

    /**
     * 1. The brutal force.
     * Check all the combinations of three numbers in the list.
     * This will be O(N^3).
     *
     * 2. Use the sorted array properties.
     * First we sort the array. The first loop is used to traverse all
     * array elements. Then we only needs to find all the pairs in the
     * rest of array (starting from the current number to the end) that
     * gives the closest summation to the target number.
     * Following the Problem 15 thinking, the overall time complexity is O(N^2).
     */
    int threeSumClosest(vector<int> &nums, int target)
    {
        size_t size = nums.size();
        int rst = 0;
        bool is_first = true;
        if (size < 3)
            throw "Error";

        auto p_head = nums.begin();
        auto p_tail = nums.end();
        sort(p_head, p_tail);

        int largest = p_tail[-1] + p_tail[-2] + p_tail[-3];
        if (target >= largest)
            return largest;
        int smallest = p_head[0] + p_head[1] + p_head[2];
        if (target <= smallest)
            return smallest;

        for (size_t i = 0; i < size - 2; ++i) {
            // always start from the first unique number to avoid duplicated
            // results.
            if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
                int j = i + 1;
                int k = size - 1;
                // note the head pointer is moving towards tail; and the tail
                // pointer is moving towards head.
                // !Note: doing so the sum is not always decreasing.
                if (i == 0)
                    rst = nums[i] + nums[j] + nums[k];
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == target) {
                        return target;
                    } else if (std::abs(sum - target) <
                               std::abs(rst - target)) {
                        rst = sum;
                    }
                    if (sum < target)
                        j++;
                    else
                        k--;
                }
            }
        }
        return rst;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // nums = {-1, 2, 1, -4};
    // nums = {0, 0, 0, 1};
    nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    nums = {-55, -24, -18, -11, -7, -3, 4, 5, 6, 9, 11, 23, 33};
    nums = {1,6,9,14,16,70};
    int target = 81;
    Solution solver;
    auto rst = solver.threeSumClosest(nums, target);
    std::cout << "answer: " << rst << std::endl;
    // std::cout << "answer2 : " << solver.threeSumClosest_2(nums, target);
}
