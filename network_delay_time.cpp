class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for (int i = 0; i < times.size(); i++)
        {
            int src = times[i][0];
            int dst = times[i][1];
            int weight = times[i][2];
            
            Edge edge = {dst, weight};
            m_graph[src].push_back(edge);
        }
        
        vector<int> costs(n, INT_MAX);
        
        CostData data;
        data.node   = k;
        data.cost   = 0;
        costs[k-1]  = 0;

        m_costQ.push(data);
        
        while (!m_costQ.empty())
        {
            
            int currentNode     = m_costQ.top().node;
            int currentNodeCost = m_costQ.top().cost;
            
            m_costQ.pop();
            
            vector<Edge> neighbors = m_graph[currentNode];
            
            for (int i = 0; i < neighbors.size(); i++)
            {
                Edge edge = neighbors[i];
                
                if (costs[edge.node-1] > costs[currentNode-1] + edge.weight)
                {   
                    costs[edge.node-1] = costs[currentNode-1] + edge.weight;
                    
                    CostData cd = {edge.node, costs[edge.node-1]};
                    m_costQ.push(cd);
                }
            }
        }
        
        int result = INT_MIN;
        
        for (int i = 0; i < n; i++)
        {
            if (costs[i] == INT_MAX)
                return -1;

            result = max(result, costs[i]);
        }
        
        return result;
        
    }
    
private:
    
    struct Edge
    {
        int node;
        int weight;
    };
    
    typedef struct Edge Edge;
    
    struct CostData
    {
        int node;
        int cost;
        
        bool operator>(const CostData &rhs) const
        {
            return cost > rhs.cost;
        }
    };
    
    typedef struct CostData CostData;
    
    
    unordered_map<int, vector<Edge>> m_graph;

    
    priority_queue<CostData, vector<CostData>, std::greater<CostData>> m_costQ;
};