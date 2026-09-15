class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

        for (long long i = 1; i <= n; i++) {
            long long x = i;

            while (x >= 1000) {
                ans++;
                x /= 1000;
            }
        }

        return ans;
    }
};