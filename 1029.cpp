#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
  public:
    int rst(vector<vector<int>> &cost)
    {
        /**
         * For each person, he/she will either go to city A or city B.
         * define diff[i] = cost[i][A] - cost[i][B], that is the cost difference
         * of let i-th person to city A and city B.
         * Sort the people by the difference from smallest to largest.
         * Intuitively, to maximize the saving, you always choose person one by
         * one from the unassigned ones that can save the most.
         * So the first half people in the sorted order assigned to city A is
         * the solution.
         *
         * Proof:
         * Now suppose we want to switch any person i from city A to B. As
         * required by the problem, we will have to switch another person j from
         * city B back to A.
         * Say cost_origin is the cost before switch. After the switch, the
         * new cost cost_new is
         * cost_new = cost_origin - diff[i] + diff[j].
         * Since person i is in city A zone, and person j is in city B zone,
         * we have diff[i] < diff[j].
         * So cost_new = cost_origin + (diff[j] - diff[i]) > cost_origin.
         * That is switch any two person in the original schedule will increase
         * the cost. End of proof.
         */
        std::sort(begin(cost), end(cost), [](vector<int> &v1, vector<int> &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });
        int res = 0;
        for (auto i = 0; i < cost.size() / 2; ++i) {
            res += cost[i][0] + cost[i + cost.size() / 2][1];
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> a = {{10,20},{30,200},{400,50},{30,20}};
    Solution solution;
    std::cout << solution.rst(a) << std::endl;
}
