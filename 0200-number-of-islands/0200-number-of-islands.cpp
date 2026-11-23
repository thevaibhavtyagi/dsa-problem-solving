class Solution {
public:

    // void dfs(vector<vector<char>>& matrix, int i, int j) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] == '0') {
    //         return;
    //     }

    //     matrix[i][j] = '0';

    //     dfs(matrix, i - 1, j);
    //     dfs(matrix, i + 1, j);
    //     dfs(matrix, i, j - 1);
    //     dfs(matrix, i, j + 1);
    // }

    void bfs(vector<vector<char>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});

        matrix[i][j] = '0';

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if(row - 1 >= 0 && matrix[row - 1][col] == '1') {
                q.push({row - 1, col});
                matrix[row - 1][col] = '0';
            }

            if(row + 1 < m && matrix[row + 1][col] == '1' ) {
                q.push({row + 1, col});
                matrix[row + 1][col] = '0';
            }

            if(col - 1 >= 0 && matrix[row][col - 1] == '1') {
                q.push({row, col - 1});
                matrix[row][col - 1] = '0';
            }

            if(col + 1 < n && matrix[row][col + 1] == '1') {
                q.push({row, col + 1});
                matrix[row][col + 1] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    count++;
                    bfs(matrix, i, j);
                }
            }
        }

        return count;
        
    }
};