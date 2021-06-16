class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        if (heights.empty() || heights[0].empty())
        {
            return 0;
        }
        
        m_rows = heights.size();
        m_cols = heights[0].size();
        
        for (int i = 0; i < m_rows; i++)
        {
            vector<bool> tempBool;
            vector<int> tempInt;
            
            for (int j = 0; j < m_cols; j++)
            {
                tempInt.push_back(INT_MAX);
                tempBool.push_back(false);
            }
            
            m_visited.push_back(tempBool);
            m_cost.push_back(tempInt);
        }
        
        Coord startNode = {0, 0, 0};
        m_cost[0][0] = 0;
        
        dfs(startNode, heights);
        
        return m_cost[m_rows-1][m_cols-1];
    }
    
private:
    
    struct Coord
    {
        int x;
        int y;
        int effort;
        
        bool operator<(const Coord& rhs) const
        {
            return effort > rhs.effort;
        }

    };
    
    typedef struct Coord Coord;
    
    void dfs(Coord node, vector<vector<int>>& heights)
    {
        if (node.x < 0 || node.x >= m_rows ||
            node.y < 0 || node.y >= m_cols)
        {
            return;
        }

        if (m_visited[node.x][node.y])
        {
            return;
        }
        
        m_visited[node.x][node.y] = true;
        
        vector<Coord> neighbors = getNeighbors(node.x, node.y,
                                               m_rows, m_cols);
        
        for (int i = 0; i < neighbors.size(); i++)
        {
            Coord newNode = neighbors[i];
            
            int cost = abs(heights[newNode.x][newNode.y] - 
                           heights[node.x][node.y]);
            
            cost = max(cost, m_cost[node.x][node.y]);
            
            if (m_cost[newNode.x][newNode.y] == INT_MAX)
            {
                m_cost[newNode.x][newNode.y] = cost;
            }
            else
            {
                if (m_cost[newNode.x][newNode.y] > cost)
                {
                    m_cost[newNode.x][newNode.y] = cost;
                }
            }
            
            newNode.effort = m_cost[newNode.x][newNode.y];
            
            m_nodes.push(newNode);
        }
        
        Coord nextNode = getNextNode();
        
        dfs(nextNode, heights);
    }
    
    vector<Coord> getNeighbors(int i, int j, int rows, int cols)
    {
        vector<Coord> result;
        
        int deltaX[4] = {1, -1, 0,  0};
        int deltaY[4] = {0,  0, 1, -1};
        
        for (int idx = 0; idx < 4; idx++)
        {
            int newI = i + deltaX[idx];
            int newJ = j + deltaY[idx];
            
            if (newI >= 0 && newI < rows &&
                newJ >= 0 && newJ < cols)
            {
                Coord coord = {newI, newJ, 0};
                result.push_back(coord);
            }
        }
        
        return result;
    }
    
    Coord getNextNode()
    {
        Coord result = {-1, -1};
        
        if (m_nodes.empty())
        {
            return result;
        }
        
        result = m_nodes.top();
        
        m_nodes.pop();
        
        if (m_visited[result.x][result.y])
        {
            return getNextNode();
        }

        return result;
    }

    priority_queue<Coord> m_nodes;
    vector<vector<bool>> m_visited;
    vector<vector<int>> m_cost;
    
    int m_rows;
    int m_cols;
};