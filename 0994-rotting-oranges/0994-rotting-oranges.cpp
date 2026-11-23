class Solution {
public:
    int orangesRotting(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

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

                if(row - 1 >= 0 && matrix[row - 1][col] == 1) {
                    matrix[row - 1][col] = 2;
                    q.push({row - 1, col});
                    fresh--;
                }

                if(row + 1 < m && matrix[row + 1][col] == 1) {
                    matrix[row + 1][col] = 2;
                    q.push({row + 1, col});
                    fresh--;
                }
                if(col - 1 >= 0 && matrix[row][col - 1] == 1) {
                    matrix[row][col - 1] = 2;
                    q.push({row, col - 1});
                    fresh--;
                }
                if(col + 1 < n && matrix[row][col + 1] == 1) {
                    matrix[row][col + 1] = 2;
                    q.push({row, col + 1});
                    fresh--;
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