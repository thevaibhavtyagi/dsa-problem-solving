class Solution {
public:
    int orangesRotting(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        int fresh = 0;
        int minutes = 0;


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 2) {
                    q.push({i, j});

                } else if(matrix[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0) {
            int size = q.size();

            for(int k = 0; k < size; k++) {
                int row = q.front().first;
                int col = q.front().second;

                

                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] == 1) {
                        matrix[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        fresh--;
                    }
                }
            }

            minutes++;
        }

        if(fresh > 0) {
            return -1;
        }

        return minutes;
     }
};



// Manual work:
                // if(row - 1 >= 0 && matrix[row - 1][col] == 1) {
                //     matrix[row - 1][col] = 2;
                //     q.push({row - 1, col});
                //     fresh--;
                // }

                // if(row + 1 < m && matrix[row + 1][col] == 1) {
                //     matrix[row + 1][col] = 2;
                //     q.push({row + 1, col});
                //     fresh--;
                // }
                // if(col - 1 >= 0 && matrix[row][col - 1] == 1) {
                //     matrix[row][col - 1] = 2;
                //     q.push({row, col - 1});
                //     fresh--;
                // }
                // if(col + 1 < n && matrix[row][col + 1] == 1) {
                //     matrix[row][col + 1] = 2;
                //     q.push({row, col + 1});
                //     fresh--;
                // }