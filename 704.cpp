#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t l = 0;
        size_t r = nums.size() - 1;
        size_t size = nums.size();
        if (size == 0) return -1;
        if (size == 1) return (nums[0] == target ? 0 : -1);
        if (size == 2) {
            if (nums[0] == target) return 0;
            else if (nums[1] == target) return 1;
            else return -1;
        }
        while (r - l > 1) {
            size_t m = (r + l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m;
            else
                l = m;
        }
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
};


int main()
{
    Solution solution;
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    std::cout << solution.search(a, 13);
}
