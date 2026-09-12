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

            if(v.size() >= 3) {
                int gap = v[1] - v[0];

                bool ok = true;

                for(int i = 2; i < v.size(); i++) {
                    if(v[i] - v[i - 1] != gap) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};