class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int result = 0;
        Node start;
        Node end;
        NodeMap parentMap;
        
        start.x = 0;
        start.y = 0;
        
        end.x = (int) grid.size() -1;
        end.y = (int) grid[0].size() - 1;
        
        bfs(grid, start, parentMap);
        
        Node it = end;
        
        while (it != start && parentMap.find(it) != parentMap.end())
        {
            it = parentMap[it];
            result++;
        }

        return (it == start) ? result + 1: -1;
    }

private:

    struct Node {
        int x;
        int y;
        
        Node() : x(-1), y(-1) {}
        Node(int xi, int yi) : x(xi), y(yi) {}
        
        bool operator==(const Node &rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }
        
        bool operator<(const Node &rhs)  const
        {
            return x < rhs.x || (x == rhs.x && y < rhs.y);
        }
        
        bool operator!=(const Node &rhs) const
        {
            return x != rhs.x || y != rhs.y;
        }
    };

    struct node_hash {
        std::size_t operator () (const struct Node &n) const {
            auto h1 = std::hash<int>{}(n.x);
            auto h2 = std::hash<int>{}(n.y);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };

    typedef struct Node Node;
    typedef vector<vector<int>> Graph;
    typedef unordered_set<Node, node_hash> NodeSet;
    typedef unordered_map<Node,Node, node_hash> NodeMap; 

    void bfs(Graph &graph, Node &start,NodeMap &parentMap)
    {
        list<Node> q;
        vector<Node> neighbors;
        
        if (graph[start.x][start.y] == 0)
            q.push_back(start);
        
        NodeSet visitedNodes;
        
        while (!q.empty())
        {
            int size = q.size();
            
            for (int i = 0; i < size; i++)
            {
                Node n = q.front();
                q.pop_front();
                
                neighbors = getNeighbors(graph, n);
                
                for (Node neighbor : neighbors)
                {
                    if (visitedNodes.find(neighbor) != visitedNodes.end()) {
                        continue;
                    }

                    visitedNodes.insert(neighbor);
                    parentMap[neighbor] = n;
                    q.push_back(neighbor);
                }
            }
        }
    }
    
    vector<Node> getNeighbors(Graph &graph, Node &node)
    {
        vector<Node> result;
        
        int dx [8] = {1, -1, 0,  0,  1, -1, 1, -1};
        int dy [8] = {0,  0, 1, -1, -1,  1, 1, -1};
        
        int length = (int) graph.size();
        int width  = (int) (length != 0) ? graph[0].size() : 0;
        
        if (length == 0 || width == 0)
        {
            return result;
        }
        
        for (int i = 0; i < 8; i++)
        {
            int newX = node.x + dx[i];
            int newY = node.y + dy[i];
            
            if (newX >= 0 && newX < length &&
                newY >= 0 && newY < width  &&
                graph[newX][newY] == 0)
            {
                Node newNode = {newX, newY};
                result.push_back(newNode);
            }
        }
        
        return result;
    }
};