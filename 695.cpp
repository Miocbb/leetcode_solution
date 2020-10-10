#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    void bfs(vector<vector<int>> &grid, int i, int j, int row, int col, int &n)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            return;
        }

        n++;
        std::cout << row << ", " << col << std::endl;
        std::cout << "i,j=" << i << "," << j << " n=" << n << std::endl;
        grid[i][j] = 0;
        show(grid);
        bfs(grid, i + 1, j, row, col, n);
        bfs(grid, i - 1, j, row, col, n);
        bfs(grid, i, j - 1, row, col, n);
        bfs(grid, i, j + 1, row, col, n);
    }

    void show(vector<vector<int>> &grid) const
    {
        for (size_t i = 0; i < grid.size(); ++i) {
            for (auto x : grid[i]) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }

  public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.size() <= 0)
            return 0;
        int row = grid.size();
        if (grid[0].size() <= 0)
            return 0;
        int col = grid[0].size();
        int rst = 0;

        for (size_t i = 0; i < row; ++i)
            for (size_t j = 0; j < col; ++j) {
                int n = 0;
                bfs(grid, i, j, row, col, n);
                rst = (rst > n ? rst : n);
                return rst;
            }
        return rst;
    }
};

int main(int argc, const char **argv)
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    grid = {{1, 1}};
    std::cout << Solution().maxAreaOfIsland(grid);
    return 0;
}