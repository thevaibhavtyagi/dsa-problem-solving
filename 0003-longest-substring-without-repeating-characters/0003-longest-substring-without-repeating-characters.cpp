class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int m_len = 0;

        for(int right = 0; right < s.length(); right++) {
            while(st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            int cl = right - left + 1;

            m_len = max(m_len, cl);
        }

        return m_len;
    }
};