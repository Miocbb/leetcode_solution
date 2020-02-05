#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        /**
         * intuitive solution:
         * slice the seats based on seated persons and the boundary of the seats.
         * calculate the maximum distance in each sliced section and take the maximum.
         */
        int i = 0;
        int j = 0;
        int n = seats.size();
        int dist = 1;   // 1 is always a candidate.
        for (int j = 0; j < n; ++j) {
            int d = 1;
            if (seats[i] == 0 && seats[j] == 1) {
                d = j;
                i = j;
            } else if (seats[i] == 1 && seats[j] == 1) {
                d = (j - i) / 2;
                i = j;
            } else if (j == n-1 && seats[i] == 1) {
                d = n - i - 1;
                i = j;
            } else {
                continue;
            }

            if (d > dist) {
                dist = d;
            }
        }
        return dist;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0, 0, 1, 0 , 1};
    nums = {1, 0 , 0, 0};
    nums = {1, 0 };
    nums = {0, 1};
    nums = {1, 0 , 0, 1};
    std::cout << "original seats: " << std::endl;
    show_vec(nums);
    Solution solver;
    int dist = solver.maxDistToClosest(nums);
    std::cout << "Problem 849: " << dist << std::endl;
}
