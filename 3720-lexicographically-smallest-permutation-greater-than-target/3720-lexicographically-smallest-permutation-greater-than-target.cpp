class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            int cur = target[i] - 'a';

            for (int x = cur + 1; x < 26; x++) {
                if (cnt[x] > 0) {

                    string ans = target.substr(0, i);
                    ans += char('a' + x);

                    cnt[x]--;

                    for (int ch = 0; ch < 26; ch++) {
                        ans += string(cnt[ch], char('a' + ch));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};