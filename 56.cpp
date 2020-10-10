
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) { return a[0] <= b[0]; }

  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        std::sort(intervals.begin(), intervals.end(), cmp);
        // for (auto x: intervals)
        //    std::cout << "[" << x[0] << "," << x[1] << "],";
        vector<vector<int>> rst;
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (rst.empty() || rst.back()[1] < intervals[i][0])
                rst.push_back(intervals[i]);
            else {
                rst.back()[1] = std::max(intervals[i][1], rst.back()[1]);
            }
            std::cout << i << ": " << std::endl;
            show(rst);
        }
        return rst;
    }

    void show(vector<vector<int>> &intervals) const
    {
        for (auto x : intervals)
            std::cout << "[" << x[0] << "," << x[1] << "],";
        std::cout << std::endl;
    }
};

int main(int argc, const char **argv)
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    grid = {{1, 4}, {1, 5}};
    auto t = Solution().merge(grid);
    Solution().show(t);
    return 0;
}