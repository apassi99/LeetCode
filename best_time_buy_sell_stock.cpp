class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2) {
            return 0;
        }
        
        int maxProfit = 0;
        int minSoFar = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            
            if (prices[i] - minSoFar > maxProfit) {
                maxProfit = prices[i] - minSoFar;
            }
            
            minSoFar = min(minSoFar, prices[i]);
        }
        
        return maxProfit;
    }
};