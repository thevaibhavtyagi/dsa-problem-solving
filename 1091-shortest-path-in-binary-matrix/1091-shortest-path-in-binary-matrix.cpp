class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<tuple<int, int, int>> q;

        q.push({0, 0, 1});
        grid[0][0] = 1;

        while(!q.empty()) {

            auto [row, col, dist] = q.front();

            q.pop();

            if(row == n - 1 && col == n - 1) {
                return dist;
            }

            for(int i = 0; i < 8; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol, dist + 1});
                }
            }

        }

        return -1;

    }
};