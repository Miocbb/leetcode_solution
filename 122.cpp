#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0)
            return 0;
        int max = 0;
        bool found_valley = false;
        int valley = -1;
        int peak = -1;
        for (int i = 0; i < size; ++i) {
            if (! found_valley) {
                if (i == size - 1)
                    break;
                if (prices[i+1] > prices[i]) {
                    valley = prices[i];
                    found_valley = true;
                }
            } else {
                if (! (i != size - 1 && prices[i+1] > prices[i])) {
                    peak = prices[i];
                    max += peak - valley;
                    found_valley = false;
                }
            }
            //std::cout << "i=" << i << "v=" << valley << "p=" << peak << std::endl;
        }
        return std::max(0, max);
    }
};

int main()
{
    vector<int> nums = {7, 1,5,3,6,4};
    //nums = {1, 2, 3, 4, 5};
    //nums = {1, 2};

    Solution solver;
    int profit = solver.maxProfit(nums);
    std::cout << profit << std::endl;
}
