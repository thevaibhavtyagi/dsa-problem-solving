class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for(auto& str : strs) {
            string ss = str;
            
            sort(ss.begin(), ss.end());
            mp[ss].push_back(str);
        }

        for(auto& s: mp) {
            result.push_back(s.second);
        }

        return result;
        
    }
};