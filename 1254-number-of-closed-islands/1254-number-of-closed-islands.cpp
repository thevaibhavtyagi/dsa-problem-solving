class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r < m; ++r) {
            if (grid[r][0] == 0) dfs(grid, r, 0, m, n);
            if (grid[r][n - 1] == 0) dfs(grid, r, n - 1, m, n);
        }
        for (int c = 0; c < n; ++c) {
            if (grid[0][c] == 0) dfs(grid, 0, c, m, n);
            if (grid[m - 1][c] == 0) dfs(grid, m - 1, c, m, n);
        }

        int closedCount = 0;
        for (int r = 1; r < m - 1; ++r) {
            for (int c = 1; c < n - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedCount++;
                    dfs(grid, r, c, m, n);
                }
            }
        }

        return closedCount;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0) {
            return;
        }

        grid[r][c] = 1;

        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }
};