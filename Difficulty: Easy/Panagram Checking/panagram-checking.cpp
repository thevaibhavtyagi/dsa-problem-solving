class Solution {
  public:
    bool checkPangram(string& s) {
        //  code here
        unordered_map<char, bool> mp;
        
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                char lower_c = tolower(s[i]);
                
                mp[lower_c] = true;
            }
        }
        
        return mp.size() == 26;
        
    }
};