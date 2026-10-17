class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> result;

        for (int i = n - k; i < n; i++) {
            result.push_back(nums[i]);
        }

        for (int i = 0; i < n - k; i++) {
            result.push_back(nums[i]);
        }

        nums = result;
    }
};
