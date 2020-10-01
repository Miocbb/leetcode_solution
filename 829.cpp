#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    bool is_int(double a) {
        return (int) a == a;
    }
    int consecutiveNumbersSum(int N) {

        int ans = 0;
        for (double k = 1; k <= std::sqrt(2 * N); ++k) {
            double x = N / k - (k + 1) / 2;
            if (is_int(x) && x >= 0) {
                ans++;
            }
        }
        return ans;
    }
};


int main(int argc, const char** argv) {
    Solution s;
    std::cout << s.consecutiveNumbersSum(9);
    return 0;
}
