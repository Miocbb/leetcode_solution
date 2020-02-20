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
    int firstUniqChar(string s) {
        vector<int> count(26);
        for (auto i : s) {
            count[i - 'a'] += 1;
        }
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (count[idx] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    string s = "leetcode";

    std::cout << "Input: " << s << std::endl;;

    Solution solver;
    auto rst = solver.firstUniqChar(s);
    std::cout << "algo1: " << rst << std::endl;
}
