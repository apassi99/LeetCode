class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> result;
        
        for (int i = 0; i < edges.size(); i++)
        {
            int parent = edges[i][0];
            int node   = edges[i][1];
            
            m_parents[node].insert(parent);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (m_parents[i].empty())
            {
                result.push_back(i);
            }
        }

        return result;
    }
    
private:
    
    unordered_map<int, unordered_set<int>> m_parents;
};