class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if (board.empty() || board[0].empty())
            return;
        
        set<pair<int,int>> visitedNodes;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = '*';
            }
        }
    
        for (int i = 0; i < board.size(); i++) {
            dfs(make_pair(i, 0), board, visitedNodes);
            dfs(make_pair(i, board[0].size()-1), board, visitedNodes);
        }
    
        for (int j = 0; j < board[0].size(); j++) {
            dfs(make_pair(0, j), board, visitedNodes);
            dfs(make_pair(board.size()-1, j), board, visitedNodes);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '*')
                    board[i][j] = 'X';
            }
        }
    }
    
private:
    
    void dfs(const pair<int,int> &node, vector<vector<char>> &G,
             set<pair<int,int>> &visitedNodes) {
        
        if (visitedNodes.find(node) != visitedNodes.end())
            return;
        
        visitedNodes.insert(node);

        if (G[node.first][node.second] == 'X')
            return;
    
        vector<pair<int,int>> neighbors = getNeighbors(node, G);
        
        for (int i = 0; i < neighbors.size(); i++) {
            dfs(neighbors[i], G, visitedNodes);
        }
        
        G[node.first][node.second] = 'O';
        
    }
    
    vector<pair<int,int>> getNeighbors(const pair<int,int> &node, 
                                       const vector<vector<char>>& grid) {
        
        int l = grid.size();
        int w = grid[0].size();
        vector<pair<int,int>> result;
        
        int dx [] = {1, -1, 0, 0};
        int dy [] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            pair<int,int> p = make_pair(node.first + dx[i], node.second + dy[i]);
            if (isValid(p, l, w) && grid[p.first][p.second] == '*')
                result.push_back(p);
        }

        return result;
    }
    
    bool isValid(const pair<int,int> &p, int l, int w) {
        return p.first >= 0 && p.first < l && p.second >= 0 && p.second < w;
    }
};