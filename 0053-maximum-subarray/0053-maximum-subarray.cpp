class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int m_sum = INT_MIN;

        for(auto s : nums) {
            sum += s;

            m_sum = max(sum, m_sum);
            if(sum < 0) {
                sum = 0;
            }
        }

        return m_sum;
    }
};