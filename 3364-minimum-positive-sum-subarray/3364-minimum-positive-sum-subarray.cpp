class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = -1;
        int n = nums.size();
        
        for (int len = l; len <= r; ++len) {
            int currentSum = 0;
            for (int i = 0; i < len; ++i) {
                currentSum += nums[i];
            }
            
            if (currentSum > 0) {
                if (minSum == -1 || currentSum < minSum) {
                    minSum = currentSum;
                }
            }
            
            for (int i = len; i < n; ++i) {
                currentSum += nums[i] - nums[i - len];
                if (currentSum > 0) {
                    if (minSum == -1 || currentSum < minSum) {
                        minSum = currentSum;
                    }
                }
            }
        }
        
        return minSum;
    }
};