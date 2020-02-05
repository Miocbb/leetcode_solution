#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& bits) {
        /**
         * At each decision to take the next step, take
         */
    }
};

int main()
{
    vector<int> nums = {1, 0, 0};
    //nums = {0, 0, 0, 0};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    int rst = solver.minCostClimbingStairs(nums);
    std::cout << "status: " << rst << std::endl;
}
