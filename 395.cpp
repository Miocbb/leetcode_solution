#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> dp(s.size(), 0);
        for (auto x : dp) {
            std::cout << x << " ";
        }
        int rst = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            if (dp[i - 1] == 0) {
                bool flag = true;
                for (size_t n = 0; n < k; ++n) {
                    int idx = i - n;
                    if (s[idx] != s[i])
                        flag = false;
                }
                if (flag) {
                    dp[i] = k;
                    rst = std::max(k, rst);
                }
            } else {
                string subs = s.substr(i - dp[i-1], dp[i-1]);
                if (subs.find(s[i]) != std::string::npos)
                    dp[i] = dp[i-1] + 1;
                    rst = std::max(rst, dp[i]);
            }

            std::cout << "\ni=" << i << " ";
            for (auto x : dp)
                std::cout << x << " ";
            std::cout << "\n";
        
        }
        return rst;
    }
};

int main(int argc, const char** argv) {
    string s = "aaabb";
    s = "ababbc";
    s = "ababbc";
    std::cout << Solution().longestSubstring(s, 2);
    return 0;
}