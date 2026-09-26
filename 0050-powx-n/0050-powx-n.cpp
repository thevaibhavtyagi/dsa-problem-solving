class Solution {
public:
    double myPow(double x, int n) {
        long binform = n;
        if(binform < 0){
            x = 1/x;
            binform = -binform;
        }

        double ans = 1;
        while(binform > 0){
            if(binform % 2 == 1){
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }

        return ans;
    }
};