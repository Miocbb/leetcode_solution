#include<iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
  public:
    int rst(vector<int> &cost)
    {
        /**
         * Define f(n) is the minimum cost paid to reach to stair n.
         * Then f(n) = min(f(n-1) + cost[n-1], f(n-2) + cost[n-2]);
         */
        size_t size = cost.size();
        if (size <= 1) return size * cost[0];
        int f1 = 0; // zero cost to reach 1st stair.
        int f2 = 0; // zero cost to reach 2nd stair.
        int fn = 0;
        for (size_t i = 2; i <= size; ++i) {
            fn = std::min(f2 + cost[i-1], f1 + cost[i-2]);
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};

int main()
{
    vector<int> a= {1, 2,3};
    a = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    a = {0, 0, 1, 1};
    Solution solution;
    std::cout << solution.rst(a) << std::endl;
}
