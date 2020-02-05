#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        /**
         * Understanding the way of decoding the array.
         * Read each element in the array from the left to right.
         * There are only two values for each element: 0 or 1.
         * When 0 is encountered, it has to be decoded as itself.
         * When 1 is encountered, it has to be decoded with its following element, no matter what
         * value the following element is.
         * Keep decoding in this way to reach the end. If the last decoded part is 0, then it is true.
         * Otherwise, it is false.
         */
        int n = bits.size();
        int i = 0;
        while (i < n) {
            if (bits[i] == 0) {
                if (i != n - 1)
                    i += 1;
                else
                    return true;
            }
            else if (bits[i] == 1)
                i += 2;
            std::cout << "i= " << i << std::endl;

            if (i == n-1)
                return true;
            else if (i == n-2 && bits[i] == 0)
                return true;
            else
                continue;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0};
    //nums = {0, 0, 0, 0};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    bool rst = solver.isOneBitCharacter(nums);
    std::cout << "status: " << rst << std::endl;
}
