class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > (long long)9 * num) {
            return "";
        }
        
        string ans = "";
        
        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                ans += '9';
                sum -= 9;
            } else if (sum > 0) {
                ans += to_string(sum);
                sum = 0;
            } else {
                ans += '0';
            }
        }
        
        return ans;
    }
};