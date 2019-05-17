class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> result;
        
        vector<PointData> pointDataList;
        
        for (int i = 0; i < points.size(); i++) {
            PointData p;
            p.x = points[i][0];
            p.y = points[i][1];
            p.dist = sqrt( (p.x * p.x) + (p.y * p.y));
            pointDataList.push_back(p);
        }
        
        std::sort(pointDataList.begin(), pointDataList.end(), comp);
        
        K = min(K, (int) points.size());
        
        for (int i = 0; i < K; i++) {
            vector<int> temp;
            temp.push_back(pointDataList[i].x);
            temp.push_back(pointDataList[i].y);
            
            result.push_back(temp);
        }
        
        return result;
    }
    
private:
    
    typedef struct {
        int x;
        int y;
        double dist;
    } PointData;
    
    static bool comp(const PointData &p1, const PointData &p2) {
        return p1.dist < p2.dist;
    }
};