class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if (matrix.size() <= 0) {
            return matrix.size();
        }
        
        int l = matrix.size();
        int w = matrix[0].size();

        
        vector<vector<int>> memo_table;
        
        for (int i = 0; i < l; i++) {
            vector<int> temp;
            for (int j = 0; j < w; j++) {
                temp.push_back(-1);
            }
            memo_table.push_back(temp);
        }
        
        int global_max = 0;
        
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                pair<int, int> p = make_pair(i, j);
                dfs(p, matrix, memo_table);
                global_max = max(global_max, memo_table[i][j]);
            }
        }
        
        return global_max;
    }
    
private:
    
    void dfs(const pair<int, int> &p, vector<vector<int>> &matrix, 
             vector<vector<int>> &memo_table) {
        
        if (memo_table[p.first][p.second] != -1) {
            return;
        }
        
        vector<pair<int,int>> neighbors;
        get_valid_neighbors(p, neighbors, matrix);
        
        int global_max = 0;
        
        for (int i = 0; i < neighbors.size(); i++) {
            dfs(neighbors[i], matrix, memo_table);
            global_max = max(memo_table[neighbors[i].first][neighbors[i].second], global_max);
        }

        memo_table[p.first][p.second] = global_max + 1;
    }
    
    void get_valid_neighbors(const pair<int, int> &p,
                             vector<pair<int,int>> &neighbors,
                             vector<vector<int>>& matrix) {
        
        
        int l = matrix.size();
        int w = matrix[0].size();
        
        
        int cur_value = matrix[p.first][p.second];
        
        pair<int, int> pairs [] = {make_pair(p.first+1, p.second), 
                                  make_pair(p.first-1, p.second),
                                  make_pair(p.first, p.second+1),
                                  make_pair(p.first, p.second-1)};
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> temp_pair = pairs[i];
            if (is_valid_point(temp_pair, l, w) &&
                matrix[temp_pair.first][temp_pair.second] > cur_value) {
                neighbors.push_back(temp_pair);
            }
        }
    }
    
    bool is_valid_point(const pair<int,int> &p, int l, int w) {
        return p.first >= 0 && p.first < l && p.second >= 0 && p.second < w;
    }
};