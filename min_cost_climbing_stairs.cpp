class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        if (cost.size() <= 1) {
            return 0;
        }
        
        int min_i = 0, min_j = 0, min_k = 0;
        
        for (int i = 2; i < cost.size(); i++) {
            min_k = min(min_i + cost[i-2], min_j + cost[i-1]);
            min_i = min_j;
            min_j = min_k;
        }
        
        return min(min_i + cost[cost.size() - 2], min_j + cost[cost.size() - 1]);
    }
};