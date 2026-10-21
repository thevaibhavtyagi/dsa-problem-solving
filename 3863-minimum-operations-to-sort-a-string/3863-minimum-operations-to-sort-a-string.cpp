class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;

        if (n <= 2) return -1;

        char mn = s[0];
        char mx = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] < mn) mn = s[i];
            if (s[i] > mx) mx = s[i];
        }

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        bool has_mn_prefix = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn) {
                has_mn_prefix = true;
                break;
            }
        }

        bool has_mx_suffix = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == mx) {
                has_mx_suffix = true;
                break;
            }
        }

        if (has_mn_prefix || has_mx_suffix) {
            return 2;
        }

        return 3;
    }
};