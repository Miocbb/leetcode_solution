#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    bool isSubsequence(string &s, string &t) {
        size_t i = -1;
        for (auto si : s) {
            for (i++; i < t.size(); ++i) {
                if (t[i] == si) {
                    break;
                }
            }
            if (i >= t.size()) return false;
        }
        return true;
    }
};


int main()
{
    string s = "aac";
    string t = "ahagdc";
    Solution solution;
    std::cout << solution.isSubsequence(s, t) << std::endl;
}
