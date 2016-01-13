class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //find_path(triangle, 0, 0);
        
        for (int i = triangle.size()-1; i >= 0; i-- ) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int min_path = find_path(triangle, i, j);
                pair<int,int> p;
                p.first = i;
                p.second = j;
                mymap[p] = min_path;
            }
        }
        
        return find_path(triangle, 0, 0);
    }
    
private:

    map<pair<int,int>, int> mymap;
    
    int find_path(vector<vector<int>>& triangle, int i, int j) {
        
        if (i >= triangle.size() || j >= triangle[i].size()) {
            return 0;
        }
        
        pair<int,int> p;
        p.first = i;
        p.second = j;
                
        pair<int, int> left = get_left_child(p);
        pair<int, int> right = get_right_child(p);
        
        int minleft = 0;
        int minright = 0;
        
        if (!contains(left)) {
            minleft = find_path(triangle, left.first, left.second);
            mymap[left] = minleft;
        }
        
        if (!contains(right)) {
            minright = find_path(triangle, right.first, right.second);
            mymap[right] = minright;
        }
        
        minleft = mymap[left];
        minright = mymap[right];
        
        return triangle[i][j] + min(minleft, minright);
    }
    
    bool contains(pair<int,int> p) {
        try {
            mymap.at(p);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
    
    pair<int, int> get_left_child(pair<int, int> p) {
        pair<int, int> child;
        child.second = p.second;
        child.first = p.first + 1;
        return child;
    }
    
    pair<int, int> get_right_child(pair<int, int> p) {
        pair<int, int> child;
        child.second = p.second+1;
        child.first = p.first + 1;
        return child;
    }

};