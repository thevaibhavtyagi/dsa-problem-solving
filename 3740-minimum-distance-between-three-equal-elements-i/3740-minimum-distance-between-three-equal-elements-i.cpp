class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<vector<int>> pos(n + 1);

        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        for (auto &p : pos) {
            for (int i = 2; i < p.size(); i++)
                ans = min(ans, 2 * (p[i] - p[i - 2]));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};