class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX;
        int even = INT_MAX;

        for (int x : nums1) {
            if (x % 2)
                odd = min(odd, x);
            else
                even = min(even, x);
        }

        if (odd == INT_MAX || even == INT_MAX)
            return true;

        return odd < even;
    }
};