#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "./include/helper.h"
using std::vector;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n_q = queries.size();
        int sum = 0;
        vector<int> rst;
        for (int i = 0; i < n_q; ++i) {
            int val = queries[i][0];
            int idx = queries[i][1];

            int A_i = A[idx];
            A[idx] += val;

            if (i == 0) {
                sum = 0;
                for (int x : A) {
                    if (x % 2 == 0)
                        sum += x;
                }
                rst.push_back(sum);
            } else {
                if (std::abs(val) % 2 == 1 && std::abs(A[idx]) % 2 == 1)
                    sum -= A_i;
                else if (std::abs(val) % 2 == 1 && std::abs(A[idx]) % 2 == 0)
                    sum += A[idx];
                else if (std::abs(val) % 2 == 0 && std::abs(A[idx]) % 2 == 0)
                    sum += val;
                rst.push_back(sum);
            }

            std::cout << "val = " << val << ", sum= " << sum << ", A=\n";
            show_vec(A);
        }

        return rst;
    }
};

int main()
{
    vector<int> A = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    Solution solver;
    vector<int> rst = solver.sumEvenAfterQueries(A, queries);
    std::cout << "Problem 985: \n";
    show_vec(rst);
}
