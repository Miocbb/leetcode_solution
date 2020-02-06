#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    vector<int> sortArrayByParityII (vector<int>& A) {
        /**
         * Time complexity: O(n).
         * Space complexity: O(1).
         */
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 != 0) {
                while(A[j] % 2 == 1) {
                    j += 2;
                }

                // Now found a A[j] that is even.
                // and A[i] is odd.
                // Just swap A[i] and A[j].
                int T = A[i];
                A[i] = A[j];
                A[j] = T;
            }
        }
        // After this for loop, all the even position is a even number. This
        // immediately make all the odd position stores the odd number.
        return A;
    }
};

int main()
{
    vector<int> A = {2, 1};
    A = {4, 2, 5, 7};
    Solution solver;
    show_vec(A);
    vector<int> rst = solver.sortArrayByParityII(A);
    std::cout << "Problem 985: \n";
    show_vec(rst);
}
