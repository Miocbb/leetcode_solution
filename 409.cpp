#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include "./include/helper.h"
using std::vector;
using std::unordered_map;
using std::string;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(58);
        for (auto i : s) {
            count[i - 'A'] += 1;
        }
        int rst = 0;
        int max_odd_count = 0;
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'A';
            rst += count[idx] / 2 * 2;
            count[idx] = 0;
            //std::cout << rst << std::endl;
        }
        //show_vec(count);
        if (rst < s.length())
            rst++;
        return rst;
    }
};

int main()
{
    string s = "abccccdd";

    std::cout << "Input: " << s << std::endl;;

    Solution solver;
    auto rst = solver.longestPalindrome(s);
    std::cout << "algo1: " << rst << std::endl;
}
