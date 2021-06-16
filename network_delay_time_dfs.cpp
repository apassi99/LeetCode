class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int result = INT_MIN;
        
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            pair<int,int> p;
            p.first  = v;
            p.second = w;
            
            m_graph[u].push_back(p);
        }
        
        // Mark start node distance as 0
        m_shortDistances[k] = 0;
        
        helper(k, n);
        
        for (int i = 1; i <= n; i++)
        {
            if (m_visitedNodes.find(i) == m_visitedNodes.end())
            {
                return -1;
            }
            
            result = max(result, m_shortDistances[i]);
        }
        
        return (result == INT_MIN) ? -1 : result;
    }
    
    
private:
    
    void helper(int node, int totalNodes)
    {
        if (m_visitedNodes.find(node) != m_visitedNodes.end())
        {
            return;
        }
        
        m_visitedNodes.insert(node);
        
        vector<pair<int,int >> neighbors = m_graph[node];
        
        for (int i = 0; i < neighbors.size(); i++)
        {
            int neighborNode       = neighbors[i].first;
            int neighborNodeWeight = neighbors[i].second;
            
            if (m_shortDistances.find(neighborNode) != m_shortDistances.end())
            {
                m_shortDistances[neighborNode] = min(m_shortDistances[neighborNode],
                                                     m_shortDistances[node] + 
                                                     neighborNodeWeight);
            }
            else
            {
                 m_shortDistances[neighborNode] = m_shortDistances[node] + 
                                                  neighborNodeWeight;
            }
        }
        
        int nextNode    = -1;
        int minDistance = INT_MAX;
        
        for (int i = 1; i <= totalNodes; i++)
        {
            if (m_visitedNodes.find(i) == m_visitedNodes.end() &&
                m_shortDistances.find(i) != m_shortDistances.end())
            {
                if (minDistance > m_shortDistances[i])
                {
                    nextNode    = i;
                    minDistance = m_shortDistances[i];
                }
            }
        }
        
        if (nextNode != -1)
        {
            helper(nextNode, totalNodes);
        }
    }
    
    typedef unordered_map<int, vector<pair<int,int >>> Graph;
    
    unordered_set<int> m_visitedNodes;
    unordered_map<int,int> m_shortDistances;
    
    Graph m_graph;
};