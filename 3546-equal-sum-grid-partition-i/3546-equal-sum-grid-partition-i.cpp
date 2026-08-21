class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        
        if(total % 2 != 0) return false;
        
        long long curr = 0;
        
        // horizontal cuts
        for(int i = 0; i < m - 1; i++) {
            long long rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            
            curr += rowSum;
            
            if(curr * 2 == total) return true;
        }
        
        // column sums
        vector<long long> colSum(n, 0);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        
        curr = 0;
        
        // vertical cuts
        for(int j = 0; j < n - 1; j++) {
            curr += colSum[j];
            
            if(curr * 2 == total) return true;
        }
        
        return false;
    }
};