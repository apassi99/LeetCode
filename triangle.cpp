class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        return dfs(triangle, 0, 0);
    }
    
private:
    
    int dfs(vector<vector<int>>& triangle, int level, int idx)
    {
        if (level >= triangle.size())
        {
            return 0;
        }
        
        if (idx >= triangle[level].size())
        {
            return 0;
        }
        
        string key = std::to_string(level) + "-" + std::to_string(idx);
        
        if (m_dp.find(key) != m_dp.end())
        {
            return m_dp[key];
        }
        
        int min_sum = triangle[level][idx];
        
        int val1 = dfs(triangle, level+1, idx);
        int val2 = dfs(triangle, level+1, idx+1);
        
        min_sum += min(val1, val2);
        
        m_dp[key] = min_sum;
        
        return min_sum;
    }
    
    unordered_map<string, int> m_dp;
};