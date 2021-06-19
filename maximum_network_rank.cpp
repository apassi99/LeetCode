class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int result = 0;
        
        for (int i = 0; i < roads.size(); i++)
        {
            int c1 = roads[i][0];
            int c2 = roads[i][1];
            
            m_graph[c1].insert(c2);
            m_graph[c2].insert(c1);
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int val = m_graph[i].size() + m_graph[j].size();
                
                if (m_graph[i].find(j) != m_graph[i].end())
                {
                    val--;
                }
                
                result = max(result, val);
            }
        }
        
        return result;
    }
    
private:
    
    unordered_map<int, unordered_set<int>> m_graph;
};