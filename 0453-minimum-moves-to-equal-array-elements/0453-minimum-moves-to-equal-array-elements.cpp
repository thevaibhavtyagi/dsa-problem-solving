class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        for (int x : nums) {
            if (x < min_val) {
                min_val = x;
            }
        }

        long long moves = 0;
        for (int x : nums) {
            moves += (x - min_val);
        }

        return moves;
    }
};