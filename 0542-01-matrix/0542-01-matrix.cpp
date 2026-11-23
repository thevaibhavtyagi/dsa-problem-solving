class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if(row - 1 >= 0 && ans[row - 1][col] == -1){
                ans[row - 1][col] = ans[row][col] + 1 ;
                q.push({row - 1, col});
            }

            if(row + 1 < m && ans[row + 1][col] == -1){
                ans[row + 1][col] = ans[row][col] + 1;
                q.push({row + 1, col});
            }
            if(col - 1 >= 0 && ans[row][col - 1] == -1){
                ans[row][col - 1] = ans[row][col] + 1;
                q.push({row, col - 1});
            }
            if(col + 1 < n && ans[row][col + 1] == -1){
               ans[row][col + 1] = ans[row][col] + 1; 
                q.push({row, col + 1});
            }
        }

        return ans;

    }
};