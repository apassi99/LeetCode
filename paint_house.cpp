#include <unordered_map>

using std::pair;
using std::unordered_map;

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int result = minCostHelper(costs, -1, 0);
        return (result == INT_MAX) ? 0 : result;
    }
    
private:

    struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
        }
    };


    int minCostHelper(vector<vector<int>> &costs, int prevColor, int curHouse) {
        
        if (curHouse >= costs.size())
            return 0;
        
        int curMinCost = INT_MAX;
        int curHouseColor = -1;
        
        pair<int,int> key = make_pair(prevColor, curHouse);
        
        if (memoTable.find(key) != memoTable.end()) {
            return memoTable[key];
        }
        
        for (int i = 0; i < costs[curHouse].size(); i++) {
            if (prevColor != i) {
                int temp = costs[curHouse][i] + minCostHelper(costs, i, curHouse+1);
                curMinCost = min(temp, curMinCost);
            }
        }
        
        memoTable[key] = curMinCost;
        
        return curMinCost;
    }
    
    unordered_map<pair<int,int>, int, pair_hash> memoTable;
};