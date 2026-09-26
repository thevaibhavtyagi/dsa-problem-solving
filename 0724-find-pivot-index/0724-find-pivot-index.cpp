class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;

        for(auto x : nums) {
            sum += x;
        }

        int leftsum = 0;
        for(auto i = 0; i < nums.size(); i++) {
            int rightsum = sum - leftsum - nums[i];

            if(leftsum == rightsum) {
                return i;
            }

            leftsum += nums[i];
        }

        return -1;
    }
};