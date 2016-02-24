class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths = 0;
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        map<pair<int,int>, int> mymap;
        
        uniquePathsHelper(mymap, p, m - 1, n - 1, &paths);
        return paths;
    }
    
private:

    void uniquePathsHelper(map<pair<int,int>, int> &mymap, pair<int, int> p , int m, int n, int * paths) {
        
        if (p.first > m || p.second > n) {
            return;
        }
        
        if (p.first == m || p.second == n) {
            *paths += 1;
            return;
        }
        
        if ( contains(mymap, p) ) {
            *paths = mymap[p];
            return;
        }
        
        vector<pair<int,int>> neighbors = getNeighbors(p, m, n);
        int totalPaths = *paths;
        
        for (int i = 0; i < neighbors.size(); i++) {
            int temp = 0;
            uniquePathsHelper(mymap, neighbors[i], m, n, &temp);
            totalPaths += temp;
        }
        
        *paths = totalPaths;
        mymap[p] = *paths;
    }

    vector<pair<int,int>> getNeighbors(pair<int, int> p, int m, int n) {
        int x = p.first;
        int y = p.second;
        
        vector<pair<int,int>> v;
        
        if (p.first == m && p.second == n) {
            return v;
        }
        
        pair<int, int> pleft;
        pleft.first = p.first;
        pleft.second = p.second + 1;
        
        pair<int, int> pdown;
        pdown.first = p.first + 1;
        pdown.second = p.second;
        
        v.push_back(pleft);
        v.push_back(pdown);
            
        return v;
    }
    
    bool contains(map<pair<int,int>, int> &m, pair<int,int> p) {
        try {
            m.at(p);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
};
