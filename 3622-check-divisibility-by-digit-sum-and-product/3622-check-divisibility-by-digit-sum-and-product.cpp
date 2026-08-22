class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int digitSum = 0;
        int digitProduct = 1;

        while (x > 0) {
            int digit = x % 10;
            digitSum += digit;
            digitProduct *= digit;
            x /= 10;
        }

        return n % (digitSum + digitProduct) == 0;
    }
};