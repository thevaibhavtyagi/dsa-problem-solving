class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        return 1LL * (*max_it - *min_it) * k;
    }
};