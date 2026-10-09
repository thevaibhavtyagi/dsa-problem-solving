class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openCount = 0; 
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openCount++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; 
                } else {
                    insertions++;
                }
                if (openCount > 0) {
                    openCount--;
                } else {
                    insertions++;
                }
            }
        }

        insertions += openCount * 2;

        return insertions;
    }
};