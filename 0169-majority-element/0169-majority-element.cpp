class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int result = -1;

        for(auto it : mp) {
            if(it.second > n / 2) {
                result = it.first;
                break;
            }
        }

        return result;
    }
};