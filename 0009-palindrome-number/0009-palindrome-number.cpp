class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int temp = x;

        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }

        return x == rev;
    }
};