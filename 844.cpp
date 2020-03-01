#include<iostream>
#include <string>
#include <vector>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
  public:
    /**
     * Time complexity: O(N);
     * Space complexity: O(N);
     */
    bool rst(string &s, string &t)
    {
        stack<char> s0;
        stack<char> t0;
        for (auto i : s) {
            if (i == '#') {
                if (!s0.empty()) s0.pop();
            } else {
                s0.push(i);
            }
        }
        for (auto i : t) {
            if (i == '#') {
                if (!t0.empty()) t0.pop();
            } else {
                t0.push(i);
            }
        }

        return s0 == t0;
    }
};

int main()
{
    string s{"a#c"};
    string t{"b"};
    Solution solution;
    std::cout << solution.rst(s, t) << std::endl;
}
