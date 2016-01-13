class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1;
        int n = grid[m].size() - 1;
        return min_path(grid, m, n);
    }

private:

    map<pair<int,int> , int> mymap;
    int MAX_INT = 0x7fffffff;
    
    int min_path(vector<vector<int>>& grid, int i, int j) {
        
        if (i >= grid.size() || j >= grid[i].size() || i < 0 || j < 0) {
            return MAX_INT;
        }
        
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        pair<int,int> p;
        p.first = i;
        p.second = j;
                
        vector<pair<int, int>> neighbors = get_neighbors(p);
        
        int min = MAX_INT;
        
        for (int i = 0; i < neighbors.size(); i++) {
            pair<int, int> n = neighbors[i];
            
            if (!contains(n)) {
                int temp = min_path(grid, n.first, n.second);
                mymap[n] = temp;
            }
            
            if (mymap[n] < min) {
                min = mymap[n];
            }
        }
        
        return grid[i][j] + min;
    }
    
    bool contains(pair<int,int> p) {
        try {
            mymap.at(p);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
    
    vector<pair<int, int>> get_neighbors(pair<int,int> p) {
        vector<pair<int, int>> list;
        
        for (int i = -1; i <= 0; i++) {
            for (int j = -1; j <= 0; j++) {
                
                if (i == 0 && j == 0)
                    continue;
                
                if (i == -1 && j == -1)
                    continue;
                
                pair<int, int> n;
                n.first = p.first + i;
                n.second = p.second + j;
                
                list.push_back(n);
            }
        }
        
        return list;
    }
};
