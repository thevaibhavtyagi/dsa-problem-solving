class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto it : mp) {
            vector<int> v = it.second;

            if(v.size() == 3) {
                if(v[1] - v[0] == v[2] - v[1]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};