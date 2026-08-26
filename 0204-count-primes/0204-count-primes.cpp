class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> is_prime(n, true);

        int count = n / 2;  
        is_prime[0] = is_prime[1] = false;

        for (int i = 3; i * i < n; i += 2) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (is_prime[j]) {
                        is_prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};