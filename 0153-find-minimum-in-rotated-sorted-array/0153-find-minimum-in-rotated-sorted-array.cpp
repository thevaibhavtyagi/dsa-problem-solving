class Solution {
public:
    int findMin(vector<int>& nums) {
        // int min = INT_MAX;

        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] < min) {
        //         min = nums[i];
        //     }
        // }

        // return min;

        int  left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};