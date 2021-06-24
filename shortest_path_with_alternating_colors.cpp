class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        for (int i = 0; i < red_edges.size(); i++)
        {
            int node1 = red_edges[i][0];
            int node2 = red_edges[i][1];
            
            m_graph[node1].node = node1;
            m_graph[node1].redEdges.push_back(node2);
        }
        
        for (int i = 0; i < blue_edges.size(); i++)
        {
            int node1 = blue_edges[i][0];
            int node2 = blue_edges[i][1];
            
            m_graph[node1].node = node1;
            m_graph[node1].blueEdges.push_back(node2);
        }
        
        vector<int> temp(n, INT_MAX);
        vector<vector<int>> costs(2, temp);
        
        bfs(0, costs);
        bfs(1, costs);
        
        for (int i = 0; i < n; i++)
        {
            int result = min(costs[0][i], costs[1][i]);
            
            if (result == INT_MAX)
                result = -1;
            
            temp[i] = result;
        }
        
        return temp;
    }
    
    
private:
    
    struct QueueData
    {
        int node;
        int cost;
        int color; // 0 = red, 1 = blue
        
        bool operator>(const QueueData &rhs) const
        {
            return cost > rhs.cost;
        }
    };
    
    typedef struct QueueData QueueData;
    
    struct Node
    {
        int node;
        vector<int> redEdges;
        vector<int> blueEdges;
    };
    
    typedef struct Node Node;
    
    void bfs(int color, vector<vector<int>> &costs)
    {
        int startNode = 0;
        
        QueueData queueData = {startNode, 0, color};
        m_queue.push(queueData);
        
        costs[0][startNode] = 0;
        costs[1][startNode] = 0;
        
        while (!m_queue.empty())
        {
            queueData = m_queue.top();
            m_queue.pop();
            
            int node   = queueData.node;
            int cost   = queueData.cost;
            int color  = queueData.color;
            int nextColor;
            
            vector<int> * neighbors;
            
            if (color == 0)
            {
                nextColor = 1;
                neighbors = &m_graph[node].redEdges;
            }
            else
            {
                nextColor = 0;
                neighbors = &m_graph[node].blueEdges;
            }
            
            for (int i = 0; i < neighbors->size(); i++)
            {
                queueData = {neighbors->at(i), cost+1, nextColor};
                
                if (costs[color][neighbors->at(i)] > cost+1)
                {
                    costs[color][neighbors->at(i)] = cost + 1;
                    m_queue.push(queueData);
                }
            }
        }
    }

    priority_queue<QueueData, vector<QueueData>, greater<QueueData>> m_queue;
    
    unordered_map<int, Node> m_graph;
};