#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        /**
         * AX: array form of number X.
         * AK: array form of number K.
         * AXK: array form of number X + K.
         * We have the following relation:
         * AXK[i-1] = ( (AX[i-1] + AK[i-1]) % 10 + (AX[i] + AK[i]) / 10 ) % 10
         *
         * 1. convert number K into AK.
         * 2. use above relation to calculate AXK.
         *
         * Time complexity: O(max(AX.size, AK.size))
         *
         * In implementation, this will be tedious.
         */


        /**
         * Another way that is easier to implement.
         * Do digital-wise addition between number K and A[i] from A[n-1] to A[0].
         * After each addition, cut off the used digits in A and number K.
         * For example:
         *
         * K = 123,
         * A = [9, 1, 5].
         *
         * 1. K = 123; K = K + A[2] = 128; AXK[0] = K % 10 = 8;
         * 2. K = K/10 = 128/10 = 12; K = K + A[1] = 12 + 1 = 13; AXK[1] = K % 10 = 3;
         * 3. K = K/10 = 13/10 = 1; K = K + A[2] = 1 + 9 = 10; AXK[2] = K % 10 = 0;
         * 4. K = K/10 = 10/10 = 1; K = K; AXK[3] = K % 10 = 1;
         * 5. K = K/10 = 1/10 = 0; exit.
         * Another way to illustrate the above procedure is:
         * 123 + 915: -> [9, 1, 5 + 123] -> [9, 1, 128] -> [9, 1 + 12, 8] -> [9, 13, 8] -> [9 + 1, 3, 8] -> [10, 3, 8] -> [1, 0, 3, 8].
         */
        vector<int> AXK;
        int i = A.size() - 1;
        while (K != 0 || i >= 0) {
            if (i >= 0) {
                K += A[i];
                i--;
            }
            AXK.push_back(K % 10);
            K /= 10;
        }
        std::reverse(AXK.begin(), AXK.end());
        return AXK;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0, 0, 1, 0 , 1};
    nums = {6, 5, 4,4};
    int K = 1;
    K = 6;
    K = 10000;
    std::cout << "original: " << std::endl;
    show_vec(nums);
    Solution solver;
    vector<int> rst = solver.addToArrayForm(nums, K);
    std::cout << "Problem 989: \n";
    show_vec(rst);
}
