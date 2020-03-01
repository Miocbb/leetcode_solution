#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m < x / m)
                l = m;
            else if (m > x / m)
                r = m;
            else
                return m;
        }
        return l;
    }
};


int main()
{
    Solution solution;
    std::cout << "sqrt(4)= " << solution.mySqrt(4) << std::endl;
    std::cout << "sqrt(100)= " << solution.mySqrt(100) << std::endl;
    std::cout << "sqrt(100)= " << solution.mySqrt(12) << std::endl;
}
