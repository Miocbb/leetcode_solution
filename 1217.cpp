#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
  public:
    int rst(vector<int> &chips)
    {
        /**
         * For all the position, it is either an even or odd number.
         * According to the game rules, move left or right with 2 units pays
         * zero cost. So we can gather all chips on even position on position
         * `i` (i is an even position) for free. Similarly, we can gather all
         * chips on `i+1` position (i+1 is an odd position) for free.
         * Now clearly, the minimum cost of move all chips on the same position
         * is minimum between the number of chips on position `i` and position
         * `i+1`. In another word, the solution is
         * min(number of even positions, number of odd positions).
         *
         * Time complexity: O(n).
         * Space complexity: O(1).
         */
        size_t odd = 0;
        size_t even = 0;
        for (auto i : chips) {
            if (i % 2 == 0) ++even;
            else ++odd;
        }
        return std::min(odd, even);
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    a = {2, 2,2, 3, 3};
    Solution solution;
    std::cout << solution.rst(a) << std::endl;
}
