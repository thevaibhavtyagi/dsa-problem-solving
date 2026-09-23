class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findfirst(nums, target);
        int last = findlast(nums, target);

        return {first, last};
    }

    int findfirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                right = mid - 1;
                ans = mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int findlast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                left = mid + 1;
                ans = mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};