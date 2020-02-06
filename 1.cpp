#include <vector>
#include <iostream>
#include <unordered_map>
#include "./include/helper.h"
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
         * Brutal force:
         * Time complexity: O(n^2).
         * Space complexity: O(1).
         */
        vector<int> rst(2);
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] == target) {
                    rst[0] = i;
                    rst[1] = j;
                }
            }
        }
        return rst;
    }

    vector<int> twoSum_2(vector<int>& nums, int target) {
        /**
         * Use hash table.
         * key = nums[i], val = i;
         *
         * Time complexity: O(n)
         * Space complexity: O(n).
         */
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int rst_val = target - nums[i];
            auto map_element = umap.find(rst_val);
            std::cout << "Try i=" <<  i << ", nums=" << nums[i] << std::endl;
            if (map_element != umap.end() && map_element->second != i) {
                ans.push_back(i);
                ans.push_back(map_element->second);
                std::cout << "found.\n";
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    nums = {3, 2, 4};
    int target = 13;
    target = 6;

    std::cout << "Input: \n";
    show_vec(nums);

    Solution solver;
    auto rst = solver.twoSum(nums, target);
    std::cout << "algo1: \n";
    show_vec(rst);

    rst = solver.twoSum_2(nums, target);
    std::cout << "algo2: \n";
    show_vec(rst);
}
