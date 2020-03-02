#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
  public:
    int rst(string &s)
    {
        /**
         * Walk along the string char by char. You keep track of the char you
         * have visited. Once you find a balanced string, you make the split
         * immediately. Using this strategy, you can always maximize the number
         * of balanced sub-strings.
         *
         * We can count the number of `R` and `L`. Once we see a `R`, count is
         * increased by one. Once we see a `L`, count is decread by one. Once
         * we see count is zero, we find a balanced sub-string.
         *
         * Time complexity: O(N).
         * Space complexity: O(1).
         */
        size_t count = 0;
        size_t rst = 0;
        for (auto i : s) {
            if (i == 'R') ++count;
            else --count;
            if (count == 0) ++rst;
        }
        return rst;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    string s = "RLRRLLRLRL";
    a = {2, 2,2, 3, 3};
    Solution solution;
    std::cout << solution.rst(s) << std::endl;
}
