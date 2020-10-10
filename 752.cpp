#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <queue>
#include <cstddef>

using std::string;
using std::set;
using std::vector;
using std::queue;

class Solution {
    string rollUp(string &s_inp, int i)
    {
        string s{s_inp};
        if (s[i] == '9')
            s[i] = '0';
        else
            s[i] += 1;
        return s;
    }

    string rollDown(string &s_inp, int i)
    {
        string s{s_inp};
        if (s[i] == '0')
            s[i] = '9';
        else
            s[i] -= 1;
        return s;
    }

  public:
    int openLock(vector<string> &deadends, string target)
    {
        // special cases.
        if (target == "0000")
            return 0;
        set<string> dead(deadends.begin(), deadends.end());
        // initial guess is in deadends.
        if (dead.find("0000") != dead.end())
            return -1;

        queue<string> q;
        set<string> visited;

        int steps = 0;
        q.push("0000");
        while (!q.empty()) {
            int size = q.size();

            auto temp = q;
            for (size_t i = 0; i < size; ++i) {
                std::cout << temp.front() << ", ";
                temp.pop();
            }
            std::cout << std::endl;

            for (size_t k = 0; k < size; ++k) {
                string &cur = q.front();
                visited.insert(cur);
                // visit adj
                if (cur == target)
                    return steps;
                for (size_t i = 0; i < cur.size(); ++i) {
                    string s_up = rollUp(cur, i);
                    if (visited.find(s_up) == visited.end() &&
                        dead.find(s_up) == dead.end()) {
                        q.push(s_up);
                        visited.insert(s_up);
                    }
                    string s_down = rollDown(cur, i);
                    if (visited.find(s_down) == visited.end() &&
                        dead.find(s_down) == dead.end()) {
                        q.push(s_down);
                        visited.insert(s_down);
                    }
                }

                // pop front.
                q.pop();
            }
            steps++;
        }

        return -1;
    }
};