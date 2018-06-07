/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        int result = 0;
        
        if (points.size() <= 2) {
            return points.size();
        }
        
        unordered_map<pair<int,int>, int, pair_hash> freqMap;
        unordered_map<int, int> invalidSlopeFreqMap;
        
        for (int i = 0; i < points.size(); i++) {
            
            int duplicates = 0, curmax = 0;

            for (int j = i+1; j < points.size(); j++) {

                pair<int,int> p;
                if (getLineVars(points[i], points[j], p)) {
                    if (freqMap.find(p) != freqMap.end()) {
                        freqMap[p]++;
                    } else {
                        freqMap[p] = 1;
                    }
                    curmax = max(curmax, freqMap[p]);
                } else if (equals(points[i], points[j])) {
                    duplicates++;
                } else {
                    if (invalidSlopeFreqMap.find(points[i].x) != invalidSlopeFreqMap.end()) {
                        invalidSlopeFreqMap[points[i].x]++;
                    } else {
                        invalidSlopeFreqMap[points[i].x] = 1;
                    }
                    curmax = max(curmax, invalidSlopeFreqMap[points[i].x]);
                }
            }

            result = max(result, curmax + duplicates + 1);
            freqMap.clear();
            invalidSlopeFreqMap.clear();

        }
        
        return result;
        
    }
    
private:
    
    bool equals(const Point &p1, const Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    
    bool getLineVars(const Point &p1, const Point &p2, pair<int,int> &vars) {
        
        if (p1.x == p2.x)
            return false;
        
        vars.first =  p2.y - p1.y;
        vars.second = p2.x - p1.x;

        int gcd = __gcd(vars.first, vars.second);
        vars.first = vars.first / gcd;
        vars.second = vars.second / gcd;
        
        return true;
    }
    
    struct pair_hash {
    template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
};