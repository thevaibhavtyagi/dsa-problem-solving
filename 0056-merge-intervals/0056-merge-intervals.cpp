class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        result.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], nums[i][1]);
            } else {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};