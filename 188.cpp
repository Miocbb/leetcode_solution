#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <numeric>
#include <cmath>

using std::vector;

class Solution {
  private:
    vector<int> profit_;

    int find_buy_in(vector<int> &prices, int start) {
        for (; start < prices.size(); ++start) {
            if (start != prices.size() - 1 && prices[start + 1] > prices[start]) {
                break;
            }
        }
        return start;
    }

    int find_sell_out(vector<int> &prices, int start) {
        for (; start < prices.size(); ++start) {
            if (start == prices.size() - 1)
                return start;
            else if (prices[start + 1] < prices[start]) {
                break;
            }
        }
        return start;
    }


  public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int buy = 0;
        int sell = 0;

        for (size_t i = 0; i < prices.size();) {
            int buy = find_buy_in(prices, i);
            int sell = find_sell_out(prices, buy);
            if (buy != sell) {
                int pro = prices[sell] - prices[buy];
                profit_.push_back(pro);
                std::cout << "buy: " << prices[buy] << " sell: " << prices[sell] << std::endl;
            }
            i = sell;
        }
        std::sort(profit_.begin(), profit_.end());
        for (auto i: profit_) {
            std::cout << i << ", ";
        }
        return std::accumulate(profit_.end() - std::min(k, int(profit_.size())), profit_.end(), 0);
    }
};

int main(int argc, const char **argv) {
    vector<int> inp {2, 4, 1};
    inp = {3,2,6,5,0,3};
    inp = {1,2,4,2,5,7,2,4,9,0};
    std::cout << Solution().maxProfit(2, inp);
    return 0;
}
