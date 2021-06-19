class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<bool> result(queries.size());
        
        // Build graph
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int c1 = prerequisites[i][0];
            int c2 = prerequisites[i][1];
            m_graph[c2].push_back(c1);
        }
        
        // Traverse full tree from each node
        // and build memo table
        for (int i = 0; i < numCourses; i++)
        {
            bfs(i);
        }
        
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            
            result[i] = m_memoTable[v].find(u) != m_memoTable[v].end();
        }
        
        return result;
    }
    
private:
    
    void bfs(int node)
    {
        m_visitedNodes.clear();
        
        list<int> q;
        
        q.push_back(node);
        
        while (!q.empty())
        {
            int curNode = q.front();
            q.pop_front();
            
            if (m_visitedNodes.find(curNode) != m_visitedNodes.end())
            {
                continue;
            }
            
            m_visitedNodes.insert(curNode);
            
            vector<int> neighbors = m_graph[curNode];
            
            for (int i = 0; i < neighbors.size(); i++)
            {
                m_memoTable[node].insert( neighbors[i] );
                q.push_back( neighbors[i] );
            }
        }
    }
    
    unordered_set<int> m_visitedNodes;
    
    unordered_map<int, vector<int>> m_graph;
    
    unordered_map<int, unordered_set<int>> m_memoTable;
    
};