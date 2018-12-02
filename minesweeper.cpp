class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> result;

        
        for (int i = 0; i < board.size(); i++) {
            vector<char> temp;
            for (int j = 0; j < board[0].size(); j++) {
                temp.push_back(board[i][j]);
            }
            result.push_back(temp);
        }
        
        pair<int, int> loc = make_pair(click[0], click[1]);

        if (loc.first >= board.size() || loc.second >= board[0].size()) {
            return result;
        }

        if (board[loc.first][loc.second] == 'M') {
            result[loc.first][loc.second] = 'X';
        } else {
            updateBoard(result, loc);
        }

        return result;
    }

private:

    void updateBoard(vector<vector<char>> &G, pair<int,int> loc) {

        if (loc.first >= G.size() || loc.second >= G[0].size()) {
            return;
        }

        if (G[loc.first][loc.second] == 'M') {
            return;
        }
        
        if (G[loc.first][loc.second] != 'E') {
            return;
        }
        
        char neighborMines = 0;
        
        vector<pair<int,int>> neighbors = getNeighbors(loc, G.size(), G[0].size());
        
        for (int i = 0; i < neighbors.size(); i++) {
            pair<int,int> newLoc = neighbors[i];
            
            if (G[newLoc.first][newLoc.second] == 'M') {
                neighborMines++;
            }
        }

        
        if (neighborMines == 0) {
            G[loc.first][loc.second] = 'B';
            for (int i = 0; i < neighbors.size(); i++) {
                updateBoard(G, neighbors[i]);
            }
        } else {
            G[loc.first][loc.second] = '0' + neighborMines;
        }
        
    }
    
    vector<pair<int,int>> getNeighbors(pair<int,int> loc, int m, int n) {
        
        int cx = loc.first;
        int cy = loc.second;
        vector<pair<int,int>> neighbors;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                
                if (i != 0 || j != 0) {
                    if ( inRange(cx + i, cy + j, m, n) ) {
                        neighbors.push_back( make_pair(cx + i, cy + j) );
                    } 
                }
            }
        }
        return neighbors;
    }
    
    bool inRange(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};