class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        int fromFront = right + 1;
        int fromBack = n - left;
        int bothSides = left + 1 + n - right;

        return min({fromFront, fromBack, bothSides});
    }
};
