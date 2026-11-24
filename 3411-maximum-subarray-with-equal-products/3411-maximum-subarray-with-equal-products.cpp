class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        const long long MAX_LIMIT = 25200; 

        for (int i = 0; i < n; ++i) {
            long long currentProd = 1;
            long long currentGcd = nums[i];
            long long currentLcm = nums[i];

            for (int j = i; j < n; ++j) {
                currentProd *= nums[j];
                currentGcd = gcd(currentGcd, (long long)nums[j]);
                currentLcm = lcm(currentLcm, (long long)nums[j]);

                if (currentProd == currentLcm * currentGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }

                if (currentProd > MAX_LIMIT) {
                    break;
                }
            }
        }

        return maxLen;
    }
};