class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        // vector<int> mavontelia = nums;

        int ans = 0;
        int mx = 0;

        for(int i = k; i < n; i++) {
            mx = max(mx, nums[i - k]);
            ans = max(ans, mx + nums[i]);
        }

        return ans;
    }
};