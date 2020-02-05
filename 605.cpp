/**
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not.
 * However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty),
 * and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * Note:
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 */

#include <vector>
#include <iostream>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // walk through the whole flowerbed to count the available plots.
        // Time complexity: O(n)
        // Space complexity: O(1)

        int l = flowerbed.size();
        int count = 0;
        // find the first plot that has flower planted.
        int first = -1;
        for (int i = 0; i < l; ++i) {
            if (flowerbed[i] == 1) {
                first = i;
                break;
            }
        }
        // empty bed: compare the maximum number of flower with input.
        if (first == -1)
            return (l + 1) / 2 >= n;

        // count from first position to left.
        int i = first;
        while (i >= 0) {
            i = i - 2;
            if (i >= 0 ) {
                if (flowerbed[i] == 1)
                    continue;
                int next = i - 1;
                if (next >= 0) {
                    if (flowerbed[next] != 1)
                        count++;
                    else
                        i = next;
                } else {
                    count++;
                }
            }
        }
        // count from first to right.
        i = first;
        while (i < l) {
            i = i + 2;
            if (i < l) {
                if (flowerbed[i] == 1)
                    continue;
                int next = i + 1;
                if (next < l) {
                    if (flowerbed[next] != 1)
                        count++;
                    else
                        i = next;
                } else {
                    count++;
                }
            }
        }
        return count >= n;
    }

    bool check_left(vector<int>& flowerbed, int i, int l) {
        return (i == 0 || flowerbed[i - 1] != 1);
    }

    bool check_right(vector<int>& flowerbed, int i, int l) {
        return (i != l || flowerbed[i + 1] != 1);
    }

    // walk through the whole array. At each position, check if a flower can be
    // planted and count the number of available positions.
    bool canPlaceFlowers_2(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        int count = 0;
        for (int i = 0; i < l; ++i) {
            if (flowerbed[i] == 0 && check_left(flowerbed, i, l) && check_right(flowerbed, i, l)) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};

int main()
{
    vector<int> nums = {1, 0, 0, 0, 1};
    nums = {1};
    nums = {0};
    int k = 1;
    std::cout << "original array:\n";
    show_vec(nums);
    Solution solver;
    std::cout << "Can place or not: " << solver.canPlaceFlowers(nums, k) << std::endl;
    std::cout << "Can place or not: " << solver.canPlaceFlowers_2(nums, k) << std::endl;
}
