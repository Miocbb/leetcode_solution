#include<iostream>
#include <string>
#include <vector>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
  public:
    bool rst(string &str)
    {
        /**
         * Using stack data structure can easily solve the problem.
         */
        stack<char> s;
        for (auto i : str) {
            if (i == '(' || i == '{' || i == '[')
                s.push(i);
            else {
                if (s.empty()) return false;
                else {
                    auto top = s.top();
                    if (i == ')' && top != '(') return false;
                    else if (i == '}' && top != '{') return false;
                    else if (i == ']' && top != '[') return false;
                    else s.pop();
                }
            }
        }
        return s.empty();
    }
};

int main()
{
    string s{"()()"};
    s = "(())";
    s = "]";
    Solution solution;
    std::cout << solution.rst(s) << std::endl;
}
