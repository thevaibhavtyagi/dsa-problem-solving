class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = INT_MIN;

        for(auto s : nums) {
            sum += s;

            maxsum = max(sum, maxsum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxsum;
    }
};