/**
 * Given an array nums and a value val, remove all instances of
 * that value in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 *
 * Example 1:
 *
 * Given nums = [3,2,2,3], val = 3,
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
 *
 * It doesn't matter what you leave beyond the returned length.
 * Example 2:
 *
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 *
 * Your function should return length = 5, with the first five elements of nums containing
 * 0, 1, 3, 0, and 4.
 *
 * Note that the order of those five elements can be arbitrary.
 *
 * It doesn't matter what values are set beyond the returned length.
 */


#include <vector>
#include <iostream>

using std::vector;

class Solution {
    public:
    void show_vec(vector<int>& nums)
    {
        for (int i : nums) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }

    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();

        if (size == 1) {
            if (nums[0] == val)
                return 0;
        } else if (size == 0) {
            return 0;
        }

        int head = 0;
        int tail = size -1;
        int count = 0;
        while(head <= tail) {
            if (nums[head] != val) {
                count++;
            } else {
                // find the first element that is not equal to val
                // from the tail to swap with found val in the beginning.
                bool is_found = false;
                while (head < tail) {
                    if (nums[tail] != val) {
                        is_found = true;
                        break;
                    } else {
                        --tail;
                    }
                }

                // swap head and tail
                if (is_found) {
                    int t = nums[head];
                    nums[head] = nums[tail];
                    nums[tail] = t;
                    tail--;
                    count++;
                    //show_vec(nums);
                } else {
                    return count;
                }
            }
            //std::cout << head << "," << tail << std::endl;
            head++;
        }
        return count;
    }


    int removeElement_2(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size() - 1;
        //int count = 0;
        while (i <= n) {
            //count++;
            if (nums[i] != val) {
                i++;
            } else {
                nums[i] = nums[n];
                n--;
            }
        }
        //std::cout << "count = " << count << std::endl;
        return n + 1;
    }
};

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution solver;
    int new_length = solver.removeElement_2(nums, val);
    std::cout << "New length of array is: " << new_length << std::endl;
    for (int i = 0; i < new_length; ++i) {
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}
