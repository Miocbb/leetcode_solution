#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
  private:
    unordered_map<string, vector<int>> mem_;
    // Given a string, return all the possible results.
    // Meanwhile, save the results in memory.
    vector<int> & ways(string &str)
    {
        if (mem_.count(str)) {
            return mem_[str];
        }

        vector<int> rst;
        for (size_t i = 0; i < str.size(); ++i) {
            const char c = str[i];
            if (c == '+' || c == '-' || c == '*') {
                string substr_pre = str.substr(0, i);
                string substr_post = str.substr(i + 1);

                vector<int> &rst_pre = ways(substr_pre);
                vector<int> &rst_post = ways(substr_post);

                for (auto i : rst_pre) {
                    for (auto j : rst_post) {
                        int val = 0;
                        switch (c)
                        {
                            case '+': val = i + j; break;
                            case '-': val = i - j; break;
                            case '*': val = i * j; break;
                            default: break;
                        }
                        rst.push_back(val);
                    }
                }
            }
        }

        // the input string contains no operator, so it is a pure string of
        // number. convert it to int and save it to rst.
        if (rst.size() == 0) {
            rst.push_back(str.empty() ? 0 : atoi(str.c_str()));
        }
        mem_[str] = rst;
        return mem_[str];
    }

  public:
    vector<int> diffWaysToCompute(string input)
    {
        return ways(input);
    }
};

int main(int argc, const char **argv)
{
    auto rst = Solution().diffWaysToCompute("2-1-1");
    for (auto i : rst) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    rst = Solution().diffWaysToCompute("2*3-4*5");
    for (auto i : rst) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;
    std::set<int> s(rst.begin(), rst.end());
    rst.assign(s.begin(), s.end());
    for (auto i : rst) {
        std::cout << i << ", ";
    }
    std::cout << "\n" << rst.size();


    return 0;
}
