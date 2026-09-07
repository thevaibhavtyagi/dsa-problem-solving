class Solution {
private:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }

        int rev = 0;
        int temp = x;
        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        return rev == x;
    }

    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        if (x == 2 || x == 3){
            return true;
        } 
        if (x % 2 == 0 || x % 3 == 0) {
            return false;
        }

        for (int d = 5; d * d <= x; d += 6) {
            if (x % d == 0 || x % (d + 2) == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int primePalindrome(int n) {
        if (8 <= n && n <= 11) return 11;

        while (true) {
            if (1000 <= n && n < 10000) {
                n = 10000;
            } else if (100000 <= n && n < 1000000) {
                n = 1000000;
            } else if (10000000 <= n && n < 100000000) {
                n = 100000000;
            }

            if (isPalindrome(n) && isPrime(n)) {
                return n;
            }
            n++;
        }
    }
};