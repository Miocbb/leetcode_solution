#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

class Solution {
public:
    // Brutal force:
    // enumerate all the combinations of buy-sell, O(n^2).
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int profit = prices[j] - prices[i];
                max = std::max(max, profit);
                //std::cout << max << "," << profit << std::endl;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> nums = {7, 1,5,3,6,4};
    nums = {7,6,4,3,1};

    Solution solver;
    int profit = solver.maxProfit(nums);
    std::cout << profit << std::endl;
}
