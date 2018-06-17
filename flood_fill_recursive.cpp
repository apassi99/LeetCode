class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int>> result;
        set<pair<int,int>> visitedNodes;

        for (int i = 0; i < image.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < image[0].size(); j++) {
                temp.push_back(image[i][j]);
            }
            result.push_back(temp);
        }

        dfs(make_pair(sr, sc), result, visitedNodes, newColor);
        
        return result;
    }
    
    void dfs(const pair<int,int> &node, vector<vector<int>>& result, 
             set<pair<int,int>> &visitedNodes, int newColor) {
        
        if (visitedNodes.find(node) != visitedNodes.end())
            return;
        
        visitedNodes.insert(node);
        
        vector<pair<int,int>> neighbors = getNeighbors(node, result);
        
        for (int i = 0; i < neighbors.size(); i++) {
            dfs(neighbors[i], result, visitedNodes, newColor);
        }
        
        result[node.first][node.second] = newColor;
    }
    
    vector<pair<int,int>> getNeighbors(const pair<int,int> &node, 
                                       const vector<vector<int>>& image) {
        
        int l = image.size();
        int w = image[0].size();
        vector<pair<int,int>> result;
        
        int dx [] = {1, -1, 0, 0};
        int dy [] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            pair<int,int> p = make_pair(node.first + dx[i], node.second + dy[i]);
            
            if (isValid(p, l, w) && image[node.first][node.second] == image[p.first][p.second])
                result.push_back(p);
        }
        
        return result;
    }
    
    bool isValid(const pair<int,int> &p, int l, int w) {
        return p.first >= 0 && p.first < l && p.second >= 0 && p.second < w;
    }
};