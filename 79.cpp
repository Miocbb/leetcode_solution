#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;

        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (find(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool find(vector<vector<char>> &board, int i, int j, string &word,
              size_t idx)
    {
        if (idx >= word.size())
            return true;
        if (i < 0 || i >= board.size())
            return false;
        else if (j < 0 || j >= board[0].size())
            return false;
        else if (board[i][j] == '1')
            return false;
        else if (board[i][j] == word[idx]) {
            char save = board[i][j];
            board[i][j] = '1';
            int next_idx = idx + 1;
            bool rst = find(board, i - 1, j, word, next_idx) ||
                       find(board, i + 1, j, word, next_idx) ||
                       find(board, i, j - 1, word, next_idx) ||
                       find(board, i, j + 1, word, next_idx);
            if (rst == true)
                return true;
            else
                board[i][j] = save;
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target = "ABCB";
    Solution solver;
    std::cout << "answer: " << solver.exist(board, target) << std::endl;
}
