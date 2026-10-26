class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        std::sort(cost.rbegin(), cost.rend());
        
        int totalCost = 0;
        for (int i = 0; i < cost.size(); ++i) {
            if (i % 3 != 2) {
                totalCost += cost[i];
            }
        }
        
        return totalCost;
    }
};