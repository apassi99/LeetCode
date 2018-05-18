/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> result;
        
        std::sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty() || result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            } else {
                result.back().end = max(intervals[i].end, result.back().end);
            }
        }
        
        return result;
    }
    
private:
    
    static bool comp(const Interval &p1, const Interval &p2) {
        return p1.start < p2.start;
    }
};