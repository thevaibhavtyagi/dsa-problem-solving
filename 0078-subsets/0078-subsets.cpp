class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        solve(nums, i + 1);

        temp.push_back(nums[i]);
        solve(nums, i + 1);

        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};