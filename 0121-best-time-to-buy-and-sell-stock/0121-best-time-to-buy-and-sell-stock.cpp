class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = prices[0];
        int max_p = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(bestbuy < prices[i]) {
                max_p = max(max_p, prices[i] - bestbuy);
            }

            bestbuy = min(bestbuy, prices[i]);
        }

        return max_p;
    }
};