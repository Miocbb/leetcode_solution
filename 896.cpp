#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        /**
         * intuitive solution:
         * 1. Using the A[0] and A[n-1] to tell the relation: <= or >.
         * 2. based on the found relation to verify the relation.
         */
        int n = A.size();
        if (n == 0)
            return true;

        if (A[0] <= A[n-1]) {
            for (int i = 0; i < n-1; ++i) {
                if (A[i] > A[i+1])
                    return false;
            }
            return true;
        } else {
            for (int i = 0; i < n-1; ++i) {
                if (A[i] < A[i+1])
                    return false;
            }
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0, 0, 1, 0 , 1};
    nums = {6, 5, 4,4};
    std::cout << "original: " << std::endl;
    show_vec(nums);
    Solution solver;
    bool rst = solver.isMonotonic(nums);
    std::cout << "Problem 896: " << rst << std::endl;
}
