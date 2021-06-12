class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        for (int i = 0; i < connections.size(); i++)
        {
            int n1 = connections[i][0];
            int n2 = connections[i][1];
            
            m_graph[n1].insert(n2);
            m_graph[n2].insert(n1);
        }
        
        int components = 0;
        int edges      = connections.size();
        
        for (int i = 0; i < n; i++)
        {
            if (visitedNodes.find(i) == visitedNodes.end())
            {
                components++;
                dfs(i);
            }
        }
        
        int redundantEdges = edges - ( (n-1) - (components-1) );
        
        if (redundantEdges >= components - 1)
        {
            return (components - 1);
        }
        
        return -1;
    }
    
private:
    
    void dfs(int node)
    {
        if (visitedNodes.find(node) != visitedNodes.end())
        {
            return;
        }
        
        visitedNodes.insert(node);
    
        unordered_set<int> neighbors = m_graph[node];
        
        unordered_set<int>::iterator it;
        for (it = neighbors.begin(); it != neighbors.end(); it++)
        {
            dfs(*it);
        }
    }
    
    unordered_set<int> visitedNodes;
    unordered_map<int, unordered_set<int>> m_graph;
};