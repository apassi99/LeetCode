class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int result = 0;
        unordered_map<string, int> memo_table;
        
        return dfs(make_pair(i, j), m, n, N, memo_table);
        // return result;
    }
    
private:
    
    int dfs(const pair<int,int> &curPos, int m, int n, 
             int stepsRemain, unordered_map<string, int> &memo_table) {
        
        string key = to_string(curPos.first) + "." + to_string(curPos.second) +
                     "." + to_string(stepsRemain);
        
        if (curPos.first < 0 || curPos.second < 0 || 
            curPos.first >= m || curPos.second >= n) {
            return 1;
        }
        
        if (stepsRemain <= 0) {
            return 0;
        }
        
        if (memo_table.find(key) != memo_table.end()) {
            return memo_table[key];
        }
        
        int result = 0;
        vector<pair<int,int>> neighbors = getNeighbors(curPos);
        
        for (int i = 0; i < neighbors.size(); i++) {
            result += dfs(neighbors[i], m, n, stepsRemain-1, memo_table);
            result = result % 1000000007;
        }
        
        memo_table[key] = result;
        return memo_table[key];
    }
    
    vector<pair<int,int>> getNeighbors(const pair<int,int> &p) {
        vector<pair<int,int>> result;
        
        int dx [] = {1, -1, 0, 0};
        int dy [] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            result.push_back(make_pair(p.first + dx[i], p.second + dy[i]));
        }
        
        return result;
    }
};