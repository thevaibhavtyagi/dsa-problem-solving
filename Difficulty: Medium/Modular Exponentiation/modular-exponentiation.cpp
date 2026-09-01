class Solution {
  public:
    int powMod(int x, int n, int M) {
        long long ans = 1;
        x %= M;

        while (n) {
            if (n & 1)
                ans = (ans * x) % M;

            x = (1LL * x * x) % M;
            n >>= 1;
        }

        return ans;
    }
};