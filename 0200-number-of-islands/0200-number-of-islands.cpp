class Solution {
public:

    void dfs(vector<vector<char>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] == '0') {
            return;
        }

        matrix[i][j] = '0';

        dfs(matrix, i - 1, j);
        dfs(matrix, i + 1, j);
        dfs(matrix, i, j - 1);
        dfs(matrix, i, j + 1);
    }
    int numIslands(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    count++;
                    dfs(matrix, i, j);
                }
            }
        }

        return count;
        
    }
};