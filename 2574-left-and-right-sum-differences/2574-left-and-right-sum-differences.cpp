class Solution {
public:
    std::vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            rightSum -= nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return answer;
    }
};