#ifndef __LEETCODE_HELPER_H__
#define __LEETCODE_HELPER_H__

#include <vector>
#include <iostream>

inline void show_vec(std::vector<int>& nums)
{
    for (auto i : nums) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

#endif // __LEETCODE_HELPER_H__
