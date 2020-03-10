#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
public:
    int update(int n)
    {
        int sum = 0;
        while (n) {
            int res = n % 10;
            sum += res * res;
            n /= 10;
        }
        return sum;
    }
    /**
     * The number n will be updated in a sequence:
     * n1 -> n2 -> n3 -> ... -> ni.
     * Use a hash map to track the evolution history. At each time,
     * check if the current number exists in the history. Exit the loop
     * if it does exist, else keep going. Now check the exited number.
     * The return answer will be true if it equals one, else false.
     */
    bool isHappy(int n) {
        unordered_map<int, bool> history;
        history[n] = true;
        while(true) {
            n = update(n);
            if (history.count(n)) break;
            history[n] = true;
        }
        return (n == 1);
    }
};

int main()
{
    int n = 100;
    n = 12;
    Solution solver;
    std::cout << solver.isHappy(n) << std::endl;
}
