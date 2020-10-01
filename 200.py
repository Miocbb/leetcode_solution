class Solution:
    def numIslands(self, grid) -> int:
        if not grid:
            return 0
        row = len(grid)
        col = len(grid[0])
        rst = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    rst += 1
                    self.dfs(grid, i, j, row, col)
        return rst

    def dfs(self, grid, i, j, row, col):
        if not (0<= i < row) or not (0 <= j < col) or grid[i][j] == '0':
            return
        else:
            grid[i][j] = '0'
        self.dfs(grid, i-1, j, row, col)
        self.dfs(grid, i+1, j, row, col)
        self.dfs(grid, i, j-1, row, col)
        self.dfs(grid, i, j+1, row, col)

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

print(Solution().numIslands(grid))
