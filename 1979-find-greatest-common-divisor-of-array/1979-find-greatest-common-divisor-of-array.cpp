class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size() - 1;

        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[n];

        for(int i = max; i > 1; i-- ){
            if(max % i == 0 && min % i == 0) {
                return i;
            }
        }

        return 1;
    }
};