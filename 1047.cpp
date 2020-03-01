#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::string;
using std::stack;

class Solution {
  public:
    /**
     * Time complexity: O(N);
     * Space complexity: O(N);
     *
     * Walk along the whole string and do the duplicate-removal with stack.
     * Finally, we can just translate the string stored in stack back to string.
     */
    string rst(string &S)
    {
        stack<char> removed_str;
        for (char i : S) {
            if (!removed_str.empty()) {
                char top = removed_str.top();
                if (i == top) {
                    removed_str.pop();
                } else {
                    removed_str.push(i);
                }
            } else {
                removed_str.push(i);
            }
        }
        vector<char> t;
        while (!removed_str.empty())
        {
            t.push_back(removed_str.top());
            removed_str.pop();
        }
        std::reverse(t.begin(), t.end());

        string rst(t.begin(), t.end());
        return rst;
    }
};

int main()
{
    string s = "abbaca";
    Solution solution;
    std::cout << solution.rst(s) << std::endl;
}
