#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include "./include/helper.h"
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        /**
         * Two pointers solution:
         */
        int i = 0;
        int j = 0;
        int n = S.length();
        vector<vector<int>> rst;
        for (j = 0; j < n; ++j) {
            if (S[j] != S[i]) {
                if (j - i >= 3) {
                    vector<int> t = {i, j - 1};
                    rst.push_back(t);
                    std::cout << "found 3: i=" << i << ", j=" << j << std::endl;;
                }
                i = j;
            } else {// special case: S[i] = S[j] and j is already the last element.
                if (j == n-1 && j - i + 1 >= 3) {
                    vector<int> t = {i, j};
                    rst.push_back(t);
                }
            }
        }
        return rst;
    }
};

int main()
{
    string S = "abbxxxxzzy";
    S = "abcdddeeeeaabbbcd";
    //S = "aaa";
    //S = "abbxxxxzzy";
    Solution solver;
    std::cout << "original strng: " << S << std::endl;
    vector<vector<int>> rst = solver.largeGroupPositions(S);
    for (auto i : rst) {
        show_vec(i);
    }
}
