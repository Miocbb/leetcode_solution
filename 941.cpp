#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        /**
         * Intuitive solution:
         * scan over the whole array.
         * 1. find the first encountered peak.
         * 2. start from the found peak to verify if it is a real peak.
         *
         * To easily describe the trend of the array,
         * calculate the delta value.
         */
        int n = A.size();
        if (n < 3)
            return false;
        for (int i = 0; i < n-1; i++) {
            A[i] = A[i + 1] - A[i];
        }

        int peak_idx = -1;
        for (int i = 0; i < n-1; i++) {
            if (A[i] <= 0) {
                peak_idx = i;
                break;
            }
        }
        if (peak_idx == -1) {
            return false;
        }
        for (int i = peak_idx; i < n-1; i++) {
            if (A[i] >=0)
                return false;
        }
        if (peak_idx == 0) {
            return false;
        }
        return true;
    }
};

int main()
{
    vector<int> A = {2, 1};
    A = {2, 2, 2};
    A = {2, 3, 2};
    A = {2, 3, 3};
    A = {0, 3, 2, 1};
    A = {3, 2, 1};
    Solution solver;
    show_vec(A);
    bool rst = solver.validMountainArray(A);
    std::cout << "Problem 985: \n" << rst;
}
