class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> c(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            c[i + 1] = costs[i];
        }

        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; ++j) {
            for (int step = 1; step <= 3; ++step) {
                int i = j - step;
                if (i >= 0 && dp[i] != LLONG_MAX) {
                    long long cost = dp[i] + c[j] + (long long)(j - i) * (j - i);
                    dp[j] = min(dp[j], cost);
                }
            }
        }

        return dp[n];
    }
};