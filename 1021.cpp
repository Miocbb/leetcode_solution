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
     *
     * Walk along the whole string to find every sub-valid parentheses string.
     * Finding the sub-valid parentheses string can easily be achieved with the
     * help of stack data structure (see problem #20).
     */
    string rst(string &S)
    {
        //std::cout << "original S: " << S << std::endl;
        stack<char> s;
        for (size_t i = 0; i < S.size(); ++i) {
            char Si = S[i];
            if (s.empty()) {
                S[i] = '*'; // label the removed char.
            }
            if (Si == '(') {
                s.push(Si);
            } else if (Si == ')') {
                if (!s.empty()) {
                    s.pop();
                    if (s.empty()) {
                        S[i] = '*';
                    }
                } else {
                    std::cout << "error1: " << S << ", Si=" << Si << std::endl;
                }
            } else {
                std::cout << "error2: " << S << ", Si=" << Si << std::endl;
            }
        }
        //std::cout << "processed S: " << S << std::endl;
        // now get the processed string.
        string result(S.size(), '*');
        size_t n = 0;
        for (char i : S) {
            if (i != '*') {
                result[n] = i;
                n++;
            }
        }
        string r(result.begin(), result.begin() + n);
        return r;
    }
};

int main()
{
    string s = "(()())(())";
    Solution solution;
    std::cout << solution.rst(s) << std::endl;
}
