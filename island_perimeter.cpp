class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        set<pair<int,int>> visitedNodes;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dfs(make_pair(i,j), grid, visitedNodes, result);
            }
        }
        return result;
    }
    
private:
    
    void dfs(const pair<int,int> &node, vector<vector<int>>& grid, 
             set<pair<int,int>> &visitedNodes, int &result) {
        
        if (visitedNodes.find(node) != visitedNodes.end())
            return;
        
        if (grid[node.first][node.second] == 0)
            return;
        
        visitedNodes.insert(node);
        
        vector<pair<int,int>> neighbors = getNeighbors(node, grid);
        
        for (int i = 0; i < neighbors.size(); i++) {
            dfs(neighbors[i], grid, visitedNodes, result);
        }

        result += 4 - neighbors.size();
    }
    
    vector<pair<int,int>> getNeighbors(const pair<int,int> &node, 
                                       const vector<vector<int>>& grid) {
        
        int l = grid.size();
        int w = grid[0].size();
        vector<pair<int,int>> result;
        
        int dx [] = {1, -1, 0, 0};
        int dy [] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            pair<int,int> p = make_pair(node.first + dx[i], node.second + dy[i]);
            
            if (isValid(p, l, w) && grid[p.first][p.second] == 1)
                result.push_back(p);
        }

        return result;
    }
    
    bool isValid(const pair<int,int> &p, int l, int w) {
        return p.first >= 0 && p.first < l && p.second >= 0 && p.second < w;
    }
};