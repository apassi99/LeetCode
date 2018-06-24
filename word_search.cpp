class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        set<pair<int,int>> visitedNodes;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(make_pair(i,j), board, visitedNodes, word, 0)) {
                    return true;
                }
                visitedNodes.clear();
            }
        }

        return false;
    }
    
private:
    
    bool dfs(const pair<int,int> &node, vector<vector<char>>& G, 
             set<pair<int,int>> &visitedNodes, string &word, int idx) {
        
        if (idx >= word.size())
            return true;

        if (visitedNodes.find(node) != visitedNodes.end())
            return false;
        
        if (word[idx] != G[node.first][node.second])
            return false;
        
        visitedNodes.insert(node);
        
        vector<pair<int,int>> neighbors = getNeighbors(node, G.size(), G[0].size());
        
        for (int i = 0; i < neighbors.size(); i++) {
            if (dfs(neighbors[i], G, visitedNodes, word, idx+1)) {
                return true;
            }
        }
        
        visitedNodes.erase(node);
        
        return neighbors.empty() && idx == word.size() - 1;
    }
    
    vector<pair<int,int>> getNeighbors(const pair<int,int> &node, int l, int w) {
        vector<pair<int,int>> result;
        
        int dx [] = {1, -1, 0, 0};
        int dy [] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            pair<int,int> p = make_pair(node.first + dx[i], node.second + dy[i]);
            if (isValid(p, l, w))
                result.push_back(p);
        }
        
        return result;
    }
    
    bool isValid(const pair<int,int> &p, int l, int w) {
        return p.first >= 0 && p.first < l && p.second >= 0 && p.second < w;
    }
};