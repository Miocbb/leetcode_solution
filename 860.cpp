#include<iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
  public:
    bool rst(vector<int> &bills)
    {
        /**
         * Since 5 bill is the most usefull one. So always try to save 5 bills
         * when you make a change. Use 10 bills as more as you can.
         */
        size_t n_5 = 0;
        size_t n_10 = 0;
        size_t n_20 = 0;

        for (int i : bills) {
            if (i == 5) n_5++;
            else if (i == 10) {
                if (n_5 < 1) return false;
                else {
                    n_10++;
                    n_5--;
                }
            } else if (i == 20) {
                if (n_10 > 0 && n_5 > 0) {
                    n_10--;
                    n_5--;
                    n_20++;
                } else if (n_10 == 0 && n_5 >= 3) {
                    n_5 -= 3;
                    n_20++;
                } else return false;
            } else {
                std::cout << "error." << std::endl;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> a= {5,5,5,10,20};
    a= {10, 10};
    Solution solution;
    std::cout << solution.rst(a) << std::endl;
}
