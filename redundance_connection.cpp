class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> result;
        
        for (int i = 0; i < edges.size(); i++)
        {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            
            m_graph[n1].insert(n2);
            m_graph[n2].insert(n1);
        }

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            m_visitingNodes.clear();

            int n1 = edges[i][0];
            int n2 = edges[i][1];

            m_graph[n1].erase(n2);
            m_graph[n2].erase(n1);

            dfs(n1);

            if (m_visitingNodes.size() == m_graph.size())
            {
                result.push_back(n1);
                result.push_back(n2);
                return result;
            }
            
            m_graph[n1].insert(n2);
            m_graph[n2].insert(n1);
        }
        
        return result;
    }
    
private:
    
    void dfs(int start)
    {
        if (m_visitingNodes.find(start) != m_visitingNodes.end())
        {
            return;
        }
        
        m_visitingNodes.insert(start);
        
        unordered_set<int> neighbors = m_graph[start];
        
        unordered_set<int>::iterator it;
        for (it = neighbors.begin(); it != neighbors.end(); it++)
        {
            dfs(*it);
        }
    }
    
    unordered_set<int> m_visitingNodes;
    unordered_map<int, unordered_set<int>> m_graph;
};