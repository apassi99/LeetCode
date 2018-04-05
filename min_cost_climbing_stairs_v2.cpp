class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int, int> *memo = new map<int, int>();
        int cost1 = minCostClimbingStairsHelper(cost, 0, *memo);
        int cost2 = minCostClimbingStairsHelper(cost, 1, *memo);
        delete memo;
        return min(cost1, cost2);
    }
    
private:
    
    int minCostClimbingStairsHelper(vector<int> &cost, int index, map<int, int> &memo) {
        if (index >= cost.size()) {
            return 0;
        }
        
        if (index == cost.size() - 1) {
            return cost.back();
        }
        
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }
        
        int cost1 = minCostClimbingStairsHelper(cost, index+1, memo);
        int cost2 = minCostClimbingStairsHelper(cost, index+2, memo);
        memo[index] =  min(cost1, cost2) + cost[index];
        return memo[index];
    }
};